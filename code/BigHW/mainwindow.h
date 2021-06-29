#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tablemodel.h"
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



    void on_filteringButton_clicked();

    void on_addButton_clicked();

    void on_removeButton_clicked();

    void on_downloadButton_clicked();

    void on_actionAbout_triggered();

    void on_pushButton_2_clicked();


    void on_checkBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    tablemodel *myTableModel, *whishListTableModel;
    tablemodel *favList;

    QSortFilterProxyModel *sortingModel;

};
#endif // MAINWINDOW_H
