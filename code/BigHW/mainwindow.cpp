#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "gameStructure.h"
#include <QFile>
#include <QTextStream>
#include <QStandardItemModel>
#include <QString>
void fillTable(tablemodel* myModel)
{
    QFile inputFile("C:\\Users\\steph\\Documents\\GitHub\\DSBA_BigHW1\\code\\BigHW\\android-games.csv");
    inputFile.open(QFile::ReadOnly);
    QTextStream input(&inputFile);


    //Remember to always skip the first line in a CSV-file, fam
    QString line = input.readLine();

    while(!input.atEnd())
    {
        line = input.readLine();
        QList<QString> anotherRow;
        int counter = 0;
        for (QString& x: line.split('|'))
        {
            if (counter <= 4 || counter == 7 || counter == 9)
            anotherRow.append(x);
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
    myTableModel = new tablemodel(this);
    ui->tableView->setModel(myTableModel);
    fillTable(myTableModel);
//    vector<Game> arr;
//    arr = fillVec();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete myTableModel;
}

//adding to favourite list


//void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
//{
//    ui -> label -> setText("");
//}

int MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    return 5;
}



void MainWindow::on_helpButton_clicked()
{
    ui -> label_3 -> setText(QString::number(MainWindow::on_tableView_clicked(index)));
}
