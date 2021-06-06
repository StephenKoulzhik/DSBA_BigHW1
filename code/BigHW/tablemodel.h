#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QVariant>
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
    void addRow(QList<QVariant> newRow);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int column, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QList<QList<QVariant>> getData() const;
    void deleteRow(int index);
    void download(QString path);

//    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
//    Qt::ItemFlags flags(const QModelIndex &index) const override;


private:
    QList<QList<QVariant>> Data;
    QList<QString> headers = {"Rank", "Title", "Ratings", "Install Milestone", "Average Rating", "Price", "Five Stars"};
};

#endif // TABLEMODEL_H
