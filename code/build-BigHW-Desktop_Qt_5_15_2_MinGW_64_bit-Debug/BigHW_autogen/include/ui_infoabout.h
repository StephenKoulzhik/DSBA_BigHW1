/********************************************************************************
** Form generated from reading UI file 'infoabout.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOABOUT_H
#define UI_INFOABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_infoabout
{
public:
    QFrame *frameLogo;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QDialog *infoabout)
    {
        if (infoabout->objectName().isEmpty())
            infoabout->setObjectName(QString::fromUtf8("infoabout"));
        infoabout->resize(600, 400);
        infoabout->setMinimumSize(QSize(600, 400));
        infoabout->setMaximumSize(QSize(600, 400));
        frameLogo = new QFrame(infoabout);
        frameLogo->setObjectName(QString::fromUtf8("frameLogo"));
        frameLogo->setGeometry(QRect(9, 9, 404, 350));
        frameLogo->setMinimumSize(QSize(404, 350));
        frameLogo->setFrameShape(QFrame::StyledPanel);
        frameLogo->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frameLogo);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(infoabout);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(420, 330, 171, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(14);
        groupBox->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        verticalLayout->addWidget(label);


        retranslateUi(infoabout);

        QMetaObject::connectSlotsByName(infoabout);
    } // setupUi

    void retranslateUi(QDialog *infoabout)
    {
        infoabout->setWindowTitle(QCoreApplication::translate("infoabout", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("infoabout", "Info", nullptr));
        label->setText(QCoreApplication::translate("infoabout", "Student ID : 155", nullptr));
    } // retranslateUi

};

namespace Ui {
    class infoabout: public Ui_infoabout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOABOUT_H
