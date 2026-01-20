#pragma once
#include <string>
#include "entities/varlik.h"

class Kitap : public varlik {
public:
    Kitap(uint64_t id = 0, std::string isbn = "", std::string baslik = "",
          int yazar_id = 0, int kategori_id = 0, int yayinevi_id = 0,
          int stok = 0, int sayfa = 0);

    std::string get_isbn() const;
    std::string get_baslik() const;
    int get_stok_adedi() const;
    int get_yazar_id() const;
    int get_kategori_id() const;
    int get_yayinevi_id() const;

    void set_stok_adedi(int s);

private:
    std::string _isbn;
    std::string _baslik;
    int _yazar_id;
    int _kategori_id;
    int _yayinevi_id;
    int _stok_adedi;
    int _sayfa_sayisi;
};