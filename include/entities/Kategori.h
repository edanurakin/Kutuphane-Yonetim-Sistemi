#pragma once
#include <string>
#include "entities/varlik.h"

class Kategori : public varlik {
public:
    Kategori(uint64_t id = 0, std::string ad = "", std::string aciklama = "");

    std::string get_ad() const;

private:
    std::string _ad;
    std::string _aciklama;
};