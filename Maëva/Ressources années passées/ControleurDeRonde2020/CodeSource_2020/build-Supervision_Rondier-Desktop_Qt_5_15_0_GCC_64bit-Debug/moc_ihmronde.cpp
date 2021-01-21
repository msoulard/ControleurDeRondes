/****************************************************************************
** Meta object code from reading C++ file 'ihmronde.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../SupervisionRondier/ihmronde.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ihmronde.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IHMRonde_t {
    QByteArrayData data[18];
    char stringdata0[443];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IHMRonde_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IHMRonde_t qt_meta_stringdata_IHMRonde = {
    {
QT_MOC_LITERAL(0, 0, 8), // "IHMRonde"
QT_MOC_LITERAL(1, 9, 34), // "on_comboBoxNom_currentIndexCh..."
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 4), // "arg1"
QT_MOC_LITERAL(4, 50, 26), // "on_lineEditNom_textChanged"
QT_MOC_LITERAL(5, 77, 46), // "on_tableWidgetListePointeaux_..."
QT_MOC_LITERAL(6, 124, 3), // "row"
QT_MOC_LITERAL(7, 128, 6), // "column"
QT_MOC_LITERAL(8, 135, 48), // "on_tableWidgetDeroulementRond..."
QT_MOC_LITERAL(9, 184, 42), // "on_tableWidgetDeroulementRond..."
QT_MOC_LITERAL(10, 227, 36), // "on_pushButtonAjouterPointeau_..."
QT_MOC_LITERAL(11, 264, 28), // "on_pushButtonAjouter_clicked"
QT_MOC_LITERAL(12, 293, 32), // "on_pushButtonEnregistrer_clicked"
QT_MOC_LITERAL(13, 326, 30), // "on_pushButtonDupliquer_clicked"
QT_MOC_LITERAL(14, 357, 30), // "on_pushButtonSupprimer_clicked"
QT_MOC_LITERAL(15, 388, 23), // "onSpinBoxTempsMinChange"
QT_MOC_LITERAL(16, 412, 6), // "valeur"
QT_MOC_LITERAL(17, 419, 23) // "onSpinBoxTempsMaxChange"

    },
    "IHMRonde\0on_comboBoxNom_currentIndexChanged\0"
    "\0arg1\0on_lineEditNom_textChanged\0"
    "on_tableWidgetListePointeaux_cellDoubleClicked\0"
    "row\0column\0on_tableWidgetDeroulementRonde_cellDoubleClicked\0"
    "on_tableWidgetDeroulementRonde_cellClicked\0"
    "on_pushButtonAjouterPointeau_clicked\0"
    "on_pushButtonAjouter_clicked\0"
    "on_pushButtonEnregistrer_clicked\0"
    "on_pushButtonDupliquer_clicked\0"
    "on_pushButtonSupprimer_clicked\0"
    "onSpinBoxTempsMinChange\0valeur\0"
    "onSpinBoxTempsMaxChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IHMRonde[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       4,    1,   77,    2, 0x08 /* Private */,
       5,    2,   80,    2, 0x08 /* Private */,
       8,    2,   85,    2, 0x08 /* Private */,
       9,    2,   90,    2, 0x08 /* Private */,
      10,    0,   95,    2, 0x08 /* Private */,
      11,    0,   96,    2, 0x08 /* Private */,
      12,    0,   97,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    1,  100,    2, 0x08 /* Private */,
      17,    1,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,

       0        // eod
};

void IHMRonde::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IHMRonde *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_comboBoxNom_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_lineEditNom_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_tableWidgetListePointeaux_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->on_tableWidgetDeroulementRonde_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_tableWidgetDeroulementRonde_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->on_pushButtonAjouterPointeau_clicked(); break;
        case 6: _t->on_pushButtonAjouter_clicked(); break;
        case 7: _t->on_pushButtonEnregistrer_clicked(); break;
        case 8: _t->on_pushButtonDupliquer_clicked(); break;
        case 9: _t->on_pushButtonSupprimer_clicked(); break;
        case 10: _t->onSpinBoxTempsMinChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->onSpinBoxTempsMaxChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject IHMRonde::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_IHMRonde.data,
    qt_meta_data_IHMRonde,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IHMRonde::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IHMRonde::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IHMRonde.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int IHMRonde::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
