#pragma once
#include <functional>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

class TaskScheduler {
public:
    TaskScheduler(size_t numThreads);
    ~TaskScheduler();

    void submit(std::function<void()> task);

private:
    void worker();

    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex mtx;
    std::condition_variable cv;
    bool stop;
};