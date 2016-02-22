/****************************************************************************
** Meta object code from reading C++ file 'mytreewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../scene_graph/src/scene/mytreewidget.h"
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
    QByteArrayData data[15];
    char stringdata[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyTreeWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyTreeWidget_t qt_meta_stringdata_MyTreeWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MyTreeWidget"
QT_MOC_LITERAL(1, 13, 14), // "sig_sendTransX"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 1), // "s"
QT_MOC_LITERAL(4, 31, 14), // "sig_sendTransY"
QT_MOC_LITERAL(5, 46, 14), // "sig_sendTransZ"
QT_MOC_LITERAL(6, 61, 17), // "sig_sendRotationX"
QT_MOC_LITERAL(7, 79, 17), // "sig_sendRotationY"
QT_MOC_LITERAL(8, 97, 17), // "sig_sendRotationZ"
QT_MOC_LITERAL(9, 115, 14), // "sig_sendScaleX"
QT_MOC_LITERAL(10, 130, 14), // "sig_sendScaleY"
QT_MOC_LITERAL(11, 145, 14), // "sig_sendScaleZ"
QT_MOC_LITERAL(12, 160, 16), // "slot_newRootNode"
QT_MOC_LITERAL(13, 177, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(14, 194, 23) // "slot_processClickedItem"

    },
    "MyTreeWidget\0sig_sendTransX\0\0s\0"
    "sig_sendTransY\0sig_sendTransZ\0"
    "sig_sendRotationX\0sig_sendRotationY\0"
    "sig_sendRotationZ\0sig_sendScaleX\0"
    "sig_sendScaleY\0sig_sendScaleZ\0"
    "slot_newRootNode\0QTreeWidgetItem*\0"
    "slot_processClickedItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyTreeWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       5,    1,   75,    2, 0x06 /* Public */,
       6,    1,   78,    2, 0x06 /* Public */,
       7,    1,   81,    2, 0x06 /* Public */,
       8,    1,   84,    2, 0x06 /* Public */,
       9,    1,   87,    2, 0x06 /* Public */,
      10,    1,   90,    2, 0x06 /* Public */,
      11,    1,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,   96,    2, 0x0a /* Public */,
      14,    1,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, 0x80000000 | 13,    2,

       0        // eod
};

void MyTreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyTreeWidget *_t = static_cast<MyTreeWidget *>(_o);
        switch (_id) {
        case 0: _t->sig_sendTransX((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sig_sendTransY((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sig_sendTransZ((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sig_sendRotationX((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->sig_sendRotationY((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->sig_sendRotationZ((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->sig_sendScaleX((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->sig_sendScaleY((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->sig_sendScaleZ((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->slot_newRootNode((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 10: _t->slot_processClickedItem((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyTreeWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sig_sendTransX)) {
                *result = 0;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sig_sendTransY)) {
                *result = 1;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sig_sendTransZ)) {
                *result = 2;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sig_sendRotationX)) {
                *result = 3;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sig_sendRotationY)) {
                *result = 4;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sig_sendRotationZ)) {
                *result = 5;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sig_sendScaleX)) {
                *result = 6;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sig_sendScaleY)) {
                *result = 7;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sig_sendScaleZ)) {
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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MyTreeWidget::sig_sendTransX(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyTreeWidget::sig_sendTransY(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyTreeWidget::sig_sendTransZ(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyTreeWidget::sig_sendRotationX(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyTreeWidget::sig_sendRotationY(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyTreeWidget::sig_sendRotationZ(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MyTreeWidget::sig_sendScaleX(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MyTreeWidget::sig_sendScaleY(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MyTreeWidget::sig_sendScaleZ(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
