/****************************************************************************
** Meta object code from reading C++ file 'dc_gui_taktsaite_velocity.2moc.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dc_gui_taktsaite_velocity.2moc.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dc_gui_taktsaite_velocity.2moc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dc_gui__TaktsaiteVelocity[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   26,   26,   26, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dc_gui__TaktsaiteVelocity[] = {
    "dc_gui::TaktsaiteVelocity\0\0"
    "on_dial_time_valueChanged(int)\0"
};

void dc_gui::TaktsaiteVelocity::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TaktsaiteVelocity *_t = static_cast<TaktsaiteVelocity *>(_o);
        switch (_id) {
        case 0: _t->on_dial_time_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData dc_gui::TaktsaiteVelocity::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dc_gui::TaktsaiteVelocity::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_dc_gui__TaktsaiteVelocity,
      qt_meta_data_dc_gui__TaktsaiteVelocity, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dc_gui::TaktsaiteVelocity::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dc_gui::TaktsaiteVelocity::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dc_gui::TaktsaiteVelocity::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dc_gui__TaktsaiteVelocity))
        return static_cast<void*>(const_cast< TaktsaiteVelocity*>(this));
    if (!strcmp(_clname, "Ui::TaktsaiteVelocity"))
        return static_cast< Ui::TaktsaiteVelocity*>(const_cast< TaktsaiteVelocity*>(this));
    return QWidget::qt_metacast(_clname);
}

int dc_gui::TaktsaiteVelocity::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
