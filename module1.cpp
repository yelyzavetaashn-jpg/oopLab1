
#include "module1.h"

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class TextDialog : public QDialog
{
public:
    explicit TextDialog(QWidget *parent = nullptr)
        : QDialog(parent)
    {
        setWindowTitle("Робота1 — введення тексту");

        auto *layout = new QVBoxLayout(this);

        auto *label = new QLabel("Введіть текст:", this);
        edit = new QLineEdit(this);

        auto *buttonLayout = new QHBoxLayout();
        auto *okButton = new QPushButton("Так", this);
        auto *cancelButton = new QPushButton("Відміна", this);

        buttonLayout->addWidget(okButton);
        buttonLayout->addWidget(cancelButton);

        layout->addWidget(label);
        layout->addWidget(edit);
        layout->addLayout(buttonLayout);

        connect(okButton, &QPushButton::clicked, this, [this]() {
            accept();
        });

        connect(cancelButton, &QPushButton::clicked,
                this, &QDialog::reject);
    }

    QString enteredText() const
    {
        return edit->text();
    }

private:
    QLineEdit *edit;
};

bool runTextDialog(QWidget *parent, QString &text)
{
    TextDialog dialog(parent);

    if (dialog.exec() == QDialog::Accepted) {
        text = dialog.enteredText();
        return true;
    }

    return false;
}
