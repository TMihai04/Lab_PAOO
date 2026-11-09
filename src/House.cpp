#include "House.hpp"
#include <iostream>

// Initialization list used. Order matches the declaration order in the header.
House::House(int rooms, int capacity, std::string& owner)
:   numRooms(rooms), 
    maxCapacity(capacity), 
    ownerName(owner) { }

void House::printDetails() const {
    std::cout << "House owned by: " << ownerName << "\n"
              << "Rooms: " << numRooms << "\n"
              << "Capacity: " << maxCapacity << " people\n\n";
}
