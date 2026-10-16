
#include "mainwindow.h"
#include "module1.h"
#include "module2.h"

#include <QLabel>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QWidget>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      resultLabel(new QLabel("Оберіть пункт меню «Робота1» або «Робота2»."))
{
    setWindowTitle("oopLab1");
    resize(500, 300);

    auto *central = new QWidget(this);
    auto *layout = new QVBoxLayout(central);

    resultLabel->setWordWrap(true);
    layout->addWidget(resultLabel);

    setCentralWidget(central);

    QMenu *workMenu = menuBar()->addMenu("Меню");

    QAction *work1Action = workMenu->addAction("Робота1");
    QAction *work2Action = workMenu->addAction("Робота2");

    connect(work1Action, &QAction::triggered, this, [this]() {
        QString text;

        if (runTextDialog(this, text)) {
            resultLabel->setText("Введений текст: " + text);
        }
    });

    connect(work2Action, &QAction::triggered, this, [this]() {
        int value = 1;

        if (runSliderDialog(this, value)) {
            resultLabel->setText(
                "Вибране число: " + QString::number(value)
            );
        }
    });
}
