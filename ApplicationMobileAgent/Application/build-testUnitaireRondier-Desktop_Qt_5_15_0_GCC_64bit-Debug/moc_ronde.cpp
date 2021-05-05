/****************************************************************************
** Meta object code from reading C++ file 'ronde.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../testUnitaireRondier/ronde.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ronde.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Ronde_t {
    QByteArrayData data[9];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ronde_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ronde_t qt_meta_stringdata_Ronde = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Ronde"
QT_MOC_LITERAL(1, 6, 18), // "obtenirListeRondes"
QT_MOC_LITERAL(2, 25, 14), // "QList<QString>"
QT_MOC_LITERAL(3, 40, 0), // ""
QT_MOC_LITERAL(4, 41, 9), // "_numBadge"
QT_MOC_LITERAL(5, 51, 23), // "mettreAJourIndexCourant"
QT_MOC_LITERAL(6, 75, 11), // "_indexRonde"
QT_MOC_LITERAL(7, 87, 23), // "obtenirNomRondeCourante"
QT_MOC_LITERAL(8, 111, 22) // "obtenirIdRondeCourante"

    },
    "Ronde\0obtenirListeRondes\0QList<QString>\0"
    "\0_numBadge\0mettreAJourIndexCourant\0"
    "_indexRonde\0obtenirNomRondeCourante\0"
    "obtenirIdRondeCourante"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ronde[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   34,    3, 0x02 /* Public */,
       5,    1,   37,    3, 0x02 /* Public */,
       7,    0,   40,    3, 0x02 /* Public */,
       8,    0,   41,    3, 0x02 /* Public */,

 // methods: parameters
    0x80000000 | 2, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::QString,
    QMetaType::Int,

       0        // eod
};

void Ronde::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Ronde *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QList<QString> _r = _t->obtenirListeRondes((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->mettreAJourIndexCourant((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: { QString _r = _t->obtenirNomRondeCourante();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->obtenirIdRondeCourante();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Ronde::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Ronde.data,
    qt_meta_data_Ronde,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Ronde::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ronde::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Ronde.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Ronde::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
