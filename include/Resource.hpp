#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include <string>

// Mock dynamically allocated resource
class Resource {
private:
    std::string name;

public:
    explicit Resource(const std::string& name);
    ~Resource();

    void use() const;
};

#endif
