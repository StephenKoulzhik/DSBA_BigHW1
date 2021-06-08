#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tablemodel.h"
#include <QTransposeProxyModel>
#include <QSortFilterProxyModel>
#include "customfilter.h"
#include <QListView>
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


    void currentSelection(QModelIndex next, QModelIndex hahaUselessGuy);

    void on_filteringButton_clicked();

    void on_addButton_clicked();

    void on_removeButton_clicked();

    void on_downloadButton_clicked();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    tablemodel *myTableModel;
    tablemodel *favList;

    QSortFilterProxyModel *sortingModel;

};
#endif // MAINWINDOW_H
