#include "scheduler.h"
#include <iostream>

int main() {
    TaskScheduler scheduler(4);

    for (int i = 0; i < 10; i++) {
        scheduler.submit([i]() {
            std::cout << "Task " << i << " executed\n";
        });
    }

    return 0;
}