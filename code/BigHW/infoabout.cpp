#include "infoabout.h"
#include "ui_infoabout.h"
#include "mylogo.h"
infoabout::infoabout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoabout)
{
    ui->setupUi(this);
    MyLogo* logoWidget = new MyLogo(ui -> frameLogo);
    ui -> gridLayout -> addWidget(logoWidget);
    logoWidget -> repaint();
}

infoabout::~infoabout()
{
    delete ui;
}


