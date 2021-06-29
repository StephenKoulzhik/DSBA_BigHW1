#include "tablemodel.h"
#include <QFile>
#include <QTextStream>
tablemodel::tablemodel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int tablemodel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return Data.size();
}


int tablemodel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    if (Data.empty())
    {
        return 0;
    }
    return Data[0].size();
}

void tablemodel::addRow(QList<QVariant> Row)
{
    bool emptyTable = false;
    // If our table is empty we add empty columns
    if (Data.isEmpty())
    {
        emptyTable = true;
        beginInsertColumns(QModelIndex(), 0, Row.size() - 1);
    }
    // Now add the given row
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    Data.append(Row);
    endInsertRows();
    if (emptyTable)
        endInsertColumns();
}

QVariant tablemodel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    int row = index.row();
    int column = index.column();

    if (role == Qt::DisplayRole)
        return Data.at(row).at(column);
    else if (role == Qt::BackgroundRole)
        return QBrush(Qt::gray);

    return QVariant();
}

QVariant tablemodel::headerData(int column, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && column >= 0)
    {
        if (orientation == Qt::Orientation::Horizontal && column < 7)
            return headers.at(column);
        else
            return column++;
    }
    return QVariant();
}

QList<QList<QVariant>> tablemodel::getData() const
{
    return Data;
}

void tablemodel::deleteRow(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    Data.removeAt(index);
    endRemoveRows();
}


void tablemodel::download(QString path)
{
    QFile downloadFile(path);
    downloadFile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
    QTextStream write(&downloadFile);

    for (int i = 0; i < rowCount(); ++i)
    {
        for (QVariant& x : Data[i])
        {
            write << x.toString()<<',';
        }

        write << '\n';
    }
    downloadFile.close();
}
