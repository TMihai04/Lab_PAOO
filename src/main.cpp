#include "Truck.hpp"
#include "BadTruck.hpp"
#include <iostream>
#include <utility>

void showTruck() {
    std::cout << "--- Truck ---" << std::endl;
    // Local scope for constructor, destructor example
    {
        Truck local = Truck("TM12ABC", 10);
        local.toString();
    }

    // Copy constructor example
    Truck originalCopy = Truck("B420BOC", 5);
    originalCopy.addTrailer(1);
    originalCopy.addTrailer(2);

    Truck copy = originalCopy;

    originalCopy.addTrailer(3);
    copy.addTrailer(66);

    std::cout << "Original: "; originalCopy.toString();
    std::cout << "Copy    : "; copy.toString();

    // Move constructor example
    Truck originalMove = Truck("MM56JEF", 45);
    originalMove.addTrailer(10);
    originalMove.addTrailer(20);

    Truck moved = std::move(originalMove);

    if (originalMove.canHaveTrailers()) {
        originalMove.addTrailer(30);
    }
    moved.addTrailer(999);

    std::cout << "Original: "; originalMove.toString();
    std::cout << "Moved   : "; moved.toString();

    std::cout << "--- Truck ---" << std::endl;
}

void showBadTruck() {
    std::cout << "--- BadTruck ---" << std::endl;
    // Local scope for constructor, destructor example
    {
        BadTruck local = BadTruck("TM12ABC", 10);
        local.toString();
    }

    // Copy constructor example
    BadTruck originalCopy = BadTruck("B420BOC", 5);
    originalCopy.addTrailer(1);
    originalCopy.addTrailer(2);

    BadTruck copy = originalCopy;

    originalCopy.addTrailer(3);
    copy.addTrailer(66);

    std::cout << "Original: "; originalCopy.toString();
    std::cout << "Copy    : "; copy.toString();

    // Move constructor example
    BadTruck originalMove = BadTruck("MM56JEF", 45);
    originalMove.addTrailer(10);
    originalMove.addTrailer(20);

    BadTruck moved = std::move(originalMove);

    if (originalMove.canHaveTrailers()) {
        originalMove.addTrailer(30);
    }
    moved.addTrailer(999);

    std::cout << "!!! Due to shallow copy, one object gets deleted twice. Segmentation fault is expected !!!" << std::endl;
    std::cout << "Original: "; originalMove.toString();
    std::cout << "Moved   : "; moved.toString();
    // Due to shallow copy, one object gets deleted twice
    // NOTE: Segmentation fault is expected

    std::cout << "--- BadTruck ---" << std::endl;
}

int main() {
    showTruck();
    showBadTruck();

    return 0;
}