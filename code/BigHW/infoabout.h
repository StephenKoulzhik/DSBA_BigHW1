#ifndef INFOABOUT_H
#define INFOABOUT_H

#include <QDialog>

namespace Ui {
class infoabout;
}

class infoabout : public QDialog
{
    Q_OBJECT

public:
    explicit infoabout(QWidget *parent = nullptr);
    ~infoabout();

private:
    Ui::infoabout *ui;
};

#endif // INFOABOUT_H
