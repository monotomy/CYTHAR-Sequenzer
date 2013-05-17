/****************************************************************************
** Meta object code from reading C++ file 'dc_gui_patternsaite_mute.2moc.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dc_gui_patternsaite_mute.2moc.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dc_gui_patternsaite_mute.2moc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dc_gui__PatternsaiteMute[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   25,   25,   25, 0x08,
      45,   25,   25,   25, 0x08,
      88,   73,   25,   25, 0x08,
     119,   25,   25,   25, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dc_gui__PatternsaiteMute[] = {
    "dc_gui::PatternsaiteMute\0\0blink_timer_mute()\0"
    "change_mute_tmer_interval()\0time_in_takt__\0"
    "on_dial_time_valueChanged(int)\0"
    "on_pb_clicked()\0"
};

void dc_gui::PatternsaiteMute::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PatternsaiteMute *_t = static_cast<PatternsaiteMute *>(_o);
        switch (_id) {
        case 0: _t->blink_timer_mute(); break;
        case 1: _t->change_mute_tmer_interval(); break;
        case 2: _t->on_dial_time_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pb_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData dc_gui::PatternsaiteMute::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dc_gui::PatternsaiteMute::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_dc_gui__PatternsaiteMute,
      qt_meta_data_dc_gui__PatternsaiteMute, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dc_gui::PatternsaiteMute::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dc_gui::PatternsaiteMute::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dc_gui::PatternsaiteMute::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dc_gui__PatternsaiteMute))
        return static_cast<void*>(const_cast< PatternsaiteMute*>(this));
    if (!strcmp(_clname, "Ui::PatternsaiteMute"))
        return static_cast< Ui::PatternsaiteMute*>(const_cast< PatternsaiteMute*>(this));
    if (!strcmp(_clname, "Events_blockable"))
        return static_cast< Events_blockable*>(const_cast< PatternsaiteMute*>(this));
    if (!strcmp(_clname, "RelativePatternsaiteObserver_V2<PatternsaiteMute>"))
        return static_cast< RelativePatternsaiteObserver_V2<PatternsaiteMute>*>(const_cast< PatternsaiteMute*>(this));
    if (!strcmp(_clname, "SelecteddetailSequencerObserver_V2"))
        return static_cast< SelecteddetailSequencerObserver_V2*>(const_cast< PatternsaiteMute*>(this));
    return QWidget::qt_metacast(_clname);
}

int dc_gui::PatternsaiteMute::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
