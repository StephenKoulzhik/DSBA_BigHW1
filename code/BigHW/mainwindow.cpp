#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "infoabout.h"
#include <QFile>
#include <QTextStream>
#include <QStandardItemModel>
#include <QString>
#include <QFileDialog>
#include <iostream>
#include <QtDebug>
void fillTable(tablemodel* myModel, QString path)
{
    QFile inputFile(path);
    inputFile.open(QFile::ReadOnly);
    QTextStream input(&inputFile);


    //Remember to always skip the first line in a CSV-file, fam
    QString line = input.readLine();

    while(!input.atEnd())
    {
        line = input.readLine();
        QList<QVariant> anotherRow;
        int counter = 0;
        //
        for (QString& x: line.split('|'))
        {
            bool convertable = false;
            QVariant mf = x;
            if (counter == 0 || counter == 2 || counter == 9)
            {
                mf = x.toInt(&convertable);
                anotherRow.append(mf);

            }
            else if (counter == 4 || counter == 7)
            {
                mf = x.toDouble(&convertable);
                anotherRow.append(mf);
            }
            else if (counter == 1 || counter == 3)
            {
                anotherRow.append(x);
            }
            counter++;

        }
        myModel -> addRow(anotherRow);
    }
    inputFile.close();
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString path = QFileDialog::getOpenFileName(this);
    myTableModel = new tablemodel(this);
    ui->tableView->setModel(myTableModel);
    fillTable(myTableModel, path);


    sortingModel = new QSortFilterProxyModel(this);
    sortingModel -> setSourceModel(myTableModel);
    sortingModel -> setFilterCaseSensitivity(Qt::CaseInsensitive);

    ui -> tableView -> setModel(sortingModel);
    ui -> tableView -> setSortingEnabled(true);


    favList = new tablemodel(this);
    ui -> listView -> setModel(favList);
    ui -> listView -> setModelColumn(1);

    ui -> comboBox -> addItems({"Rank", "Title", "Total number of Ratings", "Install Milestone", "Average Rating", "Price", "Perfect Scores"});

}

MainWindow::~MainWindow()
{
    delete ui;
    delete myTableModel;
    delete sortingModel;
}



void MainWindow::on_filteringButton_clicked()
{
    int filteringColumn = ui -> comboBox -> currentIndex();
    sortingModel -> setFilterKeyColumn(filteringColumn);
    sortingModel -> setFilterFixedString(ui -> lineEdit -> text());

}

void MainWindow::on_addButton_clicked()
{
    QModelIndexList list = ui -> tableView -> selectionModel() -> selectedIndexes();
    if (!list.isEmpty())
    {
        QList<QVariant> extra = myTableModel->getData()[sortingModel -> mapToSource(list[0]).row()];
        favList->addRow({extra[1]});
    }

}

void MainWindow::on_removeButton_clicked()
{
    QModelIndexList list = ui -> listView -> selectionModel() -> selectedIndexes();
    if (!list.isEmpty())
    {
        favList->deleteRow(list.first().row());
    }
}

void MainWindow::on_downloadButton_clicked()
{
    QString path = QFileDialog::getSaveFileName(this);
    favList -> download(path);
}


void MainWindow::on_actionAbout_triggered()
{
    infoabout aboutwindow;
    aboutwindow.setModal(true); //Random Indian guy told me to write this line in his guide
//    so I trusted him 'cause I can only trust Indian guys on Youtube when mastering this programm
    //https://www.youtube.com/watch?v=z6-FWJteNLI
    aboutwindow.exec();
}



void MainWindow::on_pushButton_2_clicked()
{
    QString path = QFileDialog::getOpenFileName(this);
    QFile inputFile(path);
    inputFile.open(QFile::ReadOnly);
    QTextStream input(&inputFile);

    favList = new tablemodel(this);
    ui -> listView -> setModel(favList);
    ui -> listView -> setModelColumn(1);

    while(!input.atEnd())
    {
        QString line = input.readLine();
        QVariant title = line.split(',')[0];
        favList -> addRow({title});
    }

    inputFile.close();
}



void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (arg1)
    {
        whishListTableModel = new tablemodel(this);
        for (QList<QVariant> x : favList->getData())
        {
            QVariant title = x[0];
            for (QList<QVariant> y : myTableModel->getData())
            {
                if (y[1] == title)
                {
                  whishListTableModel->addRow(y);
                }
            }

        }
        ui->tableView->setModel(whishListTableModel);
        sortingModel = new QSortFilterProxyModel(this);
        sortingModel -> setSourceModel(whishListTableModel);
        sortingModel -> setFilterCaseSensitivity(Qt::CaseInsensitive);

        ui -> tableView -> setModel(sortingModel);
        ui -> tableView -> setSortingEnabled(true);
    }
    else
    {
        ui->tableView->setModel(myTableModel);
        sortingModel = new QSortFilterProxyModel(this);
        sortingModel -> setSourceModel(myTableModel);
        sortingModel -> setFilterCaseSensitivity(Qt::CaseInsensitive);

        ui -> tableView -> setModel(sortingModel);
        ui -> tableView -> setSortingEnabled(true);
    }
}
