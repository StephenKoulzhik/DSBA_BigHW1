#include "customfilter.h"

customFilterModel::customFilterModel(QObject *parent) :
    QSortFilterProxyModel(parent)
{

}
//At least I tried

bool customFilterModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
    QVariant a = sourceModel() -> data(left);
    QVariant b = sourceModel() -> data(right);

    return a < b;
}

bool customFilterModel::filterAcceptsRow(int sourceRow, const QModelIndex &source_parent) const
{
    QModelIndex index2 = sourceModel() -> index(sourceRow, 2, source_parent);
    QVariant num = sourceModel() -> data(index2);
    bool ok = false;
    num = num.toInt(&ok);
    return ok;
}
