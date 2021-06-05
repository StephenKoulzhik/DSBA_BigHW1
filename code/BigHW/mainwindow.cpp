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
        QList<QVariant> anotherRow;
        int counter = 0;
        //At this point I've established the fact that QVariant is absolutely useless piece of QtClass or whatever I'm not a nerd fuck off.
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

//            if (counter <= 4 || counter == 7 || counter == 9)
//            {

//                anotherRow.append(x);
//                counter++;
//            }
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

    transposeModel = new QTransposeProxyModel(this);
    transposeModel -> setSourceModel(myTableModel);

    sortingModel = new QSortFilterProxyModel(this);
    sortingModel -> setSourceModel(myTableModel);

    ui -> tableView -> setModel(sortingModel);
    ui -> tableView -> setSortingEnabled(true);

    connect(ui->tableView->selectionModel(),
            SIGNAL(currentChanged(QModelIndex,QModelIndex)),
            this,
            SLOT(onTableViewCurrentChanged(QModelndex,QModelIndex)));


}

MainWindow::~MainWindow()
{
    delete ui;
    delete myTableModel;
    delete transposeModel;
    delete sortingModel;
}

//adding to favourite list

void MainWindow::onTableViewCurrentChanged(QModelIndex next, QModelIndex hahaUselessGuy)
{
   int row = sortingModel->mapToSource(next).row();
   ui->listView->setModelColumn(row);

}

//void MainWindow::on_tableView_clicked(const QModelIndex &index)
//{
//   currentSelection = index;
//}



//void MainWindow::on_helpButton_clicked()
//{
//    ui -> label_3 -> setText(QString::number(MainWindow::on_tableView_clicked(index)));
//}
