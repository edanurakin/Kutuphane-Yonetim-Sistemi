cmake_minimum_required(VERSION 3.10)
project(KutuphaneSistemi)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)


set(SOURCE_FILES
        src/main.cpp
        src/services/KutuphaneServisi.cpp
        src/entities/Kitap.cpp
        src/entities/Uye.cpp
        src/entities/OduncAlma.cpp
        src/entities/Rezervasyon.cpp
        src/entities/Yazar.cpp
        src/entities/Yayinevi.cpp
        src/entities/Kategori.cpp
        src/entities/varlik.cpp

)

add_executable(kutuphane_sistemi ${SOURCE_FILES})
