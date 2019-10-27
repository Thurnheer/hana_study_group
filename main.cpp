#include "boost/hana.hpp"
#include <string>

// 1. Give introspection capabilities to 'Person'
struct Person {
  BOOST_HANA_DEFINE_STRUCT(Person,
    (std::string, name),
    (int, age)
  );
};

int main()
{

}
