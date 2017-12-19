#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QVector>
#include <QProgressBar>

#include "Thread.hpp"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;
        QVector<Thread*> mThreads;
        QVector<QProgressBar*> mProgressBars;

    private slots:
        void addNewThread();
};

#endif // MAINWINDOW_HPP
