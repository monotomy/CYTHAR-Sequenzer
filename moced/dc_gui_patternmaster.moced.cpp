/****************************************************************************
** Meta object code from reading C++ file 'dc_gui_patternmaster.2moc.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dc_gui_patternmaster.2moc.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dc_gui_patternmaster.2moc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dc_gui__Patternmaster[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x08,
      51,   22,   22,   22, 0x08,
      70,   22,   22,   22, 0x08,
     107,   99,   22,   22, 0x08,
     138,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dc_gui__Patternmaster[] = {
    "dc_gui::Patternmaster\0\0"
    "change_mute_tmer_interval()\0"
    "blink_timer_mute()\0on_pb_actionButton_clicked()\0"
    "value__\0on_dial_time_valueChanged(int)\0"
    "on_pb_mute_clicked()\0"
};

void dc_gui::Patternmaster::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Patternmaster *_t = static_cast<Patternmaster *>(_o);
        switch (_id) {
        case 0: _t->change_mute_tmer_interval(); break;
        case 1: _t->blink_timer_mute(); break;
        case 2: _t->on_pb_actionButton_clicked(); break;
        case 3: _t->on_dial_time_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_pb_mute_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData dc_gui::Patternmaster::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dc_gui::Patternmaster::staticMetaObject = {
    { &extendQt::DRAGnDROP_QWidget::staticMetaObject, qt_meta_stringdata_dc_gui__Patternmaster,
      qt_meta_data_dc_gui__Patternmaster, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dc_gui::Patternmaster::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dc_gui::Patternmaster::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dc_gui::Patternmaster::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dc_gui__Patternmaster))
        return static_cast<void*>(const_cast< Patternmaster*>(this));
    if (!strcmp(_clname, "Ui::Patternmaster"))
        return static_cast< Ui::Patternmaster*>(const_cast< Patternmaster*>(this));
    if (!strcmp(_clname, "Events_blockable"))
        return static_cast< Events_blockable*>(const_cast< Patternmaster*>(this));
    if (!strcmp(_clname, "RelativePatternObserver_V2<Patternmaster>"))
        return static_cast< RelativePatternObserver_V2<Patternmaster>*>(const_cast< Patternmaster*>(this));
    if (!strcmp(_clname, "SelecteddetailSequencerObserver_V2"))
        return static_cast< SelecteddetailSequencerObserver_V2*>(const_cast< Patternmaster*>(this));
    typedef extendQt::DRAGnDROP_QWidget QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int dc_gui::Patternmaster::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef extendQt::DRAGnDROP_QWidget QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
