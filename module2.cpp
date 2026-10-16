
#include "module2.h"

#include <QDialog>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class SliderDialog : public QDialog
{
public:
    explicit SliderDialog(QWidget *parent = nullptr)
        : QDialog(parent)
    {
        setWindowTitle("Робота2 — вибір числа");

        auto *layout = new QVBoxLayout(this);

        auto *instruction = new QLabel(
            "Виберіть число від 1 до 100:", this
        );

        slider = new QSlider(Qt::Horizontal, this);
        slider->setRange(1, 100);
        slider->setValue(1);

        valueLabel = new QLabel("Вибране число: 1", this);

        auto *buttonLayout = new QHBoxLayout();
        auto *okButton = new QPushButton("Так", this);
        auto *cancelButton = new QPushButton("Відміна", this);

        buttonLayout->addWidget(okButton);
        buttonLayout->addWidget(cancelButton);

        layout->addWidget(instruction);
        layout->addWidget(slider);
        layout->addWidget(valueLabel);
        layout->addLayout(buttonLayout);

        connect(slider, &QSlider::valueChanged, this,
                [this](int value) {
            valueLabel->setText(
                "Вибране число: " + QString::number(value)
            );
        });

        connect(okButton, &QPushButton::clicked,
                this, &QDialog::accept);

        connect(cancelButton, &QPushButton::clicked,
                this, &QDialog::reject);
    }

    int selectedValue() const
    {
        return slider->value();
    }

private:
    QSlider *slider;
    QLabel *valueLabel;
};

bool runSliderDialog(QWidget *parent, int &value)
{
    SliderDialog dialog(parent);

    if (dialog.exec() == QDialog::Accepted) {
        value = dialog.selectedValue();
        return true;
    }

    return false;
}
