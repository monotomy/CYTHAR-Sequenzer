/****************************************************************************
** Meta object code from reading C++ file 'dc_gui_taktmaster.2moc.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dc_gui_taktmaster.2moc.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dc_gui_taktmaster.2moc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dc_gui__Taktchain[] = {

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
      27,   19,   18,   18, 0x08,
      52,   18,   18,   18, 0x08,
      82,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dc_gui__Taktchain[] = {
    "dc_gui::Taktchain\0\0event__\0"
    "wheelEvent(QWheelEvent*)\0"
    "mousePressEvent(QMouseEvent*)\0"
    "set_selected()\0"
};

void dc_gui::Taktchain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Taktchain *_t = static_cast<Taktchain *>(_o);
        switch (_id) {
        case 0: _t->wheelEvent((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 1: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->set_selected(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData dc_gui::Taktchain::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dc_gui::Taktchain::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_dc_gui__Taktchain,
      qt_meta_data_dc_gui__Taktchain, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dc_gui::Taktchain::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dc_gui::Taktchain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dc_gui::Taktchain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dc_gui__Taktchain))
        return static_cast<void*>(const_cast< Taktchain*>(this));
    if (!strcmp(_clname, "Ui::Taktchain"))
        return static_cast< Ui::Taktchain*>(const_cast< Taktchain*>(this));
    if (!strcmp(_clname, "RelativeTaktchainObserver_V2<Taktchain>"))
        return static_cast< RelativeTaktchainObserver_V2<Taktchain>*>(const_cast< Taktchain*>(this));
    if (!strcmp(_clname, "SelectedPatternObserver_V2"))
        return static_cast< SelectedPatternObserver_V2*>(const_cast< Taktchain*>(this));
    return QWidget::qt_metacast(_clname);
}

int dc_gui::Taktchain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
static const uint qt_meta_data_dc_gui__Taktmaster[] = {

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
      34,   19,   19,   19, 0x08,
      57,   19,   19,   19, 0x08,
      78,   19,   19,   19, 0x08,
     107,   19,   19,   19, 0x08,
     128,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dc_gui__Taktmaster[] = {
    "dc_gui::Taktmaster\0\0set_running()\0"
    "setup_blink_overhide()\0set_blink_overhide()\0"
    "on_pb_actionButton_clicked()\0"
    "on_pb_plus_clicked()\0on_pb_minus_clicked()\0"
};

void dc_gui::Taktmaster::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Taktmaster *_t = static_cast<Taktmaster *>(_o);
        switch (_id) {
        case 0: _t->set_running(); break;
        case 1: _t->setup_blink_overhide(); break;
        case 2: _t->set_blink_overhide(); break;
        case 3: _t->on_pb_actionButton_clicked(); break;
        case 4: _t->on_pb_plus_clicked(); break;
        case 5: _t->on_pb_minus_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData dc_gui::Taktmaster::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dc_gui::Taktmaster::staticMetaObject = {
    { &extendQt::DRAGnDROP_QWidget::staticMetaObject, qt_meta_stringdata_dc_gui__Taktmaster,
      qt_meta_data_dc_gui__Taktmaster, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dc_gui::Taktmaster::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dc_gui::Taktmaster::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dc_gui::Taktmaster::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dc_gui__Taktmaster))
        return static_cast<void*>(const_cast< Taktmaster*>(this));
    if (!strcmp(_clname, "Ui::Taktmaster"))
        return static_cast< Ui::Taktmaster*>(const_cast< Taktmaster*>(this));
    if (!strcmp(_clname, "Events_blockable"))
        return static_cast< Events_blockable*>(const_cast< Taktmaster*>(this));
    if (!strcmp(_clname, "SelecteddetailPatternObserver_V2<UNIQUE_TAKTMASTER_PATTERNOBSERVER>"))
        return static_cast< SelecteddetailPatternObserver_V2<UNIQUE_TAKTMASTER_PATTERNOBSERVER>*>(const_cast< Taktmaster*>(this));
    if (!strcmp(_clname, "RelativeTaktObserver_V2<UNIQUE_TAKTMASTER_TAKTOBSERVER>"))
        return static_cast< RelativeTaktObserver_V2<UNIQUE_TAKTMASTER_TAKTOBSERVER>*>(const_cast< Taktmaster*>(this));
    if (!strcmp(_clname, "SelecteddetailSequencerObserver_V2"))
        return static_cast< SelecteddetailSequencerObserver_V2*>(const_cast< Taktmaster*>(this));
    typedef extendQt::DRAGnDROP_QWidget QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int dc_gui::Taktmaster::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef extendQt::DRAGnDROP_QWidget QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
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
