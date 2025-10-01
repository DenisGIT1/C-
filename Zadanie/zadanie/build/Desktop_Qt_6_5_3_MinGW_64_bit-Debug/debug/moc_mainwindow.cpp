/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "loadSettings",
    "",
    "saveSettings",
    "stopAllProcessors",
    "startProcessing",
    "stopProcessing",
    "selectOutputPath",
    "selectInputPath",
    "on_timerTimeout",
    "processFile",
    "filePath",
    "updateProgress",
    "FileProcessor*",
    "processor",
    "processedBytes",
    "onProcessingFinished",
    "message"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[36];
    char stringdata0[11];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[18];
    char stringdata5[16];
    char stringdata6[15];
    char stringdata7[17];
    char stringdata8[16];
    char stringdata9[16];
    char stringdata10[12];
    char stringdata11[9];
    char stringdata12[15];
    char stringdata13[15];
    char stringdata14[10];
    char stringdata15[15];
    char stringdata16[21];
    char stringdata17[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 12),  // "loadSettings"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 12),  // "saveSettings"
        QT_MOC_LITERAL(38, 17),  // "stopAllProcessors"
        QT_MOC_LITERAL(56, 15),  // "startProcessing"
        QT_MOC_LITERAL(72, 14),  // "stopProcessing"
        QT_MOC_LITERAL(87, 16),  // "selectOutputPath"
        QT_MOC_LITERAL(104, 15),  // "selectInputPath"
        QT_MOC_LITERAL(120, 15),  // "on_timerTimeout"
        QT_MOC_LITERAL(136, 11),  // "processFile"
        QT_MOC_LITERAL(148, 8),  // "filePath"
        QT_MOC_LITERAL(157, 14),  // "updateProgress"
        QT_MOC_LITERAL(172, 14),  // "FileProcessor*"
        QT_MOC_LITERAL(187, 9),  // "processor"
        QT_MOC_LITERAL(197, 14),  // "processedBytes"
        QT_MOC_LITERAL(212, 20),  // "onProcessingFinished"
        QT_MOC_LITERAL(233, 7)   // "message"
    },
    "MainWindow",
    "loadSettings",
    "",
    "saveSettings",
    "stopAllProcessors",
    "startProcessing",
    "stopProcessing",
    "selectOutputPath",
    "selectInputPath",
    "on_timerTimeout",
    "processFile",
    "filePath",
    "updateProgress",
    "FileProcessor*",
    "processor",
    "processedBytes",
    "onProcessingFinished",
    "message"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    0,   81,    2, 0x08,    2 /* Private */,
       4,    0,   82,    2, 0x08,    3 /* Private */,
       5,    0,   83,    2, 0x08,    4 /* Private */,
       6,    0,   84,    2, 0x08,    5 /* Private */,
       7,    0,   85,    2, 0x08,    6 /* Private */,
       8,    0,   86,    2, 0x08,    7 /* Private */,
       9,    0,   87,    2, 0x08,    8 /* Private */,
      10,    1,   88,    2, 0x08,    9 /* Private */,
      12,    2,   91,    2, 0x08,   11 /* Private */,
      16,    2,   96,    2, 0x08,   14 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, 0x80000000 | 13, QMetaType::LongLong,   14,   15,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QString,   14,   17,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'loadSettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveSettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopAllProcessors'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startProcessing'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopProcessing'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'selectOutputPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'selectInputPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_timerTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'processFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'updateProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<FileProcessor *, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'onProcessingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<FileProcessor *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loadSettings(); break;
        case 1: _t->saveSettings(); break;
        case 2: _t->stopAllProcessors(); break;
        case 3: _t->startProcessing(); break;
        case 4: _t->stopProcessing(); break;
        case 5: _t->selectOutputPath(); break;
        case 6: _t->selectInputPath(); break;
        case 7: _t->on_timerTimeout(); break;
        case 8: _t->processFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->updateProgress((*reinterpret_cast< std::add_pointer_t<FileProcessor*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2]))); break;
        case 10: _t->onProcessingFinished((*reinterpret_cast< std::add_pointer_t<FileProcessor*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FileProcessor* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FileProcessor* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
