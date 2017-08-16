#include <iostream>
#include "Person.h"
#include <string>

int main() {

    Person John("John", "Snow", 345);
    John.Add_Resource();
    John.Set_name("Miki");
    John.Add_Resource();
    Person John2 = John;
    John = John2;
    std::string s1 = John.Get_resource_name();
    return 0;
}