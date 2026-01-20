#pragma once
#include <string>
#include "entities/varlik.h"

class Yazar : public varlik {
public:
    Yazar(uint64_t id = 0, std::string ad_soyad = "", int dogum_yili = 0, std::string ulke = "");

    std::string get_ad_soyad() const;

private:
    std::string _ad_soyad;
    int _dogum_yili;
    std::string _ulke;
};