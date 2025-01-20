/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#include <StarredSearch.hpp>
#include <StockDataProvider.hpp>


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_StockMarket()
{
    qmlRegisterTypesAndRevisions<StarredSearch>("StockMarket", 1);
    qmlRegisterTypesAndRevisions<StockData>("StockMarket", 1);
    qmlRegisterTypesAndRevisions<StockDataProvider>("StockMarket", 1);
    qmlRegisterModule("StockMarket", 1, 0);
}

static const QQmlModuleRegistration stockMarketRegistration("StockMarket", qml_register_types_StockMarket);
