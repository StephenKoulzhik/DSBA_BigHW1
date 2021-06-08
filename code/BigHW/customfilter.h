#ifndef CUSTOMFILTER_H
#define CUSTOMFILTER_H
#include <QSortFilterProxyModel>

class customFilterModel: public QSortFilterProxyModel
{
    Q_OBJECT
public:
    customFilterModel(QObject *parent = nullptr);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &source_parent) const override;
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;
};



#endif // CUSTOMFILTER_H
