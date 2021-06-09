/****************************************************************************
** Meta object code from reading C++ file 'chronologieanomalie.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Supervision_Rondier_finale3/chronologieanomalie.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chronologieanomalie.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChronologieAnomalie_t {
    QByteArrayData data[13];
    char stringdata0[250];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChronologieAnomalie_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChronologieAnomalie_t qt_meta_stringdata_ChronologieAnomalie = {
    {
QT_MOC_LITERAL(0, 0, 19), // "ChronologieAnomalie"
QT_MOC_LITERAL(1, 20, 37), // "on_tableWidgetChronologie_cel..."
QT_MOC_LITERAL(2, 58, 0), // ""
QT_MOC_LITERAL(3, 59, 3), // "row"
QT_MOC_LITERAL(4, 63, 6), // "column"
QT_MOC_LITERAL(5, 70, 24), // "on_pushButtonpdf_clicked"
QT_MOC_LITERAL(6, 95, 28), // "on_PushButtonAnnuler_clicked"
QT_MOC_LITERAL(7, 124, 37), // "on_tableWidgetChronologie_ite..."
QT_MOC_LITERAL(8, 162, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(9, 180, 4), // "item"
QT_MOC_LITERAL(10, 185, 20), // "on_checkBox1_clicked"
QT_MOC_LITERAL(11, 206, 21), // "on_checkBox_2_clicked"
QT_MOC_LITERAL(12, 228, 21) // "on_checkBox_3_clicked"

    },
    "ChronologieAnomalie\0"
    "on_tableWidgetChronologie_cellClicked\0"
    "\0row\0column\0on_pushButtonpdf_clicked\0"
    "on_PushButtonAnnuler_clicked\0"
    "on_tableWidgetChronologie_itemClicked\0"
    "QTableWidgetItem*\0item\0on_checkBox1_clicked\0"
    "on_checkBox_2_clicked\0on_checkBox_3_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChronologieAnomalie[] = {

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

 // slots: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x08 /* Private */,
       5,    0,   54,    2, 0x08 /* Private */,
       6,    0,   55,    2, 0x08 /* Private */,
       7,    1,   56,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,
      11,    0,   60,    2, 0x08 /* Private */,
      12,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ChronologieAnomalie::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChronologieAnomalie *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_tableWidgetChronologie_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->on_pushButtonpdf_clicked(); break;
        case 2: _t->on_PushButtonAnnuler_clicked(); break;
        case 3: _t->on_tableWidgetChronologie_itemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->on_checkBox1_clicked(); break;
        case 5: _t->on_checkBox_2_clicked(); break;
        case 6: _t->on_checkBox_3_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChronologieAnomalie::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ChronologieAnomalie.data,
    qt_meta_data_ChronologieAnomalie,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChronologieAnomalie::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChronologieAnomalie::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChronologieAnomalie.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ChronologieAnomalie::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
