#include "entities/Kategori.h"

Kategori::Kategori(uint64_t id, std::string ad, std::string aciklama)
    : varlik(id), _ad(ad), _aciklama(aciklama) {}

std::string Kategori::get_ad() const {
    return _ad;
}