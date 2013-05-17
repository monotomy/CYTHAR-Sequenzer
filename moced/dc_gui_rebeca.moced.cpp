/****************************************************************************
** Meta object code from reading C++ file 'dc_gui_rebeca.2moc.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dc_gui_rebeca.2moc.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dc_gui_rebeca.2moc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dc_gui__Rebeca[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      49,   15,   15,   15, 0x08,
      83,   15,   15,   15, 0x08,
     120,   15,   15,   15, 0x08,
     170,   15,   15,   15, 0x08,
     215,   15,   15,   15, 0x08,
     274,   15,   15,   15, 0x08,
     323,   15,   15,   15, 0x08,
     367,   15,   15,   15, 0x08,
     440,   15,   15,   15, 0x08,
     467,   15,   15,   15, 0x08,
     496,   15,   15,   15, 0x08,
     521,   15,   15,   15, 0x08,
     550,   15,   15,   15, 0x08,
     586,   15,   15,   15, 0x08,
     622,   15,   15,   15, 0x08,
     649,   15,   15,   15, 0x08,
     676,   15,   15,   15, 0x08,
     712,   15,   15,   15, 0x08,
     748,   15,   15,   15, 0x08,
     782,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dc_gui__Rebeca[] = {
    "dc_gui::Rebeca\0\0on_input_delay_valueChanged(int)\0"
    "on_input_repeat_valueChanged(int)\0"
    "on_input_intervall_valueChanged(int)\0"
    "on_cb_intervall_operator_currentIndexChanged(int)\0"
    "on_input_intervall_operand_valueChanged(int)\0"
    "on_cb_intervall2original_operator_currentIndexChanged(int)\0"
    "on_cb_original_operator_currentIndexChanged(int)\0"
    "on_input_original_operand_valueChanged(int)\0"
    "on_cb_intervall_original_result2repeat_operator_currentIndexChanged(in"
    "t)\0"
    "on_pb_tab_length_clicked()\0"
    "on_pb_tab_velocity_clicked()\0"
    "on_pb_tab_note_clicked()\0"
    "on_pb_fir_to_range_clicked()\0"
    "on_pb_preset_inc_interval_clicked()\0"
    "on_pb_preset_dec_interval_clicked()\0"
    "on_pb_preset_dur_clicked()\0"
    "on_pb_preset_mol_clicked()\0"
    "on_pb_preset_inc_velocity_clicked()\0"
    "on_pb_preset_dec_velocity_clicked()\0"
    "on_pb_preset_inc_length_clicked()\0"
    "on_pb_preset_dec_length_clicked()\0"
};

void dc_gui::Rebeca::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Rebeca *_t = static_cast<Rebeca *>(_o);
        switch (_id) {
        case 0: _t->on_input_delay_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_input_repeat_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_input_intervall_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_cb_intervall_operator_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_input_intervall_operand_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_cb_intervall2original_operator_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_cb_original_operator_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_input_original_operand_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_cb_intervall_original_result2repeat_operator_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_pb_tab_length_clicked(); break;
        case 10: _t->on_pb_tab_velocity_clicked(); break;
        case 11: _t->on_pb_tab_note_clicked(); break;
        case 12: _t->on_pb_fir_to_range_clicked(); break;
        case 13: _t->on_pb_preset_inc_interval_clicked(); break;
        case 14: _t->on_pb_preset_dec_interval_clicked(); break;
        case 15: _t->on_pb_preset_dur_clicked(); break;
        case 16: _t->on_pb_preset_mol_clicked(); break;
        case 17: _t->on_pb_preset_inc_velocity_clicked(); break;
        case 18: _t->on_pb_preset_dec_velocity_clicked(); break;
        case 19: _t->on_pb_preset_inc_length_clicked(); break;
        case 20: _t->on_pb_preset_dec_length_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData dc_gui::Rebeca::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dc_gui::Rebeca::staticMetaObject = {
    { &extendQt::DRAGnDROP_QWidget::staticMetaObject, qt_meta_stringdata_dc_gui__Rebeca,
      qt_meta_data_dc_gui__Rebeca, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dc_gui::Rebeca::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dc_gui::Rebeca::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dc_gui::Rebeca::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dc_gui__Rebeca))
        return static_cast<void*>(const_cast< Rebeca*>(this));
    if (!strcmp(_clname, "Ui::Rebeca"))
        return static_cast< Ui::Rebeca*>(const_cast< Rebeca*>(this));
    if (!strcmp(_clname, "Events_blockable"))
        return static_cast< Events_blockable*>(const_cast< Rebeca*>(this));
    if (!strcmp(_clname, "SelecteddetailStepObserver_V2"))
        return static_cast< SelecteddetailStepObserver_V2*>(const_cast< Rebeca*>(this));
    typedef extendQt::DRAGnDROP_QWidget QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int dc_gui::Rebeca::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef extendQt::DRAGnDROP_QWidget QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
