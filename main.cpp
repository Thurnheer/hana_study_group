#include "boost/hana.hpp"
#include <iostream>
#include <string>

template<typename T>
struct meta {
    static constexpr std::string& get_name() { return T::class_name; }
};

#define TYPE_NAME(type) \
    template<>struct meta<type> { \
        static constexpr const char* class_name = #type; \
        static constexpr const char* get_name() { return class_name; } \
    };

using PrimaryKey = unsigned int;

namespace h = boost::hana;

struct Person {
  BOOST_HANA_DEFINE_STRUCT(Person,
    (std::string, name),
    (int, age)
  );
};

TYPE_NAME(Person)  // TODO do this more elegant

struct Car {
  BOOST_HANA_DEFINE_STRUCT(Car,
    (std::string, type),
    (std::string, model),
    (int, year),
    (int, mfk)
  );
};

TYPE_NAME(Car)  // TODO do this more elegant

struct writer {
    auto operator()(const std::string& value) {
        return std::string(" TEXT");
    }
    auto operator()(const int& value) {
        return std::string(" INTEGER");
    }
};

template<typename T>
auto update(const T& value)
{

}

template<typename T>
auto create(const T& value)
{
    std::string result("create table ");
    result += meta<T>::get_name();
    result += " (";
    
    //h::zip(h::keys(value), value);

    h::for_each(h::keys(value), [&](auto key) {
        writer w;
        result += key.c_str();
        result += w(h::at_key(value, key));
        //if(h::at_key(value, key) != h::at(value, h::sizeof_(value)))
        result += ", ";
    });
    result.pop_back();
    result.pop_back();
    result += ");";
    return result;
}


int main()
{
    Person p;

    std::cout << "creating table: \n";
    Person table;
    std::cout << create(table);

    Car c;

    std::cout << "Car: \n";
    std::cout << create(c);
}
