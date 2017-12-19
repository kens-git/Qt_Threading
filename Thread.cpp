#include "Thread.hpp"

#include <QTime>
#include <QMutexLocker>

void Thread::run() {
    static QMutex mut;
    // Qt's version of the standard C++ lock_guard, unlocked when locker is destroyed
    QMutexLocker locker(&mut);
    QTime time;
    time.start();

    while (time.elapsed() < MS_COUNT) {
        emit percent(((float)time.elapsed() / (float)MS_COUNT) * 100);
    }

    emit percent(100);
    emit done();
}
