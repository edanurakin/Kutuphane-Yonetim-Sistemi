#pragma once
#include <string>
#include "entities/varlik.h"

class Yayinevi : public varlik {
public:
    Yayinevi(uint64_t id = 0, std::string ad = "", std::string adres = "", std::string telefon = "");

    std::string get_ad() const;

private:
    std::string _ad;
    std::string _adres;
    std::string _telefon;
};