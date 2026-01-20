#ifndef DEPO_H
#define DEPO_H

#include <memory>
#include <vector>
#include <functional>
#include "../entities/varlik.h"

using namespace std;

template <typename Varlik>
class Depo {
public:
    using Ptr = shared_ptr<Varlik>;
    using Elemanlar = vector<Ptr>;

    void ekle(const Ptr& eleman) {
        if (eleman != nullptr) _elemanlar.push_back(eleman);
    }

    Ptr getir(int id) {
        for (const auto& e : _elemanlar) {
            if (e->get_id() == id) return e;
        }
        return nullptr;
    }

    Elemanlar arama(function<bool(const Ptr&)> kriter) {
        Elemanlar sonuclar;
        for (const auto& e : _elemanlar) {
            if (kriter(e)) sonuclar.push_back(e);
        }
        return sonuclar;
    }

    uint64_t bir_sonraki_idyi_al() { return ++_id_sayaci; }
    Elemanlar tumunu_getir() { return _elemanlar; }

private:
    Elemanlar _elemanlar;
    uint64_t _id_sayaci = 0;
};

#endif