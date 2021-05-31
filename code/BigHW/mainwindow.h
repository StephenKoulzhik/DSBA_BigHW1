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
    void on_tableView_entered(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    tablemodel *myTableModel;
};
#endif // MAINWINDOW_H
