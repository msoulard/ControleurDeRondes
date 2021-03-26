/****************************************************************************
** Meta object code from reading C++ file 'accesbdd.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../testUnitaireRondier/accesbdd.h"
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
struct qt_meta_stringdata_AccesBdd_t {
    QByteArrayData data[14];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AccesBdd_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AccesBdd_t qt_meta_stringdata_AccesBdd = {
    {
QT_MOC_LITERAL(0, 0, 8), // "AccesBdd"
QT_MOC_LITERAL(1, 9, 12), // "ObtenirAgent"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 9), // "_numBadge"
QT_MOC_LITERAL(4, 33, 16), // "ObtenirPointeaux"
QT_MOC_LITERAL(5, 50, 9), // "_id_ronde"
QT_MOC_LITERAL(6, 60, 13), // "ObtenirRondes"
QT_MOC_LITERAL(7, 74, 9), // "_id_agent"
QT_MOC_LITERAL(8, 84, 19), // "RecupererLePointeau"
QT_MOC_LITERAL(9, 104, 11), // "_tag_mifare"
QT_MOC_LITERAL(10, 116, 17), // "VerificationBadge"
QT_MOC_LITERAL(11, 134, 14), // "MettreAJourBdd"
QT_MOC_LITERAL(12, 149, 19), // "EnregistrerAnomalie"
QT_MOC_LITERAL(13, 169, 12) // "_id_pointeau"

    },
    "AccesBdd\0ObtenirAgent\0\0_numBadge\0"
    "ObtenirPointeaux\0_id_ronde\0ObtenirRondes\0"
    "_id_agent\0RecupererLePointeau\0_tag_mifare\0"
    "VerificationBadge\0MettreAJourBdd\0"
    "EnregistrerAnomalie\0_id_pointeau"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AccesBdd[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x02 /* Public */,
       4,    1,   52,    2, 0x02 /* Public */,
       6,    1,   55,    2, 0x02 /* Public */,
       8,    1,   58,    2, 0x02 /* Public */,
      10,    1,   61,    2, 0x02 /* Public */,
      11,    0,   64,    2, 0x02 /* Public */,
      12,    1,   65,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::QString, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void AccesBdd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AccesBdd *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->ObtenirAgent((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->ObtenirPointeaux((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->ObtenirRondes((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->RecupererLePointeau((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->VerificationBadge((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->MettreAJourBdd(); break;
        case 6: _t->EnregistrerAnomalie((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AccesBdd::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AccesBdd.data,
    qt_meta_data_AccesBdd,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AccesBdd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AccesBdd::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AccesBdd.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AccesBdd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
