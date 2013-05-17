/****************************************************************************
** Meta object code from reading C++ file 'dc_gui_tuneslidereditor.2moc.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dc_gui_tuneslidereditor.2moc.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dc_gui_tuneslidereditor.2moc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dc_gui__Tuneslider[] = {

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
      28,   20,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dc_gui__Tuneslider[] = {
    "dc_gui::Tuneslider\0\0value__\0"
    "on_hs_slider_valueChanged(int)\0"
};

void dc_gui::Tuneslider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Tuneslider *_t = static_cast<Tuneslider *>(_o);
        switch (_id) {
        case 0: _t->on_hs_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData dc_gui::Tuneslider::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dc_gui::Tuneslider::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_dc_gui__Tuneslider,
      qt_meta_data_dc_gui__Tuneslider, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dc_gui::Tuneslider::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dc_gui::Tuneslider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dc_gui::Tuneslider::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dc_gui__Tuneslider))
        return static_cast<void*>(const_cast< Tuneslider*>(this));
    if (!strcmp(_clname, "Ui::Tuneslider"))
        return static_cast< Ui::Tuneslider*>(const_cast< Tuneslider*>(this));
    if (!strcmp(_clname, "Events_blockable"))
        return static_cast< Events_blockable*>(const_cast< Tuneslider*>(this));
    if (!strcmp(_clname, "SelectedPatternObserver_V2"))
        return static_cast< SelectedPatternObserver_V2*>(const_cast< Tuneslider*>(this));
    if (!strcmp(_clname, "RelativePatternsaiteObserver_V2<Tuneslider>"))
        return static_cast< RelativePatternsaiteObserver_V2<Tuneslider>*>(const_cast< Tuneslider*>(this));
    return QWidget::qt_metacast(_clname);
}

int dc_gui::Tuneslider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
static const uint qt_meta_data_dc_gui__Tuneslidereditor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   25,   25,   25, 0x08,
      53,   25,   25,   25, 0x08,
      87,   78,   25,   25, 0x08,
     121,   25,   25,   25, 0x08,
     149,   25,   25,   25, 0x08,
     177,   25,   25,   25, 0x08,
     202,   25,   25,   25, 0x08,
     227,   25,   25,   25, 0x08,
     252,   25,   25,   25, 0x08,
     277,   25,   25,   25, 0x08,
     302,   25,   25,   25, 0x08,
     327,   25,   25,   25, 0x08,
     352,   25,   25,   25, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dc_gui__Tuneslidereditor[] = {
    "dc_gui::Tuneslidereditor\0\0"
    "on_pb_viewAccord_clicked()\0"
    "on_pb_viewTune_clicked()\0offset__\0"
    "on_hs_transpose_valueChanged(int)\0"
    "on_pb_defaultTune_clicked()\0"
    "on_pb_defaultDrum_clicked()\0"
    "on_pb_accord_0_clicked()\0"
    "on_pb_accord_1_clicked()\0"
    "on_pb_accord_2_clicked()\0"
    "on_pb_accord_3_clicked()\0"
    "on_pb_accord_4_clicked()\0"
    "on_pb_accord_5_clicked()\0"
    "on_pb_accord_6_clicked()\0"
    "on_pb_accord_7_clicked()\0"
};

void dc_gui::Tuneslidereditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Tuneslidereditor *_t = static_cast<Tuneslidereditor *>(_o);
        switch (_id) {
        case 0: _t->on_pb_viewAccord_clicked(); break;
        case 1: _t->on_pb_viewTune_clicked(); break;
        case 2: _t->on_hs_transpose_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pb_defaultTune_clicked(); break;
        case 4: _t->on_pb_defaultDrum_clicked(); break;
        case 5: _t->on_pb_accord_0_clicked(); break;
        case 6: _t->on_pb_accord_1_clicked(); break;
        case 7: _t->on_pb_accord_2_clicked(); break;
        case 8: _t->on_pb_accord_3_clicked(); break;
        case 9: _t->on_pb_accord_4_clicked(); break;
        case 10: _t->on_pb_accord_5_clicked(); break;
        case 11: _t->on_pb_accord_6_clicked(); break;
        case 12: _t->on_pb_accord_7_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData dc_gui::Tuneslidereditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dc_gui::Tuneslidereditor::staticMetaObject = {
    { &extendQt::DRAGnDROP_QWidget::staticMetaObject, qt_meta_stringdata_dc_gui__Tuneslidereditor,
      qt_meta_data_dc_gui__Tuneslidereditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dc_gui::Tuneslidereditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dc_gui::Tuneslidereditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dc_gui::Tuneslidereditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dc_gui__Tuneslidereditor))
        return static_cast<void*>(const_cast< Tuneslidereditor*>(this));
    if (!strcmp(_clname, "Ui::Tuneslidereditor"))
        return static_cast< Ui::Tuneslidereditor*>(const_cast< Tuneslidereditor*>(this));
    if (!strcmp(_clname, "Events_blockable"))
        return static_cast< Events_blockable*>(const_cast< Tuneslidereditor*>(this));
    if (!strcmp(_clname, "SelectedPatternObserver_V2"))
        return static_cast< SelectedPatternObserver_V2*>(const_cast< Tuneslidereditor*>(this));
    typedef extendQt::DRAGnDROP_QWidget QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int dc_gui::Tuneslidereditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef extendQt::DRAGnDROP_QWidget QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
static const uint qt_meta_data_dc_gui__Tunevaluebox[] = {

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
      22,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dc_gui__Tunevaluebox[] = {
    "dc_gui::Tunevaluebox\0\0on_pb_clicked()\0"
};

void dc_gui::Tunevaluebox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Tunevaluebox *_t = static_cast<Tunevaluebox *>(_o);
        switch (_id) {
        case 0: _t->on_pb_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData dc_gui::Tunevaluebox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dc_gui::Tunevaluebox::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_dc_gui__Tunevaluebox,
      qt_meta_data_dc_gui__Tunevaluebox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dc_gui::Tunevaluebox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dc_gui::Tunevaluebox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dc_gui::Tunevaluebox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dc_gui__Tunevaluebox))
        return static_cast<void*>(const_cast< Tunevaluebox*>(this));
    if (!strcmp(_clname, "Ui::Tunevaluebox"))
        return static_cast< Ui::Tunevaluebox*>(const_cast< Tunevaluebox*>(this));
    if (!strcmp(_clname, "RelativePatternsaiteObserver_V2_Tunevaluebox"))
        return static_cast< RelativePatternsaiteObserver_V2_Tunevaluebox*>(const_cast< Tunevaluebox*>(this));
    if (!strcmp(_clname, "SelecteddetailPatternObserver_V2_Tunevaluebox"))
        return static_cast< SelecteddetailPatternObserver_V2_Tunevaluebox*>(const_cast< Tunevaluebox*>(this));
    return QWidget::qt_metacast(_clname);
}

int dc_gui::Tunevaluebox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
