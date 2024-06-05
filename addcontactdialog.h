#ifndef ADDCONTACTDIALOG_H
#define ADDCONTACTDIALOG_H
#include <QDialog>

namespace Ui {
class AddContactDialog;
}

class AddContactDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddContactDialog(QWidget *parent = nullptr);
    ~AddContactDialog();
    QString getName() const;
    QString getPhone() const;
    QString getEmail() const;

private:
    Ui::AddContactDialog *ui;
};

#endif // ADDCONTACTDIALOG_H
