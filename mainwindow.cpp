#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./addcontactdialog.h"
#include "customfilterproxymodel.h"

#include <QMessageBox>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , proxyModel(new CustomFilterProxyModel(this))
    , model(new QStandardItemModel(this))
{
    contactList = BridgeToJson::loadContactsFromJsonFile("contacts.json");

    ui->setupUi(this);

    proxyModel->setSourceModel(model);
    proxyModel->setFilterKeyColumn(-1);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->ContactTableView->setModel(proxyModel);

    ui->ContactTable->setVisible(false);

    QStringList headers = {"Name", "Phone", "Email"};
    model->setHorizontalHeaderLabels(headers);
    int columnWidth = 265;
    for (int i = 0; i < headers.size(); ++i) {
        ui->ContactTableView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
        ui->ContactTableView->setColumnWidth(i, columnWidth);
    }

    for (const auto &contact : contactList) {
        QList<QStandardItem *> items;
        items.append(new QStandardItem(contact.name));
        items.append(new QStandardItem(contact.phone));
        items.append(new QStandardItem(contact.email));
        model->appendRow(items);
    }

    connect(ui->AddContactButton, &QPushButton::clicked, this, &MainWindow::Add_contact_button_clicked);
    connect(ui->ContactTableView, &QTableView::doubleClicked, this, &MainWindow::Contact_table_double_clicked);
    connect(ui->SearchBar, &QLineEdit::textChanged, this, &MainWindow::Search_bar_text_changed);
    connect(ui->FilterComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::Filter_combo_box_changed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Add_contact_button_clicked() {
    AddContactDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString name = dialog.getName();
        QString phone = dialog.getPhone();
        QString email = dialog.getEmail();
        int row = ui->ContactTable->rowCount();
        ui->ContactTable->insertRow(row);
        ui->ContactTable->setItem(row, 0, new QTableWidgetItem(name));
        ui->ContactTable->setItem(row, 1, new QTableWidgetItem(phone));
        ui->ContactTable->setItem(row, 2, new QTableWidgetItem(email));
        QList<QStandardItem *> items;
        items.append(new QStandardItem(name));
        items.append(new QStandardItem(phone));
        items.append(new QStandardItem(email));
        model->appendRow(items);
        BridgeToJson::Contact newContact;
        newContact.name = name;
        newContact.phone = phone;
        newContact.email = email;
        contactList.append(newContact);
        BridgeToJson::saveContactsToJsonFile(contactList, "contacts.json");
    }
}

void MainWindow::Contact_table_double_clicked(const QModelIndex &index) {
    if (!index.isValid())
    {
        return;
    }
    int row = index.row();
    QString name = model->item(row, 0)->text();
    QString phone = model->item(row, 1)->text();
    QString email = model->item(row, 2)->text();
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Contact",
                                  QString("Do you want to delete the contact?\n\nName: %1\nPhone: %2\nEmail: %3")
                                      .arg(name).arg(phone).arg(email),
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        ui->ContactTable->removeRow(row);
        for (int i = 0; i < model->rowCount(); i++) {
            if (model->item(i, 0)->text() == name &&
                model->item(i, 1)->text() == phone &&
                model->item(i, 2)->text() == email) {
                model->removeRow(i);
                break;
            }
        }
        for (int i = 0; i < contactList.size(); ++i) {
            if (contactList[i].name == name &&
                contactList[i].phone == phone &&
                contactList[i].email == email) {
                contactList.removeAt(i);
                break;
            }
        }
        BridgeToJson::saveContactsToJsonFile(contactList, "contacts.json");
    }
}

void MainWindow::Search_bar_text_changed(const QString &text) {
    proxyModel -> setSearchBarContent(text);
}

void MainWindow::Filter_combo_box_changed(int index){
    CustomFilterProxyModel::FilterType filterType = static_cast<CustomFilterProxyModel::FilterType>(index);
    proxyModel->setFilterType(filterType);
}
