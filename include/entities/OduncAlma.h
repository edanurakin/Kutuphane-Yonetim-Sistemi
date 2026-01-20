#pragma once
#include <string>
#include "entities/varlik.h"

class OduncAlma : public varlik {
public:
    OduncAlma(uint64_t id = 0, uint64_t kitap_id = 0, uint64_t uye_id = 0,
              std::string odunc_tarihi = "", std::string iade_tarihi = "", std::string gercek_iade = "");

    uint64_t get_kitap_id() const;
    uint64_t get_uye_id() const;
    std::string get_odunc_tarihi() const;
    std::string get_iade_tarihi() const;

private:
    uint64_t _kitap_id;
    uint64_t _uye_id;
    std::string _odunc_tarihi;
    std::string _iade_tarihi;
    std::string _gercek_iade;
};