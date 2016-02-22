/****************************************************************************
** Meta object code from reading C++ file 'mytreewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../assignment_package 2/skeleton_mesh/src/scene/mytreewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mytreewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyTreeWidget_t {
    QByteArrayData data[25];
    char stringdata[297];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyTreeWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyTreeWidget_t qt_meta_stringdata_MyTreeWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MyTreeWidget"
QT_MOC_LITERAL(1, 13, 10), // "sig_update"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "sig_xRot"
QT_MOC_LITERAL(4, 34, 8), // "sig_yRot"
QT_MOC_LITERAL(5, 43, 8), // "sig_zRot"
QT_MOC_LITERAL(6, 52, 10), // "sig_xTrans"
QT_MOC_LITERAL(7, 63, 10), // "sig_yTrans"
QT_MOC_LITERAL(8, 74, 10), // "sig_zTrans"
QT_MOC_LITERAL(9, 85, 12), // "sig_moveMesh"
QT_MOC_LITERAL(10, 98, 17), // "sig_changeCurrent"
QT_MOC_LITERAL(11, 116, 6), // "Joint*"
QT_MOC_LITERAL(12, 123, 16), // "slot_newRootNode"
QT_MOC_LITERAL(13, 140, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(14, 157, 23), // "slot_changeCurrentJoint"
QT_MOC_LITERAL(15, 181, 9), // "slot_xAdd"
QT_MOC_LITERAL(16, 191, 9), // "slot_xSub"
QT_MOC_LITERAL(17, 201, 9), // "slot_yAdd"
QT_MOC_LITERAL(18, 211, 9), // "slot_ySub"
QT_MOC_LITERAL(19, 221, 9), // "slot_zAdd"
QT_MOC_LITERAL(20, 231, 9), // "slot_zSub"
QT_MOC_LITERAL(21, 241, 17), // "slot_changeXTrans"
QT_MOC_LITERAL(22, 259, 1), // "x"
QT_MOC_LITERAL(23, 261, 17), // "slot_changeYTrans"
QT_MOC_LITERAL(24, 279, 17) // "slot_changeZTrans"

    },
    "MyTreeWidget\0sig_update\0\0sig_xRot\0"
    "sig_yRot\0sig_zRot\0sig_xTrans\0sig_yTrans\0"
    "sig_zTrans\0sig_moveMesh\0sig_changeCurrent\0"
    "Joint*\0slot_newRootNode\0QTreeWidgetItem*\0"
    "slot_changeCurrentJoint\0slot_xAdd\0"
    "slot_xSub\0slot_yAdd\0slot_ySub\0slot_zAdd\0"
    "slot_zSub\0slot_changeXTrans\0x\0"
    "slot_changeYTrans\0slot_changeZTrans"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyTreeWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x06 /* Public */,
       3,    1,  115,    2, 0x06 /* Public */,
       4,    1,  118,    2, 0x06 /* Public */,
       5,    1,  121,    2, 0x06 /* Public */,
       6,    1,  124,    2, 0x06 /* Public */,
       7,    1,  127,    2, 0x06 /* Public */,
       8,    1,  130,    2, 0x06 /* Public */,
       9,    0,  133,    2, 0x06 /* Public */,
      10,    1,  134,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,  137,    2, 0x0a /* Public */,
      14,    0,  140,    2, 0x0a /* Public */,
      15,    0,  141,    2, 0x0a /* Public */,
      16,    0,  142,    2, 0x0a /* Public */,
      17,    0,  143,    2, 0x0a /* Public */,
      18,    0,  144,    2, 0x0a /* Public */,
      19,    0,  145,    2, 0x0a /* Public */,
      20,    0,  146,    2, 0x0a /* Public */,
      21,    1,  147,    2, 0x0a /* Public */,
      23,    1,  150,    2, 0x0a /* Public */,
      24,    1,  153,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   22,
    QMetaType::Void, QMetaType::Double,   22,
    QMetaType::Void, QMetaType::Double,   22,

       0        // eod
};

void MyTreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyTreeWidget *_t = static_cast<MyTreeWidget *>(_o);
        switch (_id) {
        case 0: _t->sig_update(); break;
        case 1: _t->sig_xRot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->sig_yRot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->sig_zRot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->sig_xTrans((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->sig_yTrans((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->sig_zTrans((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->sig_moveMesh(); break;
        case 8: _t->sig_changeCurrent((*reinterpret_cast< Joint*(*)>(_a[1]))); break;
        case 9: _t->slot_newRootNode((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 10: _t->slot_changeCurrentJoint(); break;
        case 11: _t->slot_xAdd(); break;
        case 12: _t->slot_xSub(); break;
        case 13: _t->slot_yAdd(); break;
        case 14: _t->slot_ySub(); break;
        case 15: _t->slot_zAdd(); break;
        case 16: _t->slot_zSub(); break;
        case 17: _t->slot_changeXTrans((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->slot_changeYTrans((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: _t->slot_changeZTrans((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyTreeWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sig_update)) {
                *result = 0;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sig_xRot)) {
                *result = 1;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sig_yRot)) {
                *result = 2;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sig_zRot)) {
                *result = 3;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sig_xTrans)) {
                *result = 4;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sig_yTrans)) {
                *result = 5;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sig_zTrans)) {
                *result = 6;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sig_moveMesh)) {
                *result = 7;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)(Joint * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sig_changeCurrent)) {
                *result = 8;
            }
        }
    }
}

const QMetaObject MyTreeWidget::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_MyTreeWidget.data,
      qt_meta_data_MyTreeWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyTreeWidget.stringdata))
        return static_cast<void*>(const_cast< MyTreeWidget*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int MyTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void MyTreeWidget::sig_update()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MyTreeWidget::sig_xRot(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyTreeWidget::sig_yRot(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyTreeWidget::sig_zRot(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyTreeWidget::sig_xTrans(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyTreeWidget::sig_yTrans(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MyTreeWidget::sig_zTrans(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MyTreeWidget::sig_moveMesh()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void MyTreeWidget::sig_changeCurrent(Joint * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
