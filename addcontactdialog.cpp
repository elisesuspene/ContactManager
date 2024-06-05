#include "addcontactdialog.h"
#include "./ui_AddContactDialog.h"

AddContactDialog::AddContactDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AddContactDialog)
{
    ui->setupUi(this);
    connect(ui->SaveContactButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->CancelContactButton, &QPushButton::clicked, this, &QDialog::reject);
}

AddContactDialog::~AddContactDialog() {
    delete ui;
}

QString AddContactDialog::getName() const {
    return ui->NameLineEdit->text();
}

QString AddContactDialog::getPhone() const {
    return ui->PhoneLineEdit->text();
}

QString AddContactDialog::getEmail() const {
    return ui->EmailLineEdit->text();
}
