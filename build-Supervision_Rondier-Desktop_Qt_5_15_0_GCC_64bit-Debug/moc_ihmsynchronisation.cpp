/****************************************************************************
** Meta object code from reading C++ file 'ihmsynchronisation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ControleurDeRonde_2020/ihmsynchronisation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ihmsynchronisation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IHMSynchronisation_t {
    QByteArrayData data[18];
    char stringdata0[347];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IHMSynchronisation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IHMSynchronisation_t qt_meta_stringdata_IHMSynchronisation = {
    {
QT_MOC_LITERAL(0, 0, 18), // "IHMSynchronisation"
QT_MOC_LITERAL(1, 19, 21), // "listeSmartphoneChange"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 14), // "QList<QString>"
QT_MOC_LITERAL(4, 57, 33), // "on_pushButtonSynchroniser_cli..."
QT_MOC_LITERAL(5, 91, 23), // "onQProcessLogsReadyRead"
QT_MOC_LITERAL(6, 115, 19), // "onAnimationFinished"
QT_MOC_LITERAL(7, 135, 12), // "onNouveauLog"
QT_MOC_LITERAL(8, 148, 5), // "texte"
QT_MOC_LITERAL(9, 154, 4), // "gras"
QT_MOC_LITERAL(10, 159, 31), // "onTimeaoutErreurSynchronisation"
QT_MOC_LITERAL(11, 191, 12), // "onExitSQLite"
QT_MOC_LITERAL(12, 204, 23), // "onListeSmartphoneChange"
QT_MOC_LITERAL(13, 228, 17), // "QList<Smartphone>"
QT_MOC_LITERAL(14, 246, 16), // "_listeSmartphone"
QT_MOC_LITERAL(15, 263, 49), // "on_comboBoxSelectionSmartphon..."
QT_MOC_LITERAL(16, 313, 4), // "arg1"
QT_MOC_LITERAL(17, 318, 28) // "on_pushButtonDetails_clicked"

    },
    "IHMSynchronisation\0listeSmartphoneChange\0"
    "\0QList<QString>\0on_pushButtonSynchroniser_clicked\0"
    "onQProcessLogsReadyRead\0onAnimationFinished\0"
    "onNouveauLog\0texte\0gras\0"
    "onTimeaoutErreurSynchronisation\0"
    "onExitSQLite\0onListeSmartphoneChange\0"
    "QList<Smartphone>\0_listeSmartphone\0"
    "on_comboBoxSelectionSmartphone_currentTextChanged\0"
    "arg1\0on_pushButtonDetails_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IHMSynchronisation[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   67,    2, 0x08 /* Private */,
       5,    0,   68,    2, 0x08 /* Private */,
       6,    0,   69,    2, 0x08 /* Private */,
       7,    2,   70,    2, 0x08 /* Private */,
      10,    0,   75,    2, 0x08 /* Private */,
      11,    0,   76,    2, 0x08 /* Private */,
      12,    1,   77,    2, 0x08 /* Private */,
      15,    1,   80,    2, 0x08 /* Private */,
      17,    0,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,

       0        // eod
};

void IHMSynchronisation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IHMSynchronisation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->listeSmartphoneChange((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 1: _t->on_pushButtonSynchroniser_clicked(); break;
        case 2: _t->onQProcessLogsReadyRead(); break;
        case 3: _t->onAnimationFinished(); break;
        case 4: _t->onNouveauLog((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->onTimeaoutErreurSynchronisation(); break;
        case 6: _t->onExitSQLite(); break;
        case 7: _t->onListeSmartphoneChange((*reinterpret_cast< QList<Smartphone>(*)>(_a[1]))); break;
        case 8: _t->on_comboBoxSelectionSmartphone_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_pushButtonDetails_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (IHMSynchronisation::*)(QList<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IHMSynchronisation::listeSmartphoneChange)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject IHMSynchronisation::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_IHMSynchronisation.data,
    qt_meta_data_IHMSynchronisation,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IHMSynchronisation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IHMSynchronisation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IHMSynchronisation.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int IHMSynchronisation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void IHMSynchronisation::listeSmartphoneChange(QList<QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
