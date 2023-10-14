/**
 *
 */
#ifndef OTUS_CPP_HW_04_TABSTRACTIP_H
#define OTUS_CPP_HW_04_TABSTRACTIP_H

#include <type_traits>
#include <cstdint>
#include <iostream>
#include <vector>
#include <list>
#include <sstream>

union {
    struct {
        uint64_t a: 8;
        uint64_t b: 8;
        uint64_t c: 8;
        uint64_t d: 8;
        uint64_t e: 8;
        uint64_t f: 8;
        uint64_t g: 8;
        uint64_t h: 8;
    } Octets;
    uint64_t IP;
} IP64;

template <typename T>
typename std::enable_if<std::is_scalar<T>::value, std::string>::type
print_ip(T value)
{
    std::stringstream out("");
    IP64.IP = value;
    if(typeid(value) == typeid(int8_t))
        out << IP64.Octets.a;

    if(typeid(value) == typeid(int16_t))
    {
        out
        << IP64.Octets.d << "."
        << IP64.Octets.a;
    }

    if(typeid(value) == typeid(int32_t))
    {
        out
        << IP64.Octets.d << "."
        << IP64.Octets.c << "."
        << IP64.Octets.b << "."
        << IP64.Octets.a;
    }

    if(typeid(value) == typeid(int64_t))
    {
        out
        << IP64.Octets.h << "."
        << IP64.Octets.g << "."
        << IP64.Octets.f << "."
        << IP64.Octets.e << "."
        << IP64.Octets.d << "."
        << IP64.Octets.c << "."
        << IP64.Octets.b << "."
        << IP64.Octets.a;
    }
    std::cout << out.str() << std::endl;
    return out.str();
}

template <typename T>
typename std::enable_if<!std::is_scalar_v<T>, std::string>::type
print_ip(T value)
{
    std::stringstream out("");
    if(typeid(value) != typeid(std::string))
    {
        size_t i = 0;
        for(auto item : value)
        {
            out << item;
            if (++i < value.size()) out << ".";
        }
    }
    if(typeid(value) == typeid(std::string))
    {
        for(auto item: value)
            out << item;
    }

    std::cout << out.str() << std::endl;
    return out.str();
 }

#endif //OTUS_CPP_HW_04_TABSTRACTIP_H
