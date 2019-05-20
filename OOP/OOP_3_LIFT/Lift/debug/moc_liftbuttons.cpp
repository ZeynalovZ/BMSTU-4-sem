/****************************************************************************
** Meta object code from reading C++ file 'liftbuttons.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../liftbuttons.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'liftbuttons.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LiftButtons_t {
    QByteArrayData data[7];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LiftButtons_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LiftButtons_t qt_meta_stringdata_LiftButtons = {
    {
QT_MOC_LITERAL(0, 0, 11), // "LiftButtons"
QT_MOC_LITERAL(1, 12, 11), // "resetButton"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "floorRequest"
QT_MOC_LITERAL(4, 38, 5), // "floor"
QT_MOC_LITERAL(5, 44, 11), // "slotPressed"
QT_MOC_LITERAL(6, 56, 12) // "slotReleased"

    },
    "LiftButtons\0resetButton\0\0floorRequest\0"
    "floor\0slotPressed\0slotReleased"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LiftButtons[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   38,    2, 0x0a /* Public */,
       6,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LiftButtons::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LiftButtons *_t = static_cast<LiftButtons *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resetButton(); break;
        case 1: _t->floorRequest((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->slotPressed(); break;
        case 3: _t->slotReleased(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LiftButtons::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LiftButtons::resetButton)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LiftButtons::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LiftButtons::floorRequest)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject LiftButtons::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_LiftButtons.data,
      qt_meta_data_LiftButtons,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LiftButtons::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LiftButtons::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LiftButtons.stringdata0))
        return static_cast<void*>(const_cast< LiftButtons*>(this));
    return QPushButton::qt_metacast(_clname);
}

int LiftButtons::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void LiftButtons::resetButton()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void LiftButtons::floorRequest(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
