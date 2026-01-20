#pragma once
#include <string>
#include "entities/varlik.h"

class Rezervasyon : public varlik {
public:
    Rezervasyon(uint64_t id = 0, uint64_t kitap_id = 0, uint64_t uye_id = 0,
                std::string tarih = "", std::string durum = "");

private:
    uint64_t _kitap_id;
    uint64_t _uye_id;
    std::string _rezerv_tarihi;
    std::string _durum;
};