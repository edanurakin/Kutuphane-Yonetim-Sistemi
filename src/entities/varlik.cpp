#include "entities/varlik.h"

varlik::varlik(uint64_t id)
    : _id(id){}

varlik::varlik(const varlik& varlik)
{
    _id = varlik._id;
}

uint64_t varlik::get_id()
{
    return _id;
}