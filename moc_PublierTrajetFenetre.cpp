/****************************************************************************
** Meta object code from reading C++ file 'PublierTrajetFenetre.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "Interface/Interface_graphique/headers/PublierTrajetFenetre.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PublierTrajetFenetre.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PublierTrajetFenetre_t {
    QByteArrayData data[20];
    char stringdata0[225];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PublierTrajetFenetre_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PublierTrajetFenetre_t qt_meta_stringdata_PublierTrajetFenetre = {
    {
QT_MOC_LITERAL(0, 0, 20), // "PublierTrajetFenetre"
QT_MOC_LITERAL(1, 21, 12), // "trajetSoumis"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 4), // "date"
QT_MOC_LITERAL(4, 40, 11), // "heureDepart"
QT_MOC_LITERAL(5, 52, 12), // "heureArrivee"
QT_MOC_LITERAL(6, 65, 10), // "lieuDepart"
QT_MOC_LITERAL(7, 76, 11), // "lieuArrivee"
QT_MOC_LITERAL(8, 88, 4), // "prix"
QT_MOC_LITERAL(9, 93, 8), // "distance"
QT_MOC_LITERAL(10, 102, 7), // "voiture"
QT_MOC_LITERAL(11, 110, 12), // "nombrePlaces"
QT_MOC_LITERAL(12, 123, 12), // "consommation"
QT_MOC_LITERAL(13, 136, 10), // "anciennete"
QT_MOC_LITERAL(14, 147, 9), // "carburant"
QT_MOC_LITERAL(15, 157, 11), // "description"
QT_MOC_LITERAL(16, 169, 7), // "animaux"
QT_MOC_LITERAL(17, 177, 13), // "retourAccueil"
QT_MOC_LITERAL(18, 191, 16), // "onPublierClicked"
QT_MOC_LITERAL(19, 208, 16) // "onAccueilClicked"

    },
    "PublierTrajetFenetre\0trajetSoumis\0\0"
    "date\0heureDepart\0heureArrivee\0lieuDepart\0"
    "lieuArrivee\0prix\0distance\0voiture\0"
    "nombrePlaces\0consommation\0anciennete\0"
    "carburant\0description\0animaux\0"
    "retourAccueil\0onPublierClicked\0"
    "onAccueilClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PublierTrajetFenetre[] = {

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
       1,   14,   34,    2, 0x06 /* Public */,
      17,    0,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    0,   64,    2, 0x08 /* Private */,
      19,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Float, QMetaType::Float, QMetaType::QString, QMetaType::Int, QMetaType::Float, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Bool,    3,    4,    5,    6,    7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PublierTrajetFenetre::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PublierTrajetFenetre *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->trajetSoumis((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< float(*)>(_a[6])),(*reinterpret_cast< float(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< float(*)>(_a[10])),(*reinterpret_cast< int(*)>(_a[11])),(*reinterpret_cast< const QString(*)>(_a[12])),(*reinterpret_cast< const QString(*)>(_a[13])),(*reinterpret_cast< bool(*)>(_a[14]))); break;
        case 1: _t->retourAccueil(); break;
        case 2: _t->onPublierClicked(); break;
        case 3: _t->onAccueilClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PublierTrajetFenetre::*)(const QString & , const QString & , const QString & , const QString & , const QString & , float , float , const QString & , int , float , int , const QString & , const QString & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PublierTrajetFenetre::trajetSoumis)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PublierTrajetFenetre::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PublierTrajetFenetre::retourAccueil)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PublierTrajetFenetre::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_PublierTrajetFenetre.data,
    qt_meta_data_PublierTrajetFenetre,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PublierTrajetFenetre::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PublierTrajetFenetre::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PublierTrajetFenetre.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PublierTrajetFenetre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void PublierTrajetFenetre::trajetSoumis(const QString & _t1, const QString & _t2, const QString & _t3, const QString & _t4, const QString & _t5, float _t6, float _t7, const QString & _t8, int _t9, float _t10, int _t11, const QString & _t12, const QString & _t13, bool _t14)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t10))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t11))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t12))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t13))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t14))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PublierTrajetFenetre::retourAccueil()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
