/****************************************************************************
** Meta object code from reading C++ file 'DetailTrajetReservationFenetre.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "Interface/Interface_graphique/headers/DetailTrajetReservationFenetre.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DetailTrajetReservationFenetre.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DetailTrajetReservationFenetre_t {
    QByteArrayData data[7];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DetailTrajetReservationFenetre_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DetailTrajetReservationFenetre_t qt_meta_stringdata_DetailTrajetReservationFenetre = {
    {
QT_MOC_LITERAL(0, 0, 30), // "DetailTrajetReservationFenetre"
QT_MOC_LITERAL(1, 31, 13), // "trajetReserve"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 6), // "Trajet"
QT_MOC_LITERAL(4, 53, 16), // "fermetureFenetre"
QT_MOC_LITERAL(5, 70, 15), // "onRetourClicked"
QT_MOC_LITERAL(6, 86, 17) // "onReserverClicked"

    },
    "DetailTrajetReservationFenetre\0"
    "trajetReserve\0\0Trajet\0fermetureFenetre\0"
    "onRetourClicked\0onReserverClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DetailTrajetReservationFenetre[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    0,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   38,    2, 0x08 /* Private */,
       6,    0,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DetailTrajetReservationFenetre::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DetailTrajetReservationFenetre *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->trajetReserve((*reinterpret_cast< const Trajet(*)>(_a[1]))); break;
        case 1: _t->fermetureFenetre(); break;
        case 2: _t->onRetourClicked(); break;
        case 3: _t->onReserverClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DetailTrajetReservationFenetre::*)(const Trajet & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DetailTrajetReservationFenetre::trajetReserve)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DetailTrajetReservationFenetre::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DetailTrajetReservationFenetre::fermetureFenetre)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DetailTrajetReservationFenetre::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_DetailTrajetReservationFenetre.data,
    qt_meta_data_DetailTrajetReservationFenetre,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DetailTrajetReservationFenetre::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DetailTrajetReservationFenetre::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DetailTrajetReservationFenetre.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DetailTrajetReservationFenetre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void DetailTrajetReservationFenetre::trajetReserve(const Trajet & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DetailTrajetReservationFenetre::fermetureFenetre()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
