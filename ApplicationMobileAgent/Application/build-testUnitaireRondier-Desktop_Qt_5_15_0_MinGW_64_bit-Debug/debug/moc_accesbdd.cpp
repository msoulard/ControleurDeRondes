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
    QByteArrayData data[15];
    char stringdata0[314];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AccesBdd_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AccesBdd_t qt_meta_stringdata_AccesBdd = {
    {
QT_MOC_LITERAL(0, 0, 8), // "AccesBdd"
QT_MOC_LITERAL(1, 9, 24), // "obtenirListePointeauxQML"
QT_MOC_LITERAL(2, 34, 15), // "QList<QObject*>"
QT_MOC_LITERAL(3, 50, 0), // ""
QT_MOC_LITERAL(4, 51, 33), // "obtenirListeDesignationsPoint..."
QT_MOC_LITERAL(5, 85, 14), // "QList<QString>"
QT_MOC_LITERAL(6, 100, 22), // "obtenirListeNomsRondes"
QT_MOC_LITERAL(7, 123, 9), // "_numBadge"
QT_MOC_LITERAL(8, 133, 32), // "obtenirListeEmplacementPointeaux"
QT_MOC_LITERAL(9, 166, 30), // "obtenirListeTempsMiniPointeaux"
QT_MOC_LITERAL(10, 197, 30), // "obtenirListeTempsMaxiPointeaux"
QT_MOC_LITERAL(11, 228, 29), // "obtenirListeBatimentPointeaux"
QT_MOC_LITERAL(12, 258, 26), // "obtenirListeEtagePointeaux"
QT_MOC_LITERAL(13, 285, 14), // "getListeRondes"
QT_MOC_LITERAL(14, 300, 13) // "QList<Ronde*>"

    },
    "AccesBdd\0obtenirListePointeauxQML\0"
    "QList<QObject*>\0\0obtenirListeDesignationsPointeaux\0"
    "QList<QString>\0obtenirListeNomsRondes\0"
    "_numBadge\0obtenirListeEmplacementPointeaux\0"
    "obtenirListeTempsMiniPointeaux\0"
    "obtenirListeTempsMaxiPointeaux\0"
    "obtenirListeBatimentPointeaux\0"
    "obtenirListeEtagePointeaux\0getListeRondes\0"
    "QList<Ronde*>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AccesBdd[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   59,    3, 0x02 /* Public */,
       4,    0,   60,    3, 0x02 /* Public */,
       6,    1,   61,    3, 0x02 /* Public */,
       8,    0,   64,    3, 0x02 /* Public */,
       9,    0,   65,    3, 0x02 /* Public */,
      10,    0,   66,    3, 0x02 /* Public */,
      11,    0,   67,    3, 0x02 /* Public */,
      12,    0,   68,    3, 0x02 /* Public */,
      13,    0,   69,    3, 0x02 /* Public */,

 // methods: parameters
    0x80000000 | 2,
    0x80000000 | 5,
    0x80000000 | 5, QMetaType::QString,    7,
    0x80000000 | 5,
    0x80000000 | 5,
    0x80000000 | 5,
    0x80000000 | 5,
    0x80000000 | 5,
    0x80000000 | 14,

       0        // eod
};

void AccesBdd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AccesBdd *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QList<QObject*> _r = _t->obtenirListePointeauxQML();
            if (_a[0]) *reinterpret_cast< QList<QObject*>*>(_a[0]) = std::move(_r); }  break;
        case 1: { QList<QString> _r = _t->obtenirListeDesignationsPointeaux();
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 2: { QList<QString> _r = _t->obtenirListeNomsRondes((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 3: { QList<QString> _r = _t->obtenirListeEmplacementPointeaux();
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 4: { QList<QString> _r = _t->obtenirListeTempsMiniPointeaux();
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 5: { QList<QString> _r = _t->obtenirListeTempsMaxiPointeaux();
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 6: { QList<QString> _r = _t->obtenirListeBatimentPointeaux();
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 7: { QList<QString> _r = _t->obtenirListeEtagePointeaux();
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 8: { QList<Ronde*> _r = _t->getListeRondes();
            if (_a[0]) *reinterpret_cast< QList<Ronde*>*>(_a[0]) = std::move(_r); }  break;
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
