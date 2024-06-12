#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "customfilterproxymodel.h"
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void Add_contact_button_clicked();
    void Contact_table_double_clicked(int row, int column);
    void Search_bar_text_changed(const QString &text);
    void Filter_combo_box_changed(int index);

private:
    Ui::MainWindow *ui;
    CustomFilterProxyModel *proxyModel;
    QStandardItemModel *model;
};
#endif // MAINWINDOW_H
