# Proje 05_01: Kütüphane Yönetim Sistemi

## Proje Tanımı
Bu proje, bir kütüphanenin temel işlevlerini yöneten bir yazılım sistemidir. Sistem, kitap envanteri yönetimi, üye kaydı, kitap ödünç verme/iade işlemleri ve rezervasyon sistemini içermektedir.

Proje, **çok katmanlı mimari (3-tier architecture)** prensiplerine uygun olarak tasarlanmıştır:
- **Veri Katmanı (Entity)**: Varlık sınıfları
- **Depo Katmanı (Repository)**: Veri erişim işlemleri
- **Servis Katmanı (Service)**: İş mantığı ve koordinasyon

## Varlık Tanımları

### 1. Kitap
Kütüphanedeki kitapları temsil eder.

| Alan        | Tip    | Açıklama            |
|-------------|--------|---------------------|
| id          | int    | Benzersiz kimlik    |
| isbn        | string | ISBN numarası       |
| baslik      | string | Kitap başlığı       |
| yazar_id    | int    | Yazar referansı     |
| kategori_id | int    | Kategori referansı  |
| yayinevi_id | int    | Yayınevi referansı  |
| stok        | int    | Mevcut stok sayısı  |
| sayfa       | int    | Toplam sayfa sayısı |

### 2. Yazar
Kitap yazarlarını temsil eder.

| Alan       | Tip    | Açıklama           |
|------------|--------|--------------------|
| id         | int    | Benzersiz kimlik   |
| ad_soyad   | string | Yazarın adı soyadı |
| dogum_yili | int    | Doğum yılı         |
| ulke       | string | Ülke               |

### 3. Kategori
Kitap kategorilerini temsil eder.

| Alan     | Tip    | Açıklama            |
|----------|--------|---------------------|
| id       | int    | Benzersiz kimlik    |
| ad       | string | Kategori adı        |
| aciklama | string | Kategori açıklaması |

### 4. Yayinevi
Kitap yayınevlerini temsil eder.

| Alan    | Tip     | Açıklama         |
|---------|---------|------------------|
| id      | int     | Benzersiz kimlik |
| ad      | string  | Yayınevi adı     |
| adres   | string  | Adres            |
| telefon | string  | Telefon numarası |

### 5. Uye
Kütüphane üyelerini temsil eder.

| Alan         | Tip      | Açıklama           |
|--------------|----------|--------------------|
| id           | int      | Benzersiz kimlik   |
| tc           | string   | TC kimlik numarası |
| ad_soyad     | string   | Üye adı soyadı     |
| eposta       | string   | E-posta adresi     |
| telefon      | string   | Telefon numarası   |
| kayit_tarihi | string   | Kayıt tarihi       |

### 6. OduncAlma
Kitap ödünç alma işlemlerini temsil eder.

| Alan         | Tip     | Açıklama                          |
|--------------|---------|-----------------------------------|
| id           | int     | Benzersiz kimlik                  |
| kitap_id     | int     | Kitap referansı                   |
| uye_id       | int     | Üye referansı                     |
| odunc_tarihi | string  | Ödünç alınma tarihi               |
| iade_tarihi  | string  | Planlanan iade tarihi             |
| gercek_iade  | string  | Gerçek iade tarihi (boş olabilir) |

### 7. Rezervasyon
Kitap rezervasyonlarını temsil eder.

| Alan     | Tip    | Açıklama                       |
|----------|--------|--------------------------------|
| id       | int    | Benzersiz kimlik               |
| kitap_id | int    | Kitap referansı                |
| uye_id   | int    | Üye referansı                  |
| tarih    | string | Rezervasyon tarihi             |
| durum    | string | Durum (Aktif/İptal/Tamamlandı) |

## Varlık İlişkileri

```
Yazar (1) ──────< (n) Kitap
Kategori (1) ───< (n) Kitap
Yayinevi (1) ───< (n) Kitap
Uye (1) ────────< (n) OduncAlma
Kitap (1) ──────< (n) OduncAlma
Uye (1) ────────< (n) Rezervasyon
Kitap (1) ──────< (n) Rezervasyon
```

## Servis İşlemleri (11 Adet)

### Temel İşlemler
1. **kitapEkle(isbn, baslik, yazar_id, kategori_id, yayinevi_id, stok, sayfa)**
   - Yeni kitap kaydı oluşturur
   - ISBN benzersizliğini kontrol eder

2. **uyeKaydet(tc, ad_soyad, email, telefon, kayit_tarihi)**
   - Yeni üye kaydı oluşturur
   - TC no benzersizliğini kontrol eder

### Ödünç İşlemleri
3. **kitapOduncVer(kitap_id, uye_id)**
   - Kitabı üyeye ödünç verir
   - Stok kontrolü yapar
   - İade tarihi hesaplar (14 gün)

4. **kitapIadeAl(odunc_id)**
   - Kitabı iade alır
   - Gecikme kontrolü yapar
   - Stoku günceller

### Rezervasyon İşlemleri
5. **rezervasyonYap(kitap_id, uye_id)**
   - Kitap için rezervasyon oluşturur
   - Mevcut stok yoksa rezervasyon kabul edilir

6. **rezervasyonIptal(rezervasyon_id)**
   - Rezervasyonu iptal eder

### Sorgulama ve Raporlama
7. **gecikmisBul()**
   - Tüm gecikmiş ödünç kayıtlarını listeler

8. **uyeGecmisi(uye_id)**
   - Belirli üyenin tüm ödünç geçmişini getirir

9. **kitapAra(kriter)**
   - Başlık veya ISBN'e göre kitap arar

10. **PopulerKitaplar(n)**
   - En çok ödünç alınan kitapları listeler

11. **uyeCezaHesapla(uye_id)**
   - Üyenin gecikme cezasını hesaplar (günlük 1 TL)

## Derleme ve Çalıştırma

```bash
mkdir build && cd build
cmake ..
make
./kutuphane_sistemi
```

## Klasör Yapısı

```
05_01_KutuphaneSistemi/
├── README.md
├── GONDERIM.md
├── CMakeLists.txt
├── diagrams/
│   └── uml_class.tex
├── include/
│   ├── entities/
│   │   ├── Kategori.h
│   │   ├── Kitap.h
│   │   ├── OduncAlma.h
│   │   ├── Rezervasyon.h
│   │   ├── Uye.h
│   │   ├── varlik.h
│   │   ├── Yayinevi.h
│   │   └── Yazar.h
│   ├── repositories/
│   │   └── depo.h
│   ├── services/
│   │   └── KutuphaneServisi.h
│   ├── utils/
│   │   └── TarihUtils.h
│   └── depo_tanimlari.h       
└── src/
    ├── entities/
    │   └── (implementasyonlar)
    ├── services/
    │   └── KutuphaneServisi.cpp
    └── main.cpp
```