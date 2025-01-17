#include "HelloWorld.hpp"

HelloWorld::HelloWorld(QObject *parent)
    : QObject(parent) {}

const QString &HelloWorld::helloWorld() {
    return _helloWorld;
}
