all:
\tg++ -std=c++17 main.cpp scheduler.cpp -o scheduler -pthread

clean:
\trm -f scheduler