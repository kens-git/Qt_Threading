#ifndef THREAD_HPP
#define THREAD_HPP

#include <QThread>
#include <QMutex>

class Thread : public QThread {
    Q_OBJECT

    protected:
        // called by the start() function
        void run();

    private:
        const int MS_COUNT = 2000;

    signals:
        void done();
        void percent(int percent);
};

#endif // THREAD_HPP
