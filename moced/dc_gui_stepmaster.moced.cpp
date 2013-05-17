/****************************************************************************
** Meta object code from reading C++ file 'dc_gui_stepmaster.2moc.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dc_gui_stepmaster.2moc.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dc_gui_stepmaster.2moc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dc_gui__StepMaster[] = {

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
      20,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dc_gui__StepMaster[] = {
    "dc_gui::StepMaster\0\0set_running()\0"
};

void dc_gui::StepMaster::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StepMaster *_t = static_cast<StepMaster *>(_o);
        switch (_id) {
        case 0: _t->set_running(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData dc_gui::StepMaster::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dc_gui::StepMaster::staticMetaObject = {
    { &extendQt::DRAGnDROP_QWidget::staticMetaObject, qt_meta_stringdata_dc_gui__StepMaster,
      qt_meta_data_dc_gui__StepMaster, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dc_gui::StepMaster::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dc_gui::StepMaster::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dc_gui::StepMaster::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dc_gui__StepMaster))
        return static_cast<void*>(const_cast< StepMaster*>(this));
    if (!strcmp(_clname, "Ui::StepMaster"))
        return static_cast< Ui::StepMaster*>(const_cast< StepMaster*>(this));
    if (!strcmp(_clname, "SelecteddetailSequencerObserver_V2"))
        return static_cast< SelecteddetailSequencerObserver_V2*>(const_cast< StepMaster*>(this));
    typedef extendQt::DRAGnDROP_QWidget QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int dc_gui::StepMaster::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef extendQt::DRAGnDROP_QWidget QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
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
