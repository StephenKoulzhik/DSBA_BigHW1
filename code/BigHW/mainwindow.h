#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tablemodel.h"
#include <QTransposeProxyModel>
#include <QSortFilterProxyModel>
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

    void on_tableView_clicked(const QModelIndex &index);

    void on_helpButton_clicked();

    void onTableViewCurrentChanged(QModelIndex next, QModelIndex hahaUselessGuy);

private:
    Ui::MainWindow *ui;
    tablemodel *myTableModel;
    const QModelIndex currentSelection;

    QTransposeProxyModel *transposeModel;
    QSortFilterProxyModel *sortingModel;

};
#endif // MAINWINDOW_H
