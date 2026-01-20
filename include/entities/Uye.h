#pragma once
#include <string>
#include "entities/varlik.h"

class Uye : public varlik {
public:
    Uye(uint64_t id = 0, std::string tc = "", std::string ad_soyad = "",
        std::string eposta = "", std::string telefon = "", std::string kayit_tarihi = "");

    std::string get_tc_no() const;
    std::string get_ad_soyad() const;

private:
    std::string _tc_no;
    std::string _ad_soyad;
    std::string _email;
    std::string _telefon;
    std::string _kayit_tarihi;
};