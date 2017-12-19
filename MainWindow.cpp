#include "MainWindow.hpp"
#include "ui_MainWindow.h"

#include <QProgressBar>

#include "Thread.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->startNewThreadButton, &QPushButton::clicked, this, &MainWindow::addNewThread);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addNewThread() {
    Thread* thread = new Thread();
    QProgressBar* progressBar = new QProgressBar(this);

    ui->progressBarLayout->addWidget(progressBar);

    connect(thread, &Thread::percent, progressBar, &QProgressBar::setValue);

    thread->start();
}
