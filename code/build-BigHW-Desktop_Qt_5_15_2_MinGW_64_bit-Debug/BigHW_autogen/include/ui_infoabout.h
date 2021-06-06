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
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_infoabout
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QLabel *label;

    void setupUi(QDialog *infoabout)
    {
        if (infoabout->objectName().isEmpty())
            infoabout->setObjectName(QString::fromUtf8("infoabout"));
        infoabout->resize(800, 600);
        gridLayout = new QGridLayout(infoabout);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(infoabout);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(640, 550, 141, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(14);
        label->setFont(font);

        gridLayout->addWidget(frame, 2, 0, 1, 1);


        retranslateUi(infoabout);

        QMetaObject::connectSlotsByName(infoabout);
    } // setupUi

    void retranslateUi(QDialog *infoabout)
    {
        infoabout->setWindowTitle(QCoreApplication::translate("infoabout", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("infoabout", "Studen ID: 155", nullptr));
    } // retranslateUi

};

namespace Ui {
    class infoabout: public Ui_infoabout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOABOUT_H
