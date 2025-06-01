/****************************************************************************
** Meta object code from reading C++ file 'MesAnnoncesFenetre.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "Interface/Interface_graphique/headers/MesAnnoncesFenetre.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MesAnnoncesFenetre.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MesAnnoncesFenetre_t {
    QByteArrayData data[12];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MesAnnoncesFenetre_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MesAnnoncesFenetre_t qt_meta_stringdata_MesAnnoncesFenetre = {
    {
QT_MOC_LITERAL(0, 0, 18), // "MesAnnoncesFenetre"
QT_MOC_LITERAL(1, 19, 19), // "annonceSelectionnee"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 6), // "Trajet"
QT_MOC_LITERAL(4, 47, 6), // "trajet"
QT_MOC_LITERAL(5, 54, 13), // "retourAccueil"
QT_MOC_LITERAL(6, 68, 18), // "demandeSuppression"
QT_MOC_LITERAL(7, 87, 8), // "idTrajet"
QT_MOC_LITERAL(8, 96, 16), // "onAnnonceCliquee"
QT_MOC_LITERAL(9, 113, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(10, 130, 4), // "item"
QT_MOC_LITERAL(11, 135, 16) // "onAccueilClicked"

    },
    "MesAnnoncesFenetre\0annonceSelectionnee\0"
    "\0Trajet\0trajet\0retourAccueil\0"
    "demandeSuppression\0idTrajet\0"
    "onAnnonceCliquee\0QListWidgetItem*\0"
    "item\0onAccueilClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MesAnnoncesFenetre[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    0,   42,    2, 0x06 /* Public */,
       6,    1,   43,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   46,    2, 0x08 /* Private */,
      11,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,

       0        // eod
};

void MesAnnoncesFenetre::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MesAnnoncesFenetre *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->annonceSelectionnee((*reinterpret_cast< const Trajet(*)>(_a[1]))); break;
        case 1: _t->retourAccueil(); break;
        case 2: _t->demandeSuppression((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onAnnonceCliquee((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->onAccueilClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MesAnnoncesFenetre::*)(const Trajet & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MesAnnoncesFenetre::annonceSelectionnee)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MesAnnoncesFenetre::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MesAnnoncesFenetre::retourAccueil)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MesAnnoncesFenetre::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MesAnnoncesFenetre::demandeSuppression)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MesAnnoncesFenetre::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MesAnnoncesFenetre.data,
    qt_meta_data_MesAnnoncesFenetre,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MesAnnoncesFenetre::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MesAnnoncesFenetre::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MesAnnoncesFenetre.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MesAnnoncesFenetre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MesAnnoncesFenetre::annonceSelectionnee(const Trajet & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MesAnnoncesFenetre::retourAccueil()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MesAnnoncesFenetre::demandeSuppression(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
