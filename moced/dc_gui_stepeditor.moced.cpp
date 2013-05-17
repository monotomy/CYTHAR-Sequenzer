/****************************************************************************
** Meta object code from reading C++ file 'dc_gui_stepeditor.2moc.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dc_gui_stepeditor.2moc.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dc_gui_stepeditor.2moc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dc_gui__Stepeditor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      57,   19,   19,   19, 0x08,
      92,   19,   19,   19, 0x08,
     135,   19,   19,   19, 0x08,
     175,   19,   19,   19, 0x08,
     215,   19,   19,   19, 0x08,
     255,   19,   19,   19, 0x08,
     295,   19,   19,   19, 0x08,
     328,   19,   19,   19, 0x08,
     361,   19,   19,   19, 0x08,
     394,   19,   19,   19, 0x08,
     427,   19,   19,   19, 0x08,
     447,   19,   19,   19, 0x08,
     467,   19,   19,   19, 0x08,
     487,   19,   19,   19, 0x08,
     507,   19,   19,   19, 0x08,
     527,   19,   19,   19, 0x08,
     548,   19,   19,   19, 0x08,
     569,   19,   19,   19, 0x08,
     590,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dc_gui__Stepeditor[] = {
    "dc_gui::Stepeditor\0\0"
    "on_slider_velocity_valueChanged(int)\0"
    "on_slider_length_valueChanged(int)\0"
    "on_input_inc_fulllengths_valueChanged(int)\0"
    "on_pb_preset_double_pointed_0_clicked()\0"
    "on_pb_preset_double_pointed_1_clicked()\0"
    "on_pb_preset_double_pointed_2_clicked()\0"
    "on_pb_preset_double_pointed_3_clicked()\0"
    "on_pb_preset_triplet_0_clicked()\0"
    "on_pb_preset_triplet_1_clicked()\0"
    "on_pb_preset_triplet_2_clicked()\0"
    "on_pb_preset_triplet_3_clicked()\0"
    "on_pb_4_4_clicked()\0on_pb_3_4_clicked()\0"
    "on_pb_2_4_clicked()\0on_pb_1_4_clicked()\0"
    "on_pb_1_8_clicked()\0on_pb_1_16_clicked()\0"
    "on_pb_1_32_clicked()\0on_pb_1_96_clicked()\0"
    "on_pb_2_96_clicked()\0"
};

void dc_gui::Stepeditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Stepeditor *_t = static_cast<Stepeditor *>(_o);
        switch (_id) {
        case 0: _t->on_slider_velocity_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_slider_length_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_input_inc_fulllengths_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pb_preset_double_pointed_0_clicked(); break;
        case 4: _t->on_pb_preset_double_pointed_1_clicked(); break;
        case 5: _t->on_pb_preset_double_pointed_2_clicked(); break;
        case 6: _t->on_pb_preset_double_pointed_3_clicked(); break;
        case 7: _t->on_pb_preset_triplet_0_clicked(); break;
        case 8: _t->on_pb_preset_triplet_1_clicked(); break;
        case 9: _t->on_pb_preset_triplet_2_clicked(); break;
        case 10: _t->on_pb_preset_triplet_3_clicked(); break;
        case 11: _t->on_pb_4_4_clicked(); break;
        case 12: _t->on_pb_3_4_clicked(); break;
        case 13: _t->on_pb_2_4_clicked(); break;
        case 14: _t->on_pb_1_4_clicked(); break;
        case 15: _t->on_pb_1_8_clicked(); break;
        case 16: _t->on_pb_1_16_clicked(); break;
        case 17: _t->on_pb_1_32_clicked(); break;
        case 18: _t->on_pb_1_96_clicked(); break;
        case 19: _t->on_pb_2_96_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData dc_gui::Stepeditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dc_gui::Stepeditor::staticMetaObject = {
    { &extendQt::DRAGnDROP_QWidget::staticMetaObject, qt_meta_stringdata_dc_gui__Stepeditor,
      qt_meta_data_dc_gui__Stepeditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dc_gui::Stepeditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dc_gui::Stepeditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dc_gui::Stepeditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dc_gui__Stepeditor))
        return static_cast<void*>(const_cast< Stepeditor*>(this));
    if (!strcmp(_clname, "Ui::Stepeditor"))
        return static_cast< Ui::Stepeditor*>(const_cast< Stepeditor*>(this));
    if (!strcmp(_clname, "Events_blockable"))
        return static_cast< Events_blockable*>(const_cast< Stepeditor*>(this));
    if (!strcmp(_clname, "SelecteddetailStepObserver_V2"))
        return static_cast< SelecteddetailStepObserver_V2*>(const_cast< Stepeditor*>(this));
    typedef extendQt::DRAGnDROP_QWidget QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int dc_gui::Stepeditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef extendQt::DRAGnDROP_QWidget QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
