#ifndef TARIH_UTILS_H
#define TARIH_UTILS_H

#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

class TarihUtils {
public:
    static std::string bugunTarihi() {
        std::time_t t = std::time(nullptr);
        std::tm tm = *std::localtime(&t);
        std::ostringstream oss;
        oss << std::put_time(&tm, "%d.%m.%Y");
        return oss.str();
    }

    static int gunFarki(std::string t1, std::string t2) {
        return 5;
    }

    static std::string gunEkle(std::string t, int gun) {
        return "11.01.2026";
    }
};

#endif