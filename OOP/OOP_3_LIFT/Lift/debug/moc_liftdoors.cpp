/****************************************************************************
** Meta object code from reading C++ file 'liftdoors.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../liftdoors.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'liftdoors.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LiftDoors_t {
    QByteArrayData data[8];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LiftDoors_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LiftDoors_t qt_meta_stringdata_LiftDoors = {
    {
QT_MOC_LITERAL(0, 0, 9), // "LiftDoors"
QT_MOC_LITERAL(1, 10, 11), // "DoorsClosed"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 9), // "DoorsOpen"
QT_MOC_LITERAL(4, 33, 13), // "DoorsOpenning"
QT_MOC_LITERAL(5, 47, 12), // "DoorsClosing"
QT_MOC_LITERAL(6, 60, 4), // "Open"
QT_MOC_LITERAL(7, 65, 5) // "Close"

    },
    "LiftDoors\0DoorsClosed\0\0DoorsOpen\0"
    "DoorsOpenning\0DoorsClosing\0Open\0Close"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LiftDoors[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LiftDoors::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LiftDoors *_t = static_cast<LiftDoors *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DoorsClosed(); break;
        case 1: _t->DoorsOpen(); break;
        case 2: _t->DoorsOpenning(); break;
        case 3: _t->DoorsClosing(); break;
        case 4: _t->Open(); break;
        case 5: _t->Close(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LiftDoors::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LiftDoors::DoorsClosed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LiftDoors::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LiftDoors::DoorsOpen)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject LiftDoors::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LiftDoors.data,
      qt_meta_data_LiftDoors,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LiftDoors::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LiftDoors::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LiftDoors.stringdata0))
        return static_cast<void*>(const_cast< LiftDoors*>(this));
    return QObject::qt_metacast(_clname);
}

int LiftDoors::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void LiftDoors::DoorsClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void LiftDoors::DoorsOpen()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
