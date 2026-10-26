#include "BadTruck.hpp"
#include <iostream>
#include <string>
#include <utility>

BadTruck::BadTruck(const std::string& id, int capacity)
    : 
    plate(id), 
    trailerCapacity(capacity), 
    weights(new int[capacity]), 
    size(0) {
    std::cout << "Created new BadTruck: " << this->plate << std::endl;
}

BadTruck::~BadTruck() {
    delete[] this->weights;
    this->weights = nullptr;
    std::cout << "Deleted a BadTruck '" << this->plate << "' from existence" << std::endl;
}

void BadTruck::addTrailer(int weight) {
    if (this->size >= this->trailerCapacity) {
        std::cout << "[" << this->plate << "] Could not add trailer " << weight << std::endl;
        return;
    }

    this->weights[this->size++] = weight;
    std::cout << "[" << this->plate << "] Added trailer " << weight << std::endl;
}

void BadTruck::removeTrailer(int id) {
    if (this->size <= 0 || id >= this->size) {
        std::cout << "[" << this->plate << "] Could not remove trailer " << id << std::endl;
        return;
    }

    for (int i = id; i < this->size; i++) {
        this->weights[i] = this->weights[i + 1];
    }
    this->size--;

    std::cout << "[" << this->plate << "] Removed trailer " << id << std::endl;
}

void BadTruck::toString() {
    std::cout << "BadTruck(plate = '" << this->plate << "', trailerCapacity = " << this->trailerCapacity << ", size = " << this->size << ", weights = [";

    for (int i = 0; i < this->size; i++) {
        std::cout << this->weights[i];
        if (i < size - 1) std::cout << ", ";
    }

    std::cout << "])" << std::endl;
}