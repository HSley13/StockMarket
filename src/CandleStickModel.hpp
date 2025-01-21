#pragma once

#include <CandleStickData.hpp>
#include <QObject>
#include <QtCore>

class CandleStickModel : public QAbstractTableModel {
    Q_OBJECT
    QML_ELEMENT

  public:
    CandleStickModel(QObject *parent = nullptr);
    enum CandleStickRoles {
        TimestampRole = Qt::UserRole + 1,
        OpenRole,
        CloseRole,
        HighRole,
        LowRole,
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void addCandleStickData(CandleStickData *candleStickData);
    QList<CandleStickData *> CandleStickData() const;

    void fetchDataFromApi(const QString &symbol);

  private:
    QList<class ::CandleStickData *> _candleStickData;
};
