//
// Created by tombr on 16/08/2017.
//


#include "Person.h"
Person::Person(std::string first, std::string last, int arbitrary):
        first_name(first), last_name(last), arbitrary_number(arbitrary)// is not required as well  pResource(nullptr) - it will automatically initialize to empty
{}
//  pResource(nullptr) we do this if this resource is optional (nullptr) if I have resource then
// pointer points where is the resource


// Below copy constructor is not needed as we are experimenting now with shared_ptr!!
/*Person::Person(const Person& p): // this is COPY CONSTRUCTOR
        first_name(p.first_name), last_name(p.last_name), arbitrary_number(p.arbitrary_number), pResource(new Resource(p.pResource->Get_Name())) {}
// what we are doing here is we are creating new resource and we provide p.Resource->Get_Name*/

/*
Person::~Person() {

    // delete pResource; // share_ptr does not need delete inside destructor as this will be taken care automatically
}
*/

std::string Person::Get_name()const {
    return first_name + " " + last_name;
}

std::string Person::Set_name(std::string name){
    return first_name = name;
}

bool Person::operator<(const Person& p) const {
    return arbitrary_number < p.arbitrary_number;
}

bool Person::operator<(int i) const {
    return arbitrary_number < i;
}

bool operator< (int i, const Person& p)  { // because this is not member function we don't put const at the end!!!!
    return i < p.Get_number();
}

int Person::operator + (const  Person& p) const{
    return arbitrary_number + p.arbitrary_number;
}

int Person::operator-(const Person &p) const {
    return arbitrary_number - p.arbitrary_number;
}

// We have removed this as with copy constructor this is not required by shared_ptr
/*
Person& Person::operator= (const Person& p){ // This is assignment constructor!!!
    first_name = p.first_name;
    last_name = p.last_name;
    arbitrary_number = p.arbitrary_number;
    delete pResource; // by doing this we are ensuring that memory which was allocated by original person will be deleted before we assign this to new person!!!
    pResource = new Resource(p.pResource->Get_Name());

    return *this; //  'this' is a pointer to THE object,
    // because we are returning reference to the object we have to dereference it by adding '*' (return type Person&)
}
*/

void Person::Add_Resource() {
    //delete pResource; // this line is replaced by
    pResource.reset();
    // if I have only nullptr deleting will not be harmful however, if I have 2 person constructed in main, without this
    // i will be only able to delete last person created. First will remain on heap and its memory leak

    //pResource = new Resource("Resource for " + Get_name()); // this line is replaced by
    pResource = std::make_shared<Resource>("Resource for " + Get_name());
}