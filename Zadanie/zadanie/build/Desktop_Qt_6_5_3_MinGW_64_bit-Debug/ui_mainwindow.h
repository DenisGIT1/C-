/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_input;
    QLineEdit *inputPathEdit;
    QPushButton *selectInputPathButton;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_output;
    QLineEdit *outputPathEdit;
    QPushButton *selectOutputPathButton;
    QLabel *label_3;
    QLineEdit *maskEdit;
    QLabel *label_4;
    QLineEdit *xorValueEdit;
    QLabel *label_5;
    QComboBox *duplicateCombo;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_mode;
    QRadioButton *singleModeRadio;
    QRadioButton *timerModeRadio;
    QLabel *label_7;
    QSpinBox *periodSpin;
    QCheckBox *deleteInputCheck;
    QHBoxLayout *horizontalLayout_buttons;
    QPushButton *startButton;
    QPushButton *stopButton;
    QLabel *currentFileLabel;
    QVBoxLayout *verticalLayout_progress;
    QProgressBar *progressBar;
    QProgressBar *totalProgressBar;
    QLabel *statusLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        horizontalLayout_input = new QHBoxLayout();
        horizontalLayout_input->setObjectName("horizontalLayout_input");
        inputPathEdit = new QLineEdit(centralwidget);
        inputPathEdit->setObjectName("inputPathEdit");

        horizontalLayout_input->addWidget(inputPathEdit);

        selectInputPathButton = new QPushButton(centralwidget);
        selectInputPathButton->setObjectName("selectInputPathButton");

        horizontalLayout_input->addWidget(selectInputPathButton);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout_input);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        horizontalLayout_output = new QHBoxLayout();
        horizontalLayout_output->setObjectName("horizontalLayout_output");
        outputPathEdit = new QLineEdit(centralwidget);
        outputPathEdit->setObjectName("outputPathEdit");

        horizontalLayout_output->addWidget(outputPathEdit);

        selectOutputPathButton = new QPushButton(centralwidget);
        selectOutputPathButton->setObjectName("selectOutputPathButton");

        horizontalLayout_output->addWidget(selectOutputPathButton);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_output);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        maskEdit = new QLineEdit(centralwidget);
        maskEdit->setObjectName("maskEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, maskEdit);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        xorValueEdit = new QLineEdit(centralwidget);
        xorValueEdit->setObjectName("xorValueEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, xorValueEdit);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        duplicateCombo = new QComboBox(centralwidget);
        duplicateCombo->addItem(QString());
        duplicateCombo->addItem(QString());
        duplicateCombo->setObjectName("duplicateCombo");

        formLayout->setWidget(4, QFormLayout::FieldRole, duplicateCombo);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        horizontalLayout_mode = new QHBoxLayout();
        horizontalLayout_mode->setObjectName("horizontalLayout_mode");
        singleModeRadio = new QRadioButton(centralwidget);
        singleModeRadio->setObjectName("singleModeRadio");
        singleModeRadio->setChecked(true);

        horizontalLayout_mode->addWidget(singleModeRadio);

        timerModeRadio = new QRadioButton(centralwidget);
        timerModeRadio->setObjectName("timerModeRadio");

        horizontalLayout_mode->addWidget(timerModeRadio);


        formLayout->setLayout(5, QFormLayout::FieldRole, horizontalLayout_mode);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        periodSpin = new QSpinBox(centralwidget);
        periodSpin->setObjectName("periodSpin");
        periodSpin->setMinimum(1);
        periodSpin->setValue(1);

        formLayout->setWidget(6, QFormLayout::FieldRole, periodSpin);

        deleteInputCheck = new QCheckBox(centralwidget);
        deleteInputCheck->setObjectName("deleteInputCheck");

        formLayout->setWidget(7, QFormLayout::LabelRole, deleteInputCheck);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_buttons = new QHBoxLayout();
        horizontalLayout_buttons->setObjectName("horizontalLayout_buttons");
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");

        horizontalLayout_buttons->addWidget(startButton);

        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName("stopButton");
        stopButton->setEnabled(false);

        horizontalLayout_buttons->addWidget(stopButton);


        verticalLayout->addLayout(horizontalLayout_buttons);

        currentFileLabel = new QLabel(centralwidget);
        currentFileLabel->setObjectName("currentFileLabel");

        verticalLayout->addWidget(currentFileLabel);

        verticalLayout_progress = new QVBoxLayout();
        verticalLayout_progress->setObjectName("verticalLayout_progress");
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(0);

        verticalLayout_progress->addWidget(progressBar);

        totalProgressBar = new QProgressBar(centralwidget);
        totalProgressBar->setObjectName("totalProgressBar");
        totalProgressBar->setValue(0);

        verticalLayout_progress->addWidget(totalProgressBar);


        verticalLayout->addLayout(verticalLayout_progress);

        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");

        verticalLayout->addWidget(statusLabel);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "XOR File Processor", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264\320\275\320\260\321\217 \320\277\320\260\320\277\320\272\320\260:", nullptr));
        selectInputPathButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214...", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264\320\275\320\260\321\217 \320\277\320\260\320\277\320\272\320\260:", nullptr));
        selectOutputPathButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214...", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\320\272\320\260 \321\204\320\260\320\271\320\273\320\276\320\262:", nullptr));
        maskEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\277\321\200\320\270\320\274\320\265\321\200: *.txt,*.jpg", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "XOR \320\272\320\273\321\216\321\207 (hex, 16 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262):", nullptr));
        xorValueEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\277\321\200\320\270\320\274\320\265\321\200: 0102030405060708", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\224\320\265\320\271\321\201\321\202\320\262\320\270\320\265 \320\277\321\200\320\270 \320\264\321\203\320\261\320\273\320\270\320\272\320\260\321\202\320\260\321\205:", nullptr));
        duplicateCombo->setItemText(0, QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        duplicateCombo->setItemText(1, QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\207\320\265\321\202\321\207\320\270\320\272", nullptr));

        label_6->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274:", nullptr));
        singleModeRadio->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\276\320\262\321\213\320\271 \320\267\320\260\320\277\321\203\321\201\320\272", nullptr));
        timerModeRadio->setText(QCoreApplication::translate("MainWindow", "\320\242\320\260\320\271\320\274\320\265\321\200", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\270\320\276\320\264 \320\276\320\277\321\200\320\276\321\201\320\260 (\321\201\320\265\320\272):", nullptr));
        deleteInputCheck->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\205\320\276\320\264\320\275\321\213\320\265 \321\204\320\260\320\271\320\273\321\213 \320\277\320\276\321\201\320\273\320\265 \320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\270", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\276\320\277", nullptr));
        currentFileLabel->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \321\204\320\260\320\271\320\273: ", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "\320\223\320\276\321\202\320\276\320\262\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
