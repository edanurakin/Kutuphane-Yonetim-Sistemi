#ifndef PROJE_KUTUPHANESERVISI_H
#define PROJE_KUTUPHANESERVISI_H

#include "depo_tanimlari.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;

class KutuphaneServisi {
public:
    KutuphaneServisi(KitapDeposu& kDepo, UyeDeposu& uDepo, OduncDeposu& oDepo, RezervasyonDeposu& rDepo);

    void kitapEkle(string isbn, string baslik, int yazar_id, int kategori_id, int yayinevi_id, int stok, int sayfa);
    void uyeKaydet(string tc, string ad_soyad, string email, string telefon, string kayit_tarihi);

    void kitapOduncVer(int kitap_id, int uye_id);
    void iadeAl(int odunc_id);
    void rezervasyonYap(int kitap_id, int uye_id);
    void rezervasyonIptal(int rezervasyon_id);

    void gecikmisBul();
    void kitapAra(string kriter);
    void kitapDurumu(int kitap_id);
    void uyeGecmisi(int uye_id);
    void populerKitaplar(int n);
    void kategoriIstatistik();

private:
    KitapDeposu& _kitapDepo;
    UyeDeposu& _uyeDepo;
    OduncDeposu& _oduncDepo;
    RezervasyonDeposu& _rezervasyonDepo;
};

#endif