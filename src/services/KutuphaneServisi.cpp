#include <iostream>
#include <string>
#include <memory>
#include "services/KutuphaneServisi.h"
#include "utils/TarihUtils.h"

using namespace std;

KutuphaneServisi::KutuphaneServisi(KitapDeposu& kDepo, UyeDeposu& uDepo, OduncDeposu& oDepo, RezervasyonDeposu& rDepo)
    : _kitapDepo(kDepo), _uyeDepo(uDepo), _oduncDepo(oDepo), _rezervasyonDepo(rDepo) {}

void KutuphaneServisi::kitapEkle(string isbn, string baslik, int yazar_id, int kategori_id, int yayinevi_id, int stok, int sayfa) {
    auto yeni_id = _kitapDepo.bir_sonraki_idyi_al();
    auto yeni_kitap = make_shared<Kitap>(yeni_id, isbn, baslik, yazar_id, kategori_id, yayinevi_id, stok, sayfa);
    _kitapDepo.ekle(yeni_kitap);
}

void KutuphaneServisi::uyeKaydet(string tc, string ad_soyad, string email, string telefon, string kayit_tarihi) {
    auto yeni_id = _uyeDepo.bir_sonraki_idyi_al();
    auto yeni_uye = make_shared<Uye>(yeni_id, tc, ad_soyad, email, telefon, kayit_tarihi);
    _uyeDepo.ekle(yeni_uye);
}

void KutuphaneServisi::kitapOduncVer(int kitap_id, int uye_id) {
    auto kitap = _kitapDepo.getir(kitap_id);
    auto uye = _uyeDepo.getir(uye_id);

    if (kitap == nullptr || uye == nullptr) {
        cout << "Hata: Kitap veya Uye bulunamadi!" << endl;
        return;
    }

    if (kitap->get_stok_adedi() <= 0) {
        cout << "Hata: Kitap stokta yok!" << endl;
        return;
    }

    kitap->set_stok_adedi(kitap->get_stok_adedi() - 1);
    auto yeni_id = _oduncDepo.bir_sonraki_idyi_al();
    string bugun = TarihUtils::bugunTarihi();
    string iade = TarihUtils::gunEkle(bugun, 14);

    auto odunc = make_shared<OduncAlma>(yeni_id, kitap_id, uye_id, bugun, iade, "");
    _oduncDepo.ekle(odunc);
    cout << "Basarili: '" << kitap->get_baslik() << "' verildi." << endl;
}

void KutuphaneServisi::iadeAl(int odunc_id) {
    auto odunc = _oduncDepo.getir(odunc_id);
    if (odunc == nullptr) {
        cout << "Hata: Gecersiz odunc kaydi!" << endl;
        return;
    }

    auto kitap = _kitapDepo.getir(odunc->get_kitap_id());
    if (kitap != nullptr) {
        kitap->set_stok_adedi(kitap->get_stok_adedi() + 1);
        cout << "Kitap '" << kitap->get_baslik() << "' iade alindi." << endl;
    }
}

void KutuphaneServisi::rezervasyonYap(int kitap_id, int uye_id) {
    auto kitap = _kitapDepo.getir(kitap_id);
    auto uye = _uyeDepo.getir(uye_id);

    if (kitap == nullptr || uye == nullptr) {
        cout << "Hata: Kitap veya Uye bulunamadi!" << endl;
        return;
    }

    auto yeni_id = _rezervasyonDepo.bir_sonraki_idyi_al();
    auto rez = make_shared<Rezervasyon>(yeni_id, kitap_id, uye_id, TarihUtils::bugunTarihi(), "Beklemede");
    _rezervasyonDepo.ekle(rez);
    cout << "Rezervasyon olusturuldu: " << kitap->get_baslik() << endl;
}

void KutuphaneServisi::kitapAra(string kriter) {
    auto sonuclar = _kitapDepo.arama([kriter](const shared_ptr<Kitap>& k) {
        return k->get_baslik().find(kriter) != string::npos;
    });

    cout << "--- Arama Sonuclari ---" << endl;
    for (const auto& k : sonuclar) {
        cout << "ID: " << k->get_id() << " | " << k->get_baslik() << endl;
    }
}

void KutuphaneServisi::kitapDurumu(int kitap_id) {
    auto kitap = _kitapDepo.getir(kitap_id);
    if (kitap != nullptr) {
        cout << "Kitap: " << kitap->get_baslik() << " | Stok: " << kitap->get_stok_adedi() << endl;
    }
}

void KutuphaneServisi::uyeGecmisi(int uye_id) {
    auto gecmis = _oduncDepo.arama([uye_id](const auto& o) { return o->get_uye_id() == (uint64_t)uye_id; });
    cout << "--- Uye Gecmisi (ID: " << uye_id << ") ---" << endl;
    for (const auto& o : gecmis) {
        auto kitap = _kitapDepo.getir(o->get_kitap_id());
        if (kitap != nullptr) cout << "- " << kitap->get_baslik() << endl;
    }
}

void KutuphaneServisi::gecikmisBul() {
    cout << "--- Gecikmis Kayitlar ---" << endl;
}

void KutuphaneServisi::populerKitaplar(int n) {
    auto tum_kitaplar = _kitapDepo.tumunu_getir();
    cout << "--- Populer Kitaplar ---" << endl;
    for (int i = 0; i < n && i < tum_kitaplar.size(); ++i) {
        cout << i + 1 << ". " << tum_kitaplar[i]->get_baslik() << endl;
    }
}

void KutuphaneServisi::kategoriIstatistik() {
    auto tum_kitaplar = _kitapDepo.tumunu_getir();
    cout << "Toplam Kitap Sayisi: " << tum_kitaplar.size() << endl;
}

void KutuphaneServisi::rezervasyonIptal(int rezervasyon_id) {
    cout << "Rezervasyon iptal edildi: " << rezervasyon_id << endl;
}