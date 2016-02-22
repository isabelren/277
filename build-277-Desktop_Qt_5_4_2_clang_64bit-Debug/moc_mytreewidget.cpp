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
    QByteArrayData data[22];
    char stringdata[301];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyTreeWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyTreeWidget_t qt_meta_stringdata_MyTreeWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MyTreeWidget"
QT_MOC_LITERAL(1, 13, 12), // "sig_newTrans"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "sig_XTrans"
QT_MOC_LITERAL(4, 38, 10), // "sig_YTrans"
QT_MOC_LITERAL(5, 49, 10), // "sig_ZTrans"
QT_MOC_LITERAL(6, 60, 16), // "slot_newRootNode"
QT_MOC_LITERAL(7, 77, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(8, 94, 16), // "slot_changeTrans"
QT_MOC_LITERAL(9, 111, 1), // "i"
QT_MOC_LITERAL(10, 113, 17), // "slot_addChildNode"
QT_MOC_LITERAL(11, 131, 24), // "ShaderProgram::Drawable*"
QT_MOC_LITERAL(12, 156, 5), // "shape"
QT_MOC_LITERAL(13, 162, 22), // "slot_removeSingleChild"
QT_MOC_LITERAL(14, 185, 22), // "slot_removeAllChildren"
QT_MOC_LITERAL(15, 208, 22), // "slot_changeCurrentNode"
QT_MOC_LITERAL(16, 231, 17), // "slot_changeXTrans"
QT_MOC_LITERAL(17, 249, 1), // "x"
QT_MOC_LITERAL(18, 251, 17), // "slot_changeYTrans"
QT_MOC_LITERAL(19, 269, 17), // "slot_changeZTrans"
QT_MOC_LITERAL(20, 287, 11), // "slot_rename"
QT_MOC_LITERAL(21, 299, 1) // "s"

    },
    "MyTreeWidget\0sig_newTrans\0\0sig_XTrans\0"
    "sig_YTrans\0sig_ZTrans\0slot_newRootNode\0"
    "QTreeWidgetItem*\0slot_changeTrans\0i\0"
    "slot_addChildNode\0ShaderProgram::Drawable*\0"
    "shape\0slot_removeSingleChild\0"
    "slot_removeAllChildren\0slot_changeCurrentNode\0"
    "slot_changeXTrans\0x\0slot_changeYTrans\0"
    "slot_changeZTrans\0slot_rename\0s"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyTreeWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       3,    1,   87,    2, 0x06 /* Public */,
       4,    1,   90,    2, 0x06 /* Public */,
       5,    1,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   96,    2, 0x0a /* Public */,
       8,    1,   99,    2, 0x0a /* Public */,
      10,    1,  102,    2, 0x0a /* Public */,
      13,    0,  105,    2, 0x0a /* Public */,
      14,    0,  106,    2, 0x0a /* Public */,
      15,    0,  107,    2, 0x0a /* Public */,
      16,    1,  108,    2, 0x0a /* Public */,
      18,    1,  111,    2, 0x0a /* Public */,
      19,    1,  114,    2, 0x0a /* Public */,
      20,    1,  117,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   17,
    QMetaType::Void, QMetaType::Double,   17,
    QMetaType::Void, QMetaType::Double,   17,
    QMetaType::Void, QMetaType::QString,   21,

       0        // eod
};

void MyTreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyTreeWidget *_t = static_cast<MyTreeWidget *>(_o);
        switch (_id) {
        case 0: _t->sig_newTrans((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sig_XTrans((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->sig_YTrans((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->sig_ZTrans((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->slot_newRootNode((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->slot_changeTrans((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->slot_addChildNode((*reinterpret_cast< ShaderProgram::Drawable*(*)>(_a[1]))); break;
        case 7: _t->slot_removeSingleChild(); break;
        case 8: _t->slot_removeAllChildren(); break;
        case 9: _t->slot_changeCurrentNode(); break;
        case 10: _t->slot_changeXTrans((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->slot_changeYTrans((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->slot_changeZTrans((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->slot_rename((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyTreeWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sig_newTrans)) {
                *result = 0;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sig_XTrans)) {
                *result = 1;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sig_YTrans)) {
                *result = 2;
            }
        }
        {
            typedef void (MyTreeWidget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTreeWidget::sig_ZTrans)) {
                *result = 3;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MyTreeWidget::sig_newTrans(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyTreeWidget::sig_XTrans(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyTreeWidget::sig_YTrans(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyTreeWidget::sig_ZTrans(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
