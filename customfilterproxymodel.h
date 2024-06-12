#ifndef CUSTOMFILTERPROXYMODEL_H
#define CUSTOMFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>

class CustomFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    enum FilterType {
        NonEmptyName,
        NonEmptyPhoneNumber,
        NonEmptyEmailAddress,
        NoFilter
    };
    CustomFilterProxyModel(QObject *parent = nullptr);
    void setFilterType(FilterType filterType);
    void setSearchBarContent(const QString &text);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

private:
    FilterType m_filterType;
    QRegularExpression m_searchExpression;

};

#endif // CUSTOMFILTERPROXYMODEL_H
