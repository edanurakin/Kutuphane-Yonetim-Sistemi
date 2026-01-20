#include "entities/Uye.h"

Uye::Uye(uint64_t id, std::string tc, std::string ad_soyad, std::string eposta, std::string telefon, std::string kayit_tarihi)
    : varlik(id), _tc_no(tc), _ad_soyad(ad_soyad), _email(eposta), _telefon(telefon), _kayit_tarihi(kayit_tarihi) {}

std::string Uye::get_tc_no() const {
    return _tc_no;
}
std::string Uye::get_ad_soyad() const {
    return _ad_soyad;
}
