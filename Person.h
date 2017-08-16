//
// Created by tombr on 16/08/2017.
//

#ifndef SMARTPOINTERS_PERSON_H
#define SMARTPOINTERS_PERSON_H



#include <string>
#include "Resource.h"
#include <memory>

class Person {
private:
    std::string first_name;
    std::string last_name;
    int arbitrary_number;
    std::shared_ptr<Resource> pResource;
public:
    Person(std::string first, std::string last, int arbitrary);
   // ~Person(); // not needed in share_ptr
    //Person(const Person& p); // shared_ptr does not need copy constructor!!!!
    std::string Get_name()const;
    std::string Set_name(std::string name);
    int Get_number() const { return  arbitrary_number; } // by adding word const after function name allow us to use this function with const objects as we guarantee that it will not change anything
    void Set_number(int number) { arbitrary_number = number; }
    bool operator< (const Person& p) const;
    bool operator< (int i) const ;
    int operator+ (const Person& p) const;
    int operator- (const Person& p) const;
    friend bool operator< (int i, const Person& p);
    //Person&operator= (const Person& p); // this is copy assignment operator
    // same reason as with copy constructor we don't need this as shared_ptr will deal with this
    void Add_Resource();
    std::string Get_resource_name() const { return pResource->Get_Name();}
};
bool operator<(int i, const Person& p);



#endif //SMARTPOINTERS_PERSON_H
