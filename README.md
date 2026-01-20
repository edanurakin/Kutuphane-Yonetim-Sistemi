📚 Kütüphane Yönetim Sistemi (Library Management System)
Bu proje, KTÜ Bilgisayar Bilimleri 2. sınıf eğitimim kapsamında, C++ dili ve Nesne Yönelimli Programlama (OOP) prensipleri temel alınarak geliştirilmiştir. Bir kütüphanenin günlük işleyişini dijital ortamda yönetmeyi amaçlayan modüler bir sistemdir.

🚀 Öne Çıkan Özellikler
Gelişmiş Nesne Yapısı: Kitap, Üye, Yazar, Kategori ve Rezervasyon gibi varlıklar (Entities), OOP'nin kapsülleme (encapsulation) prensibiyle tasarlanmıştır.

İş Mantığı Ayrımı: Kütüphane operasyonları, merkezi bir servis katmanı (KutuphaneServisi) üzerinden yönetilerek kodun okunabilirliği ve bakımı kolaylaştırılmıştır.

Dinamik Veri Yönetimi: Veriler arasındaki ilişkiler (örneğin bir kitabın yazarı veya bir üyenin aldığı ödünç kitaplar) sınıf yapıları içerisinde modellenmiştir.

🛠️ Teknik Detaylar
Dil: C++

Mimari: Nesne Yönelimli Programlama (OOP)

Kullanılan Yapılar: Sınıflar (Classes), Kalıtım (Inheritance), Vektörler ve Modüler Proje Yapısı.

📁 Proje Yapısı
Plaintext

src/
 ├── entities/       # Varlık tanımları (Kitap, Uye, Yazar vb.)
 ├── services/       # İş mantığının (business logic) yürütüldüğü katman
 └── main.cpp        # Uygulamanın giriş ve test noktası
