#include "entities/Yazar.h"

Yazar::Yazar(uint64_t id, std::string ad_soyad, int dogum_yili, std::string ulke)
    : varlik(id), _ad_soyad(ad_soyad), _dogum_yili(dogum_yili), _ulke(ulke) {}

std::string Yazar::get_ad_soyad() const {
    return _ad_soyad;
}