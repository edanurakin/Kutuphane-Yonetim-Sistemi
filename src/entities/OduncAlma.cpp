#include "entities/OduncAlma.h"

OduncAlma::OduncAlma(uint64_t id, uint64_t kitap_id, uint64_t uye_id, std::string odunc_tarihi, std::string iade_tarihi, std::string gercek_iade)
    : varlik(id), _kitap_id(kitap_id), _uye_id(uye_id), _odunc_tarihi(odunc_tarihi), _iade_tarihi(iade_tarihi), _gercek_iade(gercek_iade) {}

uint64_t OduncAlma::get_kitap_id() const {
    return _kitap_id;
}
uint64_t OduncAlma::get_uye_id() const {
    return _uye_id;
}
std::string OduncAlma::get_odunc_tarihi() const {
    return _odunc_tarihi;
}
std::string OduncAlma::get_iade_tarihi() const {
    return _iade_tarihi;
}