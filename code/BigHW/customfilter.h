#ifndef CUSTOMFILTER_H
#define CUSTOMFILTER_H
#include <QSortFilterProxyModel>

class customFilterModel: public QSortFilterProxyModel
{
    Q_OBJECT
public:
    customFilterModel(QObject *parent = nullptr);

protected:
   // bool filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const override;
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;
};



#endif // CUSTOMFILTER_H
