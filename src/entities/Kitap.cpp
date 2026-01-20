#include "entities/Kitap.h"

Kitap::Kitap(uint64_t id, std::string isbn, std::string baslik, int yazar_id, int kategori_id, int yayinevi_id, int stok, int sayfa)
    : varlik(id), _isbn(isbn), _baslik(baslik), _yazar_id(yazar_id),
      _kategori_id(kategori_id), _yayinevi_id(yayinevi_id),
      _stok_adedi(stok), _sayfa_sayisi(sayfa) {}

std::string Kitap::get_isbn() const {
    return _isbn;
}

std::string Kitap::get_baslik() const {
    return _baslik;
}

int Kitap::get_stok_adedi() const {
    return _stok_adedi;
}

void Kitap::set_stok_adedi(int s) {
    _stok_adedi = s;
}

int Kitap::get_yazar_id() const {
    return _yazar_id;
}

int Kitap::get_kategori_id() const {
    return _kategori_id;
}

int Kitap::get_yayinevi_id() const {
    return _yayinevi_id;
}