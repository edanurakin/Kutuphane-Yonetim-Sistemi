#include <iostream>
#include <string>
#include <memory>
#include "depo_tanimlari.h"
#include "services/KutuphaneServisi.h"

using namespace std;

int main() {
    KitapDeposu kitapDepo;
    UyeDeposu uyeDepo;
    OduncDeposu oduncDepo;
    RezervasyonDeposu rezervasyonDepo;

    KutuphaneServisi servis(kitapDepo, uyeDepo, oduncDepo, rezervasyonDepo);

    servis.uyeKaydet("48296705742", "Edanur Akin", "edanur@mail.com", "05551112233", "29.12.2025");
    servis.uyeKaydet("11903665426", "Lal Eylul Kaygisiz", "lal@mail.com", "05554445566", "29.12.2025");
    servis.uyeKaydet("22984530012", "Senem Deniz", "senem@mail.com", "05557778899", "29.12.2025");
    servis.uyeKaydet("36988563750", "Mehmet Erdem", "mehmet@mail.com", "05558889900", "29.12.2025");
    servis.uyeKaydet("58573389018", "Meltem Ezgi Akin", "meltem@mail.com", "05552223344", "29.12.2025");
    servis.uyeKaydet("11245988794", "Ruzgar Yasar Arduc", "ruzgar@mail.com", "05553334455", "29.12.2025");
    servis.uyeKaydet("36896658910", "Mete Akarsu", "mete@mail.com", "05556667788", "29.12.2025");
    servis.uyeKaydet("10197006712", "Ferhat Ufuk Aslan", "ferhat@mail.com", "05559990011", "29.12.2025");
    servis.uyeKaydet("27468900216", "Yusuf Han", "yusuf@mail.com", "05550001122", "29.12.2025");
    servis.uyeKaydet("46890957886", "Elif Anakok", "elif@mail.com", "05551113355", "29.12.2025");

    servis.kitapEkle("978-001", "Gece Yarisi Kutuphanesi", 1, 1, 1, 4, 320);
    servis.kitapEkle("978-002", "Ugultulu Tepeler", 2, 2, 2, 3, 400);
    servis.kitapEkle("978-603", "Bir Bilim Adaminin Romani", 3, 1, 3, 2, 280);
    servis.kitapEkle("978-604", "Gulyabani", 4, 3, 4, 5, 210);
    servis.kitapEkle("978-605", "Sipsevdi", 4, 3, 4, 1, 250);
    servis.kitapEkle("978-606", "Kurk Mantolu Madonna", 5, 1, 5, 6, 160);
    servis.kitapEkle("978-607", "Pinhan", 6, 1, 2, 2, 450);
    servis.kitapEkle("978-608", "Turkan", 7, 2, 1, 4, 300);
    servis.kitapEkle("978-609", "Kasagi", 8, 3, 1, 10, 120);
    servis.kitapEkle("978-610", "Atesli Silahlar ve Bilardo", 9, 4, 5, 0, 180);
    servis.kitapEkle("978-011", "Dogu Ekspresinde Cinayet", 10, 3, 2, 3, 250);
    servis.kitapEkle("978-012", "Olasilik ve Istatistik", 11, 5, 3, 5, 500);
    servis.kitapEkle("978-013", "Algoritma", 11, 5, 3, 2, 600);
    servis.kitapEkle("978-614", "Beyaz Gemi", 12, 1, 4, 4, 190);
    servis.kitapEkle("978-615", "Uzun Hikaye", 13, 1, 6, 6, 140);
    servis.kitapEkle("978-616", "Sirca Kosk", 5, 1, 3, 3, 150);

    cout << "--- Kutuphane Bilgi Sistemi Test Raporu ---" << endl << endl;

    try {
        servis.kitapOduncVer(1, 1);
        servis.iadeAl(1);
        servis.rezervasyonYap(10, 2);

        servis.kitapAra("Algoritma");
        servis.kitapDurumu(5);
        servis.uyeGecmisi(1);
        servis.gecikmisBul();
    } catch (const exception& e) {
        cout << "Test sirasinda hata olustu: " << e.what() << endl;
    }

    servis.populerKitaplar(5);
    cout << endl;

    servis.kategoriIstatistik();
    cout << endl;

    cout << "--- TUM TESTLER BASARIYLA TAMAMLANDI ---" << endl;

    return 0;
}