#include <iostream>
#include <string>
#include "House.hpp"

int main() {
    std::string owner1 = "Alice";
    std::string owner2 = "Bob";

    // Initialization of objects
    House house1(5, 10, owner1);
    House house2(3, 6, owner2);

    std::cout << "--- House 1 ---\n";
    house1.printDetails();

    std::cout << "--- House 2 ---\n";
    house2.printDetails();

    // The compiler-generated copy constructor and copy assignment operator are explicitly deleted in the class definition.
    // Uncommenting the lines below will result in a compile-time error:

    // House house3 = house1;
    // house2 = house1;

    std::cout << "Program completed successfully without illegal copies.\n";

    return 0;
}
