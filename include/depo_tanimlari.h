#pragma once

#include "entities/Kitap.h"
#include "entities/Uye.h"
#include "entities/Yazar.h"
#include "entities/Kategori.h"
#include "entities/Yayinevi.h"
#include "entities/OduncAlma.h"
#include "entities/Rezervasyon.h"
#include "repositories/depo.h"


using KitapDeposu = Depo<Kitap>;
using UyeDeposu = Depo<Uye>;
using YazarDeposu = Depo<Yazar>;
using KategoriDeposu = Depo<Kategori>;
using YayineviDeposu = Depo<Yayinevi>;
using OduncDeposu = Depo<OduncAlma>;
using RezervasyonDeposu = Depo<Rezervasyon>;