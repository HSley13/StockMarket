/****************************************************************************
** Meta object code from reading C++ file 'StockDataProvider.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/StockDataProvider.hpp"
#include <QtNetwork/QSslError>
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StockDataProvider.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSStockDataENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSStockDataENDCLASS = QtMocHelpers::stringData(
    "StockData",
    "QML.Element",
    "auto",
    "timestampChanged",
    "",
    "openChanged",
    "closeChanged",
    "highChanged",
    "lowChanged",
    "volumeChanged",
    "setTimestamp",
    "timestamp",
    "setOpen",
    "open",
    "setClose",
    "close",
    "setHigh",
    "high",
    "setLow",
    "low",
    "setVolume",
    "volume"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSStockDataENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
      12,   16, // methods
       6,  112, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   88,    4, 0x06,    7 /* Public */,
       5,    0,   89,    4, 0x06,    8 /* Public */,
       6,    0,   90,    4, 0x06,    9 /* Public */,
       7,    0,   91,    4, 0x06,   10 /* Public */,
       8,    0,   92,    4, 0x06,   11 /* Public */,
       9,    0,   93,    4, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    1,   94,    4, 0x0a,   13 /* Public */,
      12,    1,   97,    4, 0x0a,   15 /* Public */,
      14,    1,  100,    4, 0x0a,   17 /* Public */,
      16,    1,  103,    4, 0x0a,   19 /* Public */,
      18,    1,  106,    4, 0x0a,   21 /* Public */,
      20,    1,  109,    4, 0x0a,   23 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   13,
    QMetaType::Void, QMetaType::Double,   15,
    QMetaType::Void, QMetaType::Double,   17,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   21,

 // properties: name, type, flags
      11, QMetaType::Double, 0x00015103, uint(0), 0,
      13, QMetaType::Double, 0x00015103, uint(1), 0,
      15, QMetaType::Double, 0x00015103, uint(2), 0,
      17, QMetaType::Double, 0x00015103, uint(3), 0,
      19, QMetaType::Double, 0x00015103, uint(4), 0,
      21, QMetaType::Double, 0x00015103, uint(5), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject StockData::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSStockDataENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSStockDataENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'timestamp'
        double,
        // property 'open'
        double,
        // property 'close'
        double,
        // property 'high'
        double,
        // property 'low'
        double,
        // property 'volume'
        double,
        // Q_OBJECT / Q_GADGET
        StockData,
        // method 'timestampChanged'
        void,
        // method 'openChanged'
        void,
        // method 'closeChanged'
        void,
        // method 'highChanged'
        void,
        // method 'lowChanged'
        void,
        // method 'volumeChanged'
        void,
        // method 'setTimestamp'
        void,
        double,
        // method 'setOpen'
        void,
        double,
        // method 'setClose'
        void,
        double,
        // method 'setHigh'
        void,
        double,
        // method 'setLow'
        void,
        double,
        // method 'setVolume'
        void,
        double
    >,
    nullptr
} };

void StockData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StockData *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->timestampChanged(); break;
        case 1: _t->openChanged(); break;
        case 2: _t->closeChanged(); break;
        case 3: _t->highChanged(); break;
        case 4: _t->lowChanged(); break;
        case 5: _t->volumeChanged(); break;
        case 6: _t->setTimestamp((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 7: _t->setOpen((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 8: _t->setClose((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 9: _t->setHigh((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 10: _t->setLow((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 11: _t->setVolume((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (StockData::*)();
            if (_t _q_method = &StockData::timestampChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (StockData::*)();
            if (_t _q_method = &StockData::openChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (StockData::*)();
            if (_t _q_method = &StockData::closeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (StockData::*)();
            if (_t _q_method = &StockData::highChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (StockData::*)();
            if (_t _q_method = &StockData::lowChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (StockData::*)();
            if (_t _q_method = &StockData::volumeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<StockData *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = _t->timestamp(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->open(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->close(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->high(); break;
        case 4: *reinterpret_cast< double*>(_v) = _t->low(); break;
        case 5: *reinterpret_cast< double*>(_v) = _t->volume(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<StockData *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTimestamp(*reinterpret_cast< double*>(_v)); break;
        case 1: _t->setOpen(*reinterpret_cast< double*>(_v)); break;
        case 2: _t->setClose(*reinterpret_cast< double*>(_v)); break;
        case 3: _t->setHigh(*reinterpret_cast< double*>(_v)); break;
        case 4: _t->setLow(*reinterpret_cast< double*>(_v)); break;
        case 5: _t->setVolume(*reinterpret_cast< double*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *StockData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StockData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSStockDataENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int StockData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void StockData::timestampChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void StockData::openChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void StockData::closeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void StockData::highChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void StockData::lowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void StockData::volumeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSStockDataProviderENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSStockDataProviderENDCLASS = QtMocHelpers::stringData(
    "StockDataProvider",
    "QML.Element",
    "auto",
    "stockDataChanged",
    "",
    "stockData",
    "QList<StockData*>"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSStockDataProviderENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
       1,   16, // methods
       1,   23, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   22,    4, 0x06,    2 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // properties: name, type, flags
       5, 0x80000000 | 6, 0x00015009, uint(0), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject StockDataProvider::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSStockDataProviderENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSStockDataProviderENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'stockData'
        QList<StockData*>,
        // Q_OBJECT / Q_GADGET
        StockDataProvider,
        // method 'stockDataChanged'
        void
    >,
    nullptr
} };

void StockDataProvider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StockDataProvider *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->stockDataChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (StockDataProvider::*)();
            if (_t _q_method = &StockDataProvider::stockDataChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<StockData*> >(); break;
        }
    }  else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<StockDataProvider *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<StockData*>*>(_v) = _t->stockData(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *StockDataProvider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StockDataProvider::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSStockDataProviderENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int StockDataProvider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void StockDataProvider::stockDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
