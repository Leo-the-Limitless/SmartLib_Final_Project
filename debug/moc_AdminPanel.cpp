/****************************************************************************
** Meta object code from reading C++ file 'AdminPanel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AdminPanel.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AdminPanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10AdminPanelE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10AdminPanelE = QtMocHelpers::stringData(
    "AdminPanel",
    "onActionLogOutClicked",
    "",
    "onActionExitClicked",
    "onActionRefreshClicked",
    "onActionAddBookClicked",
    "onActionEditBookClicked",
    "onActionDeleteBookClicked",
    "onBookSelectionChanged",
    "searchBooks",
    "loadBooks",
    "setupAnalysisChart",
    "availableCount",
    "borrowedCount",
    "totalCount",
    "overdueCount",
    "loadBorrowedBooks",
    "onTabChanged",
    "index"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10AdminPanelE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x08,    1 /* Private */,
       3,    0,   87,    2, 0x08,    2 /* Private */,
       4,    0,   88,    2, 0x08,    3 /* Private */,
       5,    0,   89,    2, 0x08,    4 /* Private */,
       6,    0,   90,    2, 0x08,    5 /* Private */,
       7,    0,   91,    2, 0x08,    6 /* Private */,
       8,    0,   92,    2, 0x08,    7 /* Private */,
       9,    0,   93,    2, 0x08,    8 /* Private */,
      10,    0,   94,    2, 0x08,    9 /* Private */,
      11,    4,   95,    2, 0x08,   10 /* Private */,
      16,    0,  104,    2, 0x08,   15 /* Private */,
      17,    1,  105,    2, 0x08,   16 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   12,   13,   14,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

Q_CONSTINIT const QMetaObject AdminPanel::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ZN10AdminPanelE.offsetsAndSizes,
    qt_meta_data_ZN10AdminPanelE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN10AdminPanelE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AdminPanel, std::true_type>,
        // method 'onActionLogOutClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onActionExitClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onActionRefreshClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onActionAddBookClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onActionEditBookClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onActionDeleteBookClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onBookSelectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'searchBooks'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadBooks'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setupAnalysisChart'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'loadBorrowedBooks'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTabChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void AdminPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<AdminPanel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->onActionLogOutClicked(); break;
        case 1: _t->onActionExitClicked(); break;
        case 2: _t->onActionRefreshClicked(); break;
        case 3: _t->onActionAddBookClicked(); break;
        case 4: _t->onActionEditBookClicked(); break;
        case 5: _t->onActionDeleteBookClicked(); break;
        case 6: _t->onBookSelectionChanged(); break;
        case 7: _t->searchBooks(); break;
        case 8: _t->loadBooks(); break;
        case 9: _t->setupAnalysisChart((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 10: _t->loadBorrowedBooks(); break;
        case 11: _t->onTabChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *AdminPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN10AdminPanelE.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int AdminPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
