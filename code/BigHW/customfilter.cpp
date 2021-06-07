#include "customfilter.h"

customFilterModel::customFilterModel(QObject *parent) :
    QSortFilterProxyModel(parent)
{

}

bool customFilterModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
    QVariant a = sourceModel() -> data(left);
    QVariant b = sourceModel() -> data(right);

    bool ok = false;
    return a < b;
}
