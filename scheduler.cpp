#include "scheduler.h"

TaskScheduler::TaskScheduler(size_t numThreads) : stop(false) {
    for (size_t i = 0; i < numThreads; ++i) {
        workers.emplace_back(&TaskScheduler::worker, this);
    }
}

TaskScheduler::~TaskScheduler() {
    {
        std::unique_lock<std::mutex> lock(mtx);
        stop = true;
    }
    cv.notify_all();
    for (auto &t : workers) t.join();
}

void TaskScheduler::submit(std::function<void()> task) {
    {
        std::unique_lock<std::mutex> lock(mtx);
        tasks.push(task);
    }
    cv.notify_one();
}

void TaskScheduler::worker() {
    while (true) {
        std::function<void()> task;

        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]() { return stop || !tasks.empty(); });

            if (stop && tasks.empty()) return;

            task = tasks.front();
            tasks.pop();
        }

        task();
    }
}