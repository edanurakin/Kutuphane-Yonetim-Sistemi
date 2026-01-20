#pragma once
#include <cstdint>

class varlik
{
public:
    varlik(uint64_t id);
    varlik(const varlik& varlik);
    uint64_t get_id();

protected:
    uint64_t _id;
};