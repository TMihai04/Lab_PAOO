#include "Resource.hpp"
#include <iostream>

Resource::Resource(const std::string& name) : name(name) {
    std::cout << "[Resource] Acquired: " << name << "\n";
}

Resource::~Resource() {
    std::cout << "[Resource] Released: " << name << "\n";
}

void Resource::use() const {
    std::cout << "[Resource] Using: " << name << "\n";
}
