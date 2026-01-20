#include "entities/Yayinevi.h"

Yayinevi::Yayinevi(uint64_t id, std::string ad, std::string adres, std::string telefon)
    : varlik(id), _ad(ad), _adres(adres), _telefon(telefon) {}

std::string Yayinevi::get_ad() const {
    return _ad;
}