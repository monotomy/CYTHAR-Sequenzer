/****************************************************************************
** Meta object code from reading C++ file 'dc_gui_midideviceeditor.2moc.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dc_gui_midideviceeditor.2moc.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dc_gui_midideviceeditor.2moc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dc_gui__Midideviceeditor[] = {

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
      64,   25,   25,   25, 0x08,
     103,   25,   25,   25, 0x08,
     123,   25,   25,   25, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dc_gui__Midideviceeditor[] = {
    "dc_gui::Midideviceeditor\0\0"
    "on_cb_device_currentIndexChanged(int)\0"
    "on_cb_channel_currentIndexChanged(int)\0"
    "enterEvent(QEvent*)\0leaveEvent(QEvent*)\0"
};

void dc_gui::Midideviceeditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Midideviceeditor *_t = static_cast<Midideviceeditor *>(_o);
        switch (_id) {
        case 0: _t->on_cb_device_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_cb_channel_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->enterEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 3: _t->leaveEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData dc_gui::Midideviceeditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dc_gui::Midideviceeditor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_dc_gui__Midideviceeditor,
      qt_meta_data_dc_gui__Midideviceeditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dc_gui::Midideviceeditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dc_gui::Midideviceeditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dc_gui::Midideviceeditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dc_gui__Midideviceeditor))
        return static_cast<void*>(const_cast< Midideviceeditor*>(this));
    if (!strcmp(_clname, "Ui::Midideviceeditor"))
        return static_cast< Ui::Midideviceeditor*>(const_cast< Midideviceeditor*>(this));
    if (!strcmp(_clname, "Events_blockable"))
        return static_cast< Events_blockable*>(const_cast< Midideviceeditor*>(this));
    if (!strcmp(_clname, "RelativePatternsaiteObserver_V2<UNIQUE_guiMidideviceeditor_forPatternsaiteobserver>"))
        return static_cast< RelativePatternsaiteObserver_V2<UNIQUE_guiMidideviceeditor_forPatternsaiteobserver>*>(const_cast< Midideviceeditor*>(this));
    if (!strcmp(_clname, "SelectedPatternObserver_V2"))
        return static_cast< SelectedPatternObserver_V2*>(const_cast< Midideviceeditor*>(this));
    return QWidget::qt_metacast(_clname);
}

int dc_gui::Midideviceeditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
static const uint qt_meta_data_dc_gui__Midideviceeditormaster[] = {

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
      32,   31,   31,   31, 0x08,
      56,   31,   31,   31, 0x08,
      80,   31,   31,   31, 0x08,
     115,   31,   31,   31, 0x08,
     135,   31,   31,   31, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dc_gui__Midideviceeditormaster[] = {
    "dc_gui::Midideviceeditormaster\0\0"
    "on_pB_set2all_clicked()\0on_pB_refresh_clicked()\0"
    "on_pb_set_midi_in_device_clicked()\0"
    "enterEvent(QEvent*)\0leaveEvent(QEvent*)\0"
};

void dc_gui::Midideviceeditormaster::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Midideviceeditormaster *_t = static_cast<Midideviceeditormaster *>(_o);
        switch (_id) {
        case 0: _t->on_pB_set2all_clicked(); break;
        case 1: _t->on_pB_refresh_clicked(); break;
        case 2: _t->on_pb_set_midi_in_device_clicked(); break;
        case 3: _t->enterEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 4: _t->leaveEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData dc_gui::Midideviceeditormaster::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dc_gui::Midideviceeditormaster::staticMetaObject = {
    { &extendQt::DRAGnDROP_QWidget::staticMetaObject, qt_meta_stringdata_dc_gui__Midideviceeditormaster,
      qt_meta_data_dc_gui__Midideviceeditormaster, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dc_gui::Midideviceeditormaster::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dc_gui::Midideviceeditormaster::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dc_gui::Midideviceeditormaster::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dc_gui__Midideviceeditormaster))
        return static_cast<void*>(const_cast< Midideviceeditormaster*>(this));
    if (!strcmp(_clname, "Ui::Midideviceeditormaster"))
        return static_cast< Ui::Midideviceeditormaster*>(const_cast< Midideviceeditormaster*>(this));
    if (!strcmp(_clname, "SelectedPatternObserver_V2"))
        return static_cast< SelectedPatternObserver_V2*>(const_cast< Midideviceeditormaster*>(this));
    if (!strcmp(_clname, "dc_midi::MidiOutPortsPerApiGUIInterface"))
        return static_cast< dc_midi::MidiOutPortsPerApiGUIInterface*>(const_cast< Midideviceeditormaster*>(this));
    typedef extendQt::DRAGnDROP_QWidget QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int dc_gui::Midideviceeditormaster::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
