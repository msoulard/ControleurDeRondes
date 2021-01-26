/****************************************************************************
** Meta object code from reading C++ file 'ihmassociation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../SupervisionRondier/ihmassociation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ihmassociation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IHMAssociation_t {
    QByteArrayData data[10];
    char stringdata0[251];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IHMAssociation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IHMAssociation_t qt_meta_stringdata_IHMAssociation = {
    {
QT_MOC_LITERAL(0, 0, 14), // "IHMAssociation"
QT_MOC_LITERAL(1, 15, 36), // "on_comboBoxAgent_currentIndex..."
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 5), // "index"
QT_MOC_LITERAL(4, 59, 34), // "on_pushButtonAffecterRonde_cl..."
QT_MOC_LITERAL(5, 94, 37), // "on_pushButtonDesaffecterRonde..."
QT_MOC_LITERAL(6, 132, 32), // "on_pushButtonEnregistrer_clicked"
QT_MOC_LITERAL(7, 165, 34), // "on_listWidget_rondes_doubleCl..."
QT_MOC_LITERAL(8, 200, 11), // "QModelIndex"
QT_MOC_LITERAL(9, 212, 38) // "on_listWidget_rondeAgent_doub..."

    },
    "IHMAssociation\0on_comboBoxAgent_currentIndexChanged\0"
    "\0index\0on_pushButtonAffecterRonde_clicked\0"
    "on_pushButtonDesaffecterRonde_clicked\0"
    "on_pushButtonEnregistrer_clicked\0"
    "on_listWidget_rondes_doubleClicked\0"
    "QModelIndex\0on_listWidget_rondeAgent_doubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IHMAssociation[] = {

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

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    0,   47,    2, 0x08 /* Private */,
       5,    0,   48,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,
       7,    1,   50,    2, 0x08 /* Private */,
       9,    1,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    3,
    QMetaType::Void, 0x80000000 | 8,    3,

       0        // eod
};

void IHMAssociation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IHMAssociation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_comboBoxAgent_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pushButtonAffecterRonde_clicked(); break;
        case 2: _t->on_pushButtonDesaffecterRonde_clicked(); break;
        case 3: _t->on_pushButtonEnregistrer_clicked(); break;
        case 4: _t->on_listWidget_rondes_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_listWidget_rondeAgent_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject IHMAssociation::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_IHMAssociation.data,
    qt_meta_data_IHMAssociation,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IHMAssociation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IHMAssociation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IHMAssociation.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int IHMAssociation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
