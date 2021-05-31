#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tablemodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    int on_tableView_clicked(const QModelIndex &index);

    void on_helpButton_clicked();

private:
    Ui::MainWindow *ui;
    tablemodel *myTableModel;
    QModelIndex index;
};
#endif // MAINWINDOW_H
