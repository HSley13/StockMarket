#pragma once

#include <QtQuick>

class HelloWorld : public QObject {
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString helloWorld READ helloWorld CONSTANT)

  public:
    HelloWorld(QObject *parent = nullptr);

    const QString &helloWorld();

  private:
    QString _helloWorld{"Hello World from cpp!"};
};
