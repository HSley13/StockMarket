#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>
#include <QtCore/qhash.h>
#include <QtCore/qstring.h>

namespace QmlCacheGeneratedCode {
namespace _0x5f_QML_stockMarket_customedModules_Main_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _0x5f_QML_stockMarket_customedModules_HomeWindow_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _0x5f_QML_stockMarket_customedModules_BackGround_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _0x5f_QML_stockMarket_customedModules_InputField_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _0x5f_QML_stockMarket_customedModules_ButtonImage_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _0x5f_QML_stockMarket_customedModules_RoundedButton_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _0x5f_QML_stockMarket_customedModules_MenuPanel_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    ~Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
    resourcePathToCachedUnit.insert(QStringLiteral("/QML/stockMarket/customedModules/Main.qml"), &QmlCacheGeneratedCode::_0x5f_QML_stockMarket_customedModules_Main_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/QML/stockMarket/customedModules/HomeWindow.qml"), &QmlCacheGeneratedCode::_0x5f_QML_stockMarket_customedModules_HomeWindow_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/QML/stockMarket/customedModules/BackGround.qml"), &QmlCacheGeneratedCode::_0x5f_QML_stockMarket_customedModules_BackGround_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/QML/stockMarket/customedModules/InputField.qml"), &QmlCacheGeneratedCode::_0x5f_QML_stockMarket_customedModules_InputField_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/QML/stockMarket/customedModules/ButtonImage.qml"), &QmlCacheGeneratedCode::_0x5f_QML_stockMarket_customedModules_ButtonImage_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/QML/stockMarket/customedModules/RoundedButton.qml"), &QmlCacheGeneratedCode::_0x5f_QML_stockMarket_customedModules_RoundedButton_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/QML/stockMarket/customedModules/MenuPanel.qml"), &QmlCacheGeneratedCode::_0x5f_QML_stockMarket_customedModules_MenuPanel_qml::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.structVersion = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
}

Registry::~Registry() {
    QQmlPrivate::qmlunregister(QQmlPrivate::QmlUnitCacheHookRegistration, quintptr(&lookupCachedUnit));
}

const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qmlcache_app)() {
    ::unitRegistry();
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qmlcache_app))
int QT_MANGLE_NAMESPACE(qCleanupResources_qmlcache_app)() {
    return 1;
}
