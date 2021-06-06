#include "infoabout.h"
#include "ui_infoabout.h"

infoabout::infoabout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoabout)
{
    ui->setupUi(this);
}

infoabout::~infoabout()
{
    delete ui;
}


