#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./addcontactdialog.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->AddContactButton, &QPushButton::clicked, this, &MainWindow::Add_contact_button_clicked);
    connect(ui->ContactTable, &QTableWidget::cellDoubleClicked, this, &MainWindow::Contact_table_double_clicked);
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
        // Add contact to the table
        int row = ui->ContactTable->rowCount();
        ui->ContactTable->insertRow(row);
        ui->ContactTable->setItem(row, 0, new QTableWidgetItem(name));
        ui->ContactTable->setItem(row, 1, new QTableWidgetItem(phone));
        ui->ContactTable->setItem(row, 2, new QTableWidgetItem(email));
    }
}

void MainWindow::Contact_table_double_clicked(int row, int column) {
    QString name = ui->ContactTable->item(row, 0)->text();
    QString phone = ui->ContactTable->item(row, 1)->text();
    QString email = ui->ContactTable->item(row, 2)->text();
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Contact",
                                  QString("Do you want to delete the contact?\n\nName: %1\nPhone: %2\nEmail: %3")
                                      .arg(name).arg(phone).arg(email),
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        ui->ContactTable->removeRow(row);
    }
}
