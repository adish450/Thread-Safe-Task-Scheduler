# Thread-Safe Task Scheduler (C++)

## Overview
This project implements a thread-safe task scheduler (thread pool) in C++ that efficiently executes tasks concurrently using a fixed number of worker threads. It demonstrates core concurrency concepts required for high-performance systems.

---

## Key Concepts Covered
- Multithreading using `std::thread`
- Synchronization using `std::mutex` and `std::condition_variable`
- Producer-consumer pattern
- Thread-safe queue design
- Task scheduling and execution
- Graceful thread shutdown

---

## Features
- Fixed-size thread pool
- Concurrent task execution
- Blocking task queue with condition variables
- Efficient resource utilization (no thread spawning per task)
- Safe shutdown of worker threads

---

## Project Structure
├── main.cpp
├── scheduler.h
├── scheduler.cpp
├── Makefile


---

## Build & Run

### Compile
```bash
make

Run
./scheduler

Sample Output
Task 0 executed
Task 1 executed
Task 2 executed
...