#pragma once

#include <QObject>
#include <QtQuick>

class CandleStickData : public QObject {
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(double timestamp READ timestamp WRITE setTimestamp NOTIFY timestampChanged)
    Q_PROPERTY(double open READ open WRITE setOpen NOTIFY openChanged)
    Q_PROPERTY(double close READ close WRITE setClose NOTIFY closeChanged)
    Q_PROPERTY(double high READ high WRITE setHigh NOTIFY highChanged)
    Q_PROPERTY(double low READ low WRITE setLow NOTIFY lowChanged)
    Q_PROPERTY(double volume READ volume WRITE setVolume NOTIFY volumeChanged)

  public:
    CandleStickData(QObject *parent = nullptr);

    double timestamp() const { return _timestamp; }
    double open() const { return _open; }
    double close() const { return _close; }
    double high() const { return _high; }
    double low() const { return _low; }
    double volume() const { return _volume; }

  public slots:
    void setTimestamp(double timestamp);
    void setOpen(double open);
    void setClose(double close);
    void setHigh(double high);
    void setLow(double low);
    void setVolume(double volume);

  signals:
    void timestampChanged();
    void openChanged();
    void closeChanged();
    void highChanged();
    void lowChanged();
    void volumeChanged();

  private:
    double _timestamp;
    double _open;
    double _close;
    double _high;
    double _low;
    double _volume;
};
