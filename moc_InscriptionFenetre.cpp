/****************************************************************************
** Meta object code from reading C++ file 'InscriptionFenetre.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "Interface/Interface_graphique/headers/InscriptionFenetre.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'InscriptionFenetre.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InscriptionFenetre_t {
    QByteArrayData data[12];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InscriptionFenetre_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InscriptionFenetre_t qt_meta_stringdata_InscriptionFenetre = {
    {
QT_MOC_LITERAL(0, 0, 18), // "InscriptionFenetre"
QT_MOC_LITERAL(1, 19, 19), // "inscriptionDemandee"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 3), // "nom"
QT_MOC_LITERAL(4, 44, 6), // "prenom"
QT_MOC_LITERAL(5, 51, 5), // "email"
QT_MOC_LITERAL(6, 57, 10), // "motDePasse"
QT_MOC_LITERAL(7, 68, 14), // "adressePostale"
QT_MOC_LITERAL(8, 83, 6), // "fumeur"
QT_MOC_LITERAL(9, 90, 15), // "retourConnexion"
QT_MOC_LITERAL(10, 106, 20), // "onInscriptionClicked"
QT_MOC_LITERAL(11, 127, 23) // "onRetourConnexionClique"

    },
    "InscriptionFenetre\0inscriptionDemandee\0"
    "\0nom\0prenom\0email\0motDePasse\0"
    "adressePostale\0fumeur\0retourConnexion\0"
    "onInscriptionClicked\0onRetourConnexionClique"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InscriptionFenetre[] = {

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
       1,    6,   34,    2, 0x06 /* Public */,
       9,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   48,    2, 0x08 /* Private */,
      11,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool,    3,    4,    5,    6,    7,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void InscriptionFenetre::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InscriptionFenetre *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->inscriptionDemandee((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6]))); break;
        case 1: _t->retourConnexion(); break;
        case 2: _t->onInscriptionClicked(); break;
        case 3: _t->onRetourConnexionClique(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (InscriptionFenetre::*)(QString , QString , QString , QString , QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InscriptionFenetre::inscriptionDemandee)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (InscriptionFenetre::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InscriptionFenetre::retourConnexion)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject InscriptionFenetre::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_InscriptionFenetre.data,
    qt_meta_data_InscriptionFenetre,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *InscriptionFenetre::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InscriptionFenetre::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InscriptionFenetre.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int InscriptionFenetre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void InscriptionFenetre::inscriptionDemandee(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5, bool _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void InscriptionFenetre::retourConnexion()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
