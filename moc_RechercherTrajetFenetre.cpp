/****************************************************************************
** Meta object code from reading C++ file 'RechercherTrajetFenetre.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "Interface/Interface_graphique/headers/RechercherTrajetFenetre.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RechercherTrajetFenetre.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RechercherTrajetFenetre_t {
    QByteArrayData data[20];
    char stringdata0[262];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RechercherTrajetFenetre_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RechercherTrajetFenetre_t qt_meta_stringdata_RechercherTrajetFenetre = {
    {
QT_MOC_LITERAL(0, 0, 23), // "RechercherTrajetFenetre"
QT_MOC_LITERAL(1, 24, 15), // "rechercheLancee"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 6), // "depart"
QT_MOC_LITERAL(4, 48, 7), // "arrivee"
QT_MOC_LITERAL(5, 56, 4), // "date"
QT_MOC_LITERAL(6, 61, 15), // "filtrageDemande"
QT_MOC_LITERAL(7, 77, 7), // "critere"
QT_MOC_LITERAL(8, 85, 12), // "trajetClique"
QT_MOC_LITERAL(9, 98, 6), // "Trajet"
QT_MOC_LITERAL(10, 105, 13), // "retourAccueil"
QT_MOC_LITERAL(11, 119, 17), // "afficherResultats"
QT_MOC_LITERAL(12, 137, 19), // "std::vector<Trajet>"
QT_MOC_LITERAL(13, 157, 9), // "resultats"
QT_MOC_LITERAL(14, 167, 18), // "onRechercheClicked"
QT_MOC_LITERAL(15, 186, 16), // "onFiltrerClicked"
QT_MOC_LITERAL(16, 203, 19), // "onTrajetSelectionne"
QT_MOC_LITERAL(17, 223, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(18, 240, 4), // "item"
QT_MOC_LITERAL(19, 245, 16) // "onAccueilClicked"

    },
    "RechercherTrajetFenetre\0rechercheLancee\0"
    "\0depart\0arrivee\0date\0filtrageDemande\0"
    "critere\0trajetClique\0Trajet\0retourAccueil\0"
    "afficherResultats\0std::vector<Trajet>\0"
    "resultats\0onRechercheClicked\0"
    "onFiltrerClicked\0onTrajetSelectionne\0"
    "QListWidgetItem*\0item\0onAccueilClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RechercherTrajetFenetre[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   59,    2, 0x06 /* Public */,
       6,    1,   66,    2, 0x06 /* Public */,
       8,    1,   69,    2, 0x06 /* Public */,
      10,    0,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   73,    2, 0x0a /* Public */,
      14,    0,   76,    2, 0x08 /* Private */,
      15,    0,   77,    2, 0x08 /* Private */,
      16,    1,   78,    2, 0x08 /* Private */,
      19,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void,

       0        // eod
};

void RechercherTrajetFenetre::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RechercherTrajetFenetre *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->rechercheLancee((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->filtrageDemande((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->trajetClique((*reinterpret_cast< const Trajet(*)>(_a[1]))); break;
        case 3: _t->retourAccueil(); break;
        case 4: _t->afficherResultats((*reinterpret_cast< const std::vector<Trajet>(*)>(_a[1]))); break;
        case 5: _t->onRechercheClicked(); break;
        case 6: _t->onFiltrerClicked(); break;
        case 7: _t->onTrajetSelectionne((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->onAccueilClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RechercherTrajetFenetre::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RechercherTrajetFenetre::rechercheLancee)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RechercherTrajetFenetre::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RechercherTrajetFenetre::filtrageDemande)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RechercherTrajetFenetre::*)(const Trajet & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RechercherTrajetFenetre::trajetClique)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (RechercherTrajetFenetre::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RechercherTrajetFenetre::retourAccueil)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RechercherTrajetFenetre::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_RechercherTrajetFenetre.data,
    qt_meta_data_RechercherTrajetFenetre,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RechercherTrajetFenetre::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RechercherTrajetFenetre::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RechercherTrajetFenetre.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RechercherTrajetFenetre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void RechercherTrajetFenetre::rechercheLancee(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RechercherTrajetFenetre::filtrageDemande(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RechercherTrajetFenetre::trajetClique(const Trajet & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RechercherTrajetFenetre::retourAccueil()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
