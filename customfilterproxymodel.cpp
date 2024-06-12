#include "customfilterproxymodel.h"

#include <QTableWidgetItem>
#include <QTableWidget>
#include <QRegularExpression>

CustomFilterProxyModel::CustomFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent), m_filterType(NoFilter)
{
}

void CustomFilterProxyModel::setSearchBarContent(const QString &text)
{
    m_searchExpression = QRegularExpression(text, QRegularExpression::CaseInsensitiveOption);
    invalidateFilter();
}

void CustomFilterProxyModel::setFilterType(FilterType filterType)
{
    m_filterType = filterType;
    invalidateFilter();
}

bool CustomFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    if (!sourceModel()) {
        return true;
    }
    QModelIndex nameIndex = sourceModel()->index(sourceRow, 0, sourceParent);
    QVariant nameData = sourceModel()->data(nameIndex);
    QModelIndex phoneIndex = sourceModel()->index(sourceRow, 1, sourceParent);
    QVariant phoneData = sourceModel()->data(phoneIndex);
    QModelIndex emailIndex = sourceModel()->index(sourceRow, 2, sourceParent);
    QVariant emailData = sourceModel()->data(emailIndex);
    if (m_searchExpression.pattern().isEmpty()) {
        //filtering logic
        switch (m_filterType) {
            case NonEmptyName:
                return !nameData.toString().isEmpty();
            case NonEmptyPhoneNumber:
                return !phoneData.toString().isEmpty();
            case NonEmptyEmailAddress:
                return !emailData.toString().isEmpty();
            case NoFilter:
                default:
                    return true;
        }
    }
    if (m_searchExpression.match(nameData.toString()).hasMatch()) {
        //filtering logic
        switch (m_filterType) {
            case NonEmptyName:
                return !nameData.toString().isEmpty();
            case NonEmptyPhoneNumber:
                return !phoneData.toString().isEmpty();
            case NonEmptyEmailAddress:
                return !emailData.toString().isEmpty();
            case NoFilter:
                default:
                    return true;
        }
    }
    return false;
}

