#include <iostream>
#include <thread>
#include <vector>
#include "logger.hpp"

void worker(int id, Logger &logger, int messages) {
    for (int i = 0; i < messages; ++i)
        logger.log("Worker " + std::to_string(id) + " message " + std::to_string(i));
}

int main() {
    Logger logger("mt_log.txt");
    const int workers = 4, messages = 50;
    std::vector<std::thread> threads;
    for (int i = 0; i < workers; ++i) threads.emplace_back(worker, i, std::ref(logger), messages);
    for (auto &t : threads) t.join();
    std::cout << "All workers finished. Check mt_log.txt\n";
    return 0;
}
