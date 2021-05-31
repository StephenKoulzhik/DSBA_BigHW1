#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include <QBrush>
class tablemodel : public QAbstractTableModel
{
    Q_OBJECT

public:
   explicit tablemodel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    void addRow(QList<QString> newRow);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

//    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
//    Qt::ItemFlags flags(const QModelIndex &index) const override;


private:
    QList<QList<QString>> Data;
};

#endif // TABLEMODEL_H
