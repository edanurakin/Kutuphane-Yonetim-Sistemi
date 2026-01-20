#include "entities/Rezervasyon.h"

Rezervasyon::Rezervasyon(uint64_t id, uint64_t kitap_id, uint64_t uye_id, std::string tarih, std::string durum)
    : varlik(id), _kitap_id(kitap_id), _uye_id(uye_id), _rezerv_tarihi(tarih), _durum(durum) {}