/****************************************************************************
** Meta object code from reading C++ file 'pointeau.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../testUnitaireRondier/pointeau.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pointeau.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Pointeau_t {
    QByteArrayData data[8];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Pointeau_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Pointeau_t qt_meta_stringdata_Pointeau = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Pointeau"
QT_MOC_LITERAL(1, 9, 18), // "designationChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 14), // "couleurChanged"
QT_MOC_LITERAL(4, 44, 9), // "horodater"
QT_MOC_LITERAL(5, 54, 14), // "getDesignation"
QT_MOC_LITERAL(6, 69, 13), // "m_designation"
QT_MOC_LITERAL(7, 83, 9) // "m_couleur"

    },
    "Pointeau\0designationChanged\0\0"
    "couleurChanged\0horodater\0getDesignation\0"
    "m_designation\0m_couleur"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Pointeau[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       2,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x02 /* Public */,
       5,    0,   37,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::QString,

 // properties: name, type, flags
       6, QMetaType::QString, 0x00495003,
       7, QMetaType::QString, 0x00495003,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void Pointeau::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Pointeau *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->designationChanged(); break;
        case 1: _t->couleurChanged(); break;
        case 2: _t->horodater(); break;
        case 3: { QString _r = _t->getDesignation();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Pointeau::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Pointeau::designationChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Pointeau::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Pointeau::couleurChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Pointeau *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getDesignation(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getCouleur(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Pointeau *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDesignation(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setCouleur(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Pointeau::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Pointeau.data,
    qt_meta_data_Pointeau,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Pointeau::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Pointeau::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Pointeau.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Pointeau::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Pointeau::designationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Pointeau::couleurChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
