//
// Created by tombr on 16/08/2017.
//

#ifndef SMARTPOINTERS_RESOURCE_H
#define SMARTPOINTERS_RESOURCE_H

#include <string>

class Resource {
private:
    std::string name;
public:
    Resource(std::string n); // default construcor that takes string
    ~Resource();             // Destructor
    std::string Get_Name() const { return name; }
};


#endif //SMARTPOINTERS_RESOURCE_H
