#include "StockDataProvider.hpp"

StockData::StockData(QObject *parent)
    : QObject(parent), _timestamp(0), _open(0), _close(0), _high(0), _low(0), _volume(0) {}

void StockData::setTimestamp(double date) {
    if (!qFuzzyCompare(_timestamp, date)) {
        _timestamp = date;
        emit timestampChanged();
    }
}

void StockData::setOpen(double open) {
    if (!qFuzzyCompare(_open, open)) {
        _open = open;
        emit openChanged();
    }
}

void StockData::setClose(double close) {
    if (!qFuzzyCompare(_close, close)) {
        _close = close;
        emit closeChanged();
    }
}

void StockData::setHigh(double high) {
    if (!qFuzzyCompare(_high, high)) {
        _high = high;
        emit highChanged();
    }
}

void StockData::setLow(double low) {
    if (!qFuzzyCompare(_low, low)) {
        _low = low;
        emit lowChanged();
    }
}

void StockData::setVolume(double volume) {
    if (!qFuzzyCompare(_volume, volume)) {
        _volume = volume;
        emit volumeChanged();
    }
}

StockDataProvider::StockDataProvider(QObject *parent) : QObject(parent) {
    fetchDataFromApi("AAPL");
}

void StockDataProvider::fetchDataFromApi(const QString &symbol) {
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

        QByteArray data = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        QJsonObject root = doc.object();

        QJsonObject metaData = root["Meta Data"].toObject();
        QJsonObject timeSeries = root["Time Series (Daily)"].toObject();

        _stockData.clear();

        for (const QString &date : timeSeries.keys()) {
            QJsonObject dayData{timeSeries[date].toObject()};

            StockData *stock{new StockData(this)};

            QDateTime dateTime = QDateTime::fromString(date, "yyyy-MM-dd");
            if (!dateTime.isValid()) {
                qDebug() << "Invalid date format:" << date;
                continue;
            }
            double dateTimestamp = static_cast<double>(dateTime.toSecsSinceEpoch());

            stock->setTimestamp(dateTimestamp);
            stock->setOpen(dayData["1. open"].toString().toDouble());
            stock->setHigh(dayData["2. high"].toString().toDouble());
            stock->setLow(dayData["3. low"].toString().toDouble());
            stock->setClose(dayData["4. close"].toString().toDouble());
            stock->setVolume(dayData["5. volume"].toString().toDouble());

            _stockData.append(stock);
        }

        emit stockDataChanged();
        reply->deleteLater();
    });

    manager->get(request);
}
