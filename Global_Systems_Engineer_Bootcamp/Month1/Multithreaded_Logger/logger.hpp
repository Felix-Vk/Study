#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <mutex>
#include <fstream>
#include <string>

class Logger {
    std::mutex mtx;
    std::ofstream ofs;
public:
    explicit Logger(const std::string& path = "mt_log.txt") { ofs.open(path, std::ios::app); }
    ~Logger() { if (ofs.is_open()) ofs.close(); }
    void log(const std::string& msg) {
        std::lock_guard<std::mutex> lk(mtx);
        ofs << msg << std::endl;
    }
};
#endif // LOGGER_HPP
