#pragma once

#include <QObject>
#include <QtQuick>

class StarredSearch : public QObject {
    Q_OBJECT
    QML_ELEMENT

  public:
    StarredSearch(QObject *parent = nullptr);

  private slots:

  signals:

  private:
};
