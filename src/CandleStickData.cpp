#include "CandleStickData.hpp"

CandleStickData::CandleStickData(QObject *parent)
    : QObject(parent), _timestamp(0), _open(0), _close(0), _high(0), _low(0), _volume(0) {}

void CandleStickData::setTimestamp(double date) {
    if (!qFuzzyCompare(_timestamp, date)) {
        _timestamp = date;
        emit timestampChanged();
    }
}

void CandleStickData::setOpen(double open) {
    if (!qFuzzyCompare(_open, open)) {
        _open = open;
        emit openChanged();
    }
}

void CandleStickData::setClose(double close) {
    if (!qFuzzyCompare(_close, close)) {
        _close = close;
        emit closeChanged();
    }
}

void CandleStickData::setHigh(double high) {
    if (!qFuzzyCompare(_high, high)) {
        _high = high;
        emit highChanged();
    }
}

void CandleStickData::setLow(double low) {
    if (!qFuzzyCompare(_low, low)) {
        _low = low;
        emit lowChanged();
    }
}

void CandleStickData::setVolume(double volume) {
    if (!qFuzzyCompare(_volume, volume)) {
        _volume = volume;
        emit volumeChanged();
    }
}
