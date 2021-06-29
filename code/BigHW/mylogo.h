#ifndef MYLOGO_H
#define MYLOGO_H

#include <QWidget>

class MyLogo : public QWidget
{
    Q_OBJECT
public:
    explicit MyLogo(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;

signals:

};


#endif // MYLOGO_H
