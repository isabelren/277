/****************************************************************************
** Meta object code from reading C++ file 'mygl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../assignment_package 2/skeleton_mesh/src/mygl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mygl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyGL_t {
    QByteArrayData data[13];
    char stringdata[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyGL_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyGL_t qt_meta_stringdata_MyGL = {
    {
QT_MOC_LITERAL(0, 0, 4), // "MyGL"
QT_MOC_LITERAL(1, 5, 12), // "sig_sendRoot"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(4, 36, 12), // "slot_LoadOBJ"
QT_MOC_LITERAL(5, 49, 13), // "slot_LoadJSON"
QT_MOC_LITERAL(6, 63, 13), // "slot_skinMesh"
QT_MOC_LITERAL(7, 77, 11), // "slot_update"
QT_MOC_LITERAL(8, 89, 23), // "slot_updateCurrentJoint"
QT_MOC_LITERAL(9, 113, 6), // "Joint*"
QT_MOC_LITERAL(10, 120, 13), // "slot_moveMesh"
QT_MOC_LITERAL(11, 134, 13), // "slot_dualQuat"
QT_MOC_LITERAL(12, 148, 16) // "slot_linearBlend"

    },
    "MyGL\0sig_sendRoot\0\0QTreeWidgetItem*\0"
    "slot_LoadOBJ\0slot_LoadJSON\0slot_skinMesh\0"
    "slot_update\0slot_updateCurrentJoint\0"
    "Joint*\0slot_moveMesh\0slot_dualQuat\0"
    "slot_linearBlend"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGL[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   62,    2, 0x0a /* Public */,
       5,    0,   63,    2, 0x0a /* Public */,
       6,    0,   64,    2, 0x0a /* Public */,
       7,    0,   65,    2, 0x0a /* Public */,
       8,    1,   66,    2, 0x0a /* Public */,
      10,    0,   69,    2, 0x0a /* Public */,
      11,    0,   70,    2, 0x0a /* Public */,
      12,    0,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyGL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyGL *_t = static_cast<MyGL *>(_o);
        switch (_id) {
        case 0: _t->sig_sendRoot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->slot_LoadOBJ(); break;
        case 2: _t->slot_LoadJSON(); break;
        case 3: _t->slot_skinMesh(); break;
        case 4: _t->slot_update(); break;
        case 5: _t->slot_updateCurrentJoint((*reinterpret_cast< Joint*(*)>(_a[1]))); break;
        case 6: _t->slot_moveMesh(); break;
        case 7: _t->slot_dualQuat(); break;
        case 8: _t->slot_linearBlend(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyGL::*_t)(QTreeWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_sendRoot)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MyGL::staticMetaObject = {
    { &GLWidget277::staticMetaObject, qt_meta_stringdata_MyGL.data,
      qt_meta_data_MyGL,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGL::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyGL.stringdata))
        return static_cast<void*>(const_cast< MyGL*>(this));
    return GLWidget277::qt_metacast(_clname);
}

int MyGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GLWidget277::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void MyGL::sig_sendRoot(QTreeWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
