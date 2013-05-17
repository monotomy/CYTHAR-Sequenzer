/****************************************************************************
** Meta object code from reading C++ file 'dc_gui_masterbuttons.2moc.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dc_gui_masterbuttons.2moc.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dc_gui_masterbuttons.2moc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dc_gui__MasterBase[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      49,   19,   19,   19, 0x08,
      70,   19,   19,   19, 0x08,
      92,   19,   19,   19, 0x08,
     115,   19,   19,   19, 0x08,
     133,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dc_gui__MasterBase[] = {
    "dc_gui::MasterBase\0\0on_pb_actionButton_clicked()\0"
    "on_pb_plus_clicked()\0on_pb_minus_clicked()\0"
    "actionButton_clicked()\0pb_plus_clicked()\0"
    "pb_minus_clicked()\0"
};

void dc_gui::MasterBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MasterBase *_t = static_cast<MasterBase *>(_o);
        switch (_id) {
        case 0: _t->on_pb_actionButton_clicked(); break;
        case 1: _t->on_pb_plus_clicked(); break;
        case 2: _t->on_pb_minus_clicked(); break;
        case 3: _t->actionButton_clicked(); break;
        case 4: _t->pb_plus_clicked(); break;
        case 5: _t->pb_minus_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData dc_gui::MasterBase::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dc_gui::MasterBase::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_dc_gui__MasterBase,
      qt_meta_data_dc_gui__MasterBase, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dc_gui::MasterBase::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dc_gui::MasterBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dc_gui::MasterBase::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dc_gui__MasterBase))
        return static_cast<void*>(const_cast< MasterBase*>(this));
    if (!strcmp(_clname, "Ui::Bar"))
        return static_cast< Ui::Bar*>(const_cast< MasterBase*>(this));
    if (!strcmp(_clname, "stuff::Id_public"))
        return static_cast< stuff::Id_public*>(const_cast< MasterBase*>(this));
    return QWidget::qt_metacast(_clname);
}

int dc_gui::MasterBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
