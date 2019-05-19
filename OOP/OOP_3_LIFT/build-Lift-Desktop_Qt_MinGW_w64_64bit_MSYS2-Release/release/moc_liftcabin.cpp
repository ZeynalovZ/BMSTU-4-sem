/****************************************************************************
** Meta object code from reading C++ file 'liftcabin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Lift/liftcabin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'liftcabin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LiftCabin_t {
    QByteArrayData data[14];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LiftCabin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LiftCabin_t qt_meta_stringdata_LiftCabin = {
    {
QT_MOC_LITERAL(0, 0, 9), // "LiftCabin"
QT_MOC_LITERAL(1, 10, 13), // "FloorAchieved"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "FloorPassed"
QT_MOC_LITERAL(4, 37, 5), // "floor"
QT_MOC_LITERAL(5, 43, 9), // "Direction"
QT_MOC_LITERAL(6, 53, 9), // "direction"
QT_MOC_LITERAL(7, 63, 4), // "Move"
QT_MOC_LITERAL(8, 68, 22), // "AchievedForResetButton"
QT_MOC_LITERAL(9, 91, 12), // "cabinStopped"
QT_MOC_LITERAL(10, 104, 12), // "CurrentFloor"
QT_MOC_LITERAL(11, 117, 14), // "FloorAchieving"
QT_MOC_LITERAL(12, 132, 8), // "slotBusy"
QT_MOC_LITERAL(13, 141, 4) // "Stay"

    },
    "LiftCabin\0FloorAchieved\0\0FloorPassed\0"
    "floor\0Direction\0direction\0Move\0"
    "AchievedForResetButton\0cabinStopped\0"
    "CurrentFloor\0FloorAchieving\0slotBusy\0"
    "Stay"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LiftCabin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    2,   55,    2, 0x06 /* Public */,
       7,    0,   60,    2, 0x06 /* Public */,
       8,    1,   61,    2, 0x06 /* Public */,
       9,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   67,    2, 0x0a /* Public */,
      12,    1,   68,    2, 0x0a /* Public */,
      13,    0,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5,    4,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,

       0        // eod
};

void LiftCabin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LiftCabin *_t = static_cast<LiftCabin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->FloorAchieved(); break;
        case 1: _t->FloorPassed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Direction(*)>(_a[2]))); break;
        case 2: _t->Move(); break;
        case 3: _t->AchievedForResetButton((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->cabinStopped((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->FloorAchieving(); break;
        case 6: _t->slotBusy((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->Stay(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (LiftCabin::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LiftCabin::FloorAchieved)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LiftCabin::*_t)(int , Direction );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LiftCabin::FloorPassed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (LiftCabin::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LiftCabin::Move)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (LiftCabin::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LiftCabin::AchievedForResetButton)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (LiftCabin::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LiftCabin::cabinStopped)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LiftCabin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LiftCabin.data,
      qt_meta_data_LiftCabin,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LiftCabin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LiftCabin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LiftCabin.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LiftCabin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void LiftCabin::FloorAchieved()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LiftCabin::FloorPassed(int _t1, Direction _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LiftCabin::Move()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void LiftCabin::AchievedForResetButton(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void LiftCabin::cabinStopped(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
