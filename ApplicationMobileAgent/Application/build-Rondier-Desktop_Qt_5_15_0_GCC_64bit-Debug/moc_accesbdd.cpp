/****************************************************************************
** Meta object code from reading C++ file 'accesbdd.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Rondier/accesbdd.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'accesbdd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AccesBDD_t {
    QByteArrayData data[13];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AccesBDD_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AccesBDD_t qt_meta_stringdata_AccesBDD = {
    {
QT_MOC_LITERAL(0, 0, 8), // "AccesBDD"
QT_MOC_LITERAL(1, 9, 16), // "ObtenirPointeaux"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "_id_ronde"
QT_MOC_LITERAL(4, 37, 13), // "ObtenirRondes"
QT_MOC_LITERAL(5, 51, 9), // "_id_agent"
QT_MOC_LITERAL(6, 61, 19), // "RecupererLePointeau"
QT_MOC_LITERAL(7, 81, 11), // "_tag_mifare"
QT_MOC_LITERAL(8, 93, 17), // "VerificationBadge"
QT_MOC_LITERAL(9, 111, 9), // "_numBadge"
QT_MOC_LITERAL(10, 121, 14), // "MettreAJourBdd"
QT_MOC_LITERAL(11, 136, 19), // "EnregistrerAnomalie"
QT_MOC_LITERAL(12, 156, 12) // "_id_pointeau"

    },
    "AccesBDD\0ObtenirPointeaux\0\0_id_ronde\0"
    "ObtenirRondes\0_id_agent\0RecupererLePointeau\0"
    "_tag_mifare\0VerificationBadge\0_numBadge\0"
    "MettreAJourBdd\0EnregistrerAnomalie\0"
    "_id_pointeau"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AccesBDD[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x02 /* Public */,
       4,    1,   47,    2, 0x02 /* Public */,
       6,    1,   50,    2, 0x02 /* Public */,
       8,    1,   53,    2, 0x02 /* Public */,
      10,    0,   56,    2, 0x02 /* Public */,
      11,    1,   57,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void AccesBDD::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AccesBDD *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ObtenirPointeaux((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->ObtenirRondes((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->RecupererLePointeau((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->VerificationBadge((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->MettreAJourBdd(); break;
        case 5: _t->EnregistrerAnomalie((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AccesBDD::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AccesBDD.data,
    qt_meta_data_AccesBDD,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AccesBDD::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AccesBDD::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AccesBDD.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AccesBDD::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
