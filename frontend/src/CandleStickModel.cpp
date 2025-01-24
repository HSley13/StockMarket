#include "CandleStickModel.hpp"

CandleStickModel::CandleStickModel(QObject *parent) : QAbstractTableModel(parent) { fetchDataFromApi("AAPL"); }

int CandleStickModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return _candleStickData.size();
}

int CandleStickModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 5;
}

QVariant CandleStickModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= _candleStickData.size()) {
        return QVariant();
    }

    const class ::CandleStickData *candle{_candleStickData.at(index.row())};

    // switch (index.column()) {
    // case 0:
    //     return candle->timestamp();
    // case 1:
    //     return candle->open();
    // case 2:
    //     return candle->high();
    // case 3:
    //     return candle->low();
    // case 4:
    //     return candle->close();
    // default:
    //     return QVariant();
    // }

    switch (CandleStickRoles(role)) {
    case TimestampRole:
        return candle->timestamp();
    case OpenRole:
        return candle->open();
    case CloseRole:
        return candle->close();
    case HighRole:
        return candle->high();
    case LowRole:
        return candle->low();
    default:
        return QVariant();
    }

    return QVariant();
}

QHash<int, QByteArray> CandleStickModel::roleNames() const {
    QHash<int, QByteArray> roles;

    roles[TimestampRole] = "timestamp";
    roles[OpenRole] = "open";
    roles[CloseRole] = "close";
    roles[HighRole] = "high";
    roles[LowRole] = "low";

    return roles;
}

QList<CandleStickData *> CandleStickModel::CandleStickData() const { return _candleStickData; }

void CandleStickModel::addCandleStickData(class ::CandleStickData *candleStickData) {
    beginInsertRows(QModelIndex(), _candleStickData.size(), _candleStickData.size());
    _candleStickData.append(candleStickData);
    endInsertRows();
}

void CandleStickModel::fetchDataFromApi(const QString &symbol) {
    QString url{QString("http://localhost:8080/stockdata?symbol=%1").arg(symbol)};

    QNetworkAccessManager *manager{new QNetworkAccessManager(this)};
    QUrl requestUrl(url);
    QNetworkRequest request(requestUrl);

    connect(manager, &QNetworkAccessManager::finished, this, [this](QNetworkReply *reply) {
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "Error fetching data:" << reply->errorString();
            reply->deleteLater();
            return;
        }

        QByteArray data{reply->readAll()};
        QJsonDocument doc{QJsonDocument::fromJson(data)};
        QJsonObject root{doc.object()};

        QJsonObject metaData{root["Meta Data"].toObject()};
        QJsonObject timeSeries{root["Time Series (Daily)"].toObject()};

        beginResetModel();
        for (const QString &date : timeSeries.keys()) {
            QJsonObject dayData{timeSeries[date].toObject()};

            class ::CandleStickData *candle{new class ::CandleStickData(this)};

            QDateTime dateTime{QDateTime::fromString(date, "yyyy-MM-dd")};
            if (!dateTime.isValid()) {
                qDebug() << "Invalid date format:" << date;
                continue;
            }
            double dateTimestamp{static_cast<double>(dateTime.toSecsSinceEpoch())};

            candle->setTimestamp(dateTimestamp);
            candle->setOpen(dayData["1. open"].toString().toDouble());
            candle->setHigh(dayData["2. high"].toString().toDouble());
            candle->setLow(dayData["3. low"].toString().toDouble());
            candle->setClose(dayData["4. close"].toString().toDouble());
            candle->setVolume(dayData["5. volume"].toString().toDouble());

            addCandleStickData(candle);
        }
        endResetModel();

        reply->deleteLater();
    });

    manager->get(request);
}
