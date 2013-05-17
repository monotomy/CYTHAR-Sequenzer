/****************************************************************************
** Meta object code from reading C++ file 'dc_gui_filemanager.2moc.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dc_gui_filemanager.2moc.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dc_gui_filemanager.2moc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dc_gui__Filemanager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x08,
      42,   20,   20,   20, 0x08,
      63,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dc_gui__Filemanager[] = {
    "dc_gui::Filemanager\0\0on_pb_save_clicked()\0"
    "on_pb_load_clicked()\0on_pb_cancel_clicked()\0"
};

void dc_gui::Filemanager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Filemanager *_t = static_cast<Filemanager *>(_o);
        switch (_id) {
        case 0: _t->on_pb_save_clicked(); break;
        case 1: _t->on_pb_load_clicked(); break;
        case 2: _t->on_pb_cancel_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData dc_gui::Filemanager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dc_gui::Filemanager::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_dc_gui__Filemanager,
      qt_meta_data_dc_gui__Filemanager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dc_gui::Filemanager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dc_gui::Filemanager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dc_gui::Filemanager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dc_gui__Filemanager))
        return static_cast<void*>(const_cast< Filemanager*>(this));
    if (!strcmp(_clname, "Ui::Filemanager"))
        return static_cast< Ui::Filemanager*>(const_cast< Filemanager*>(this));
    return QWidget::qt_metacast(_clname);
}

int dc_gui::Filemanager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
