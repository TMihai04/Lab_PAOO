#include "Truck.hpp"
#include <iostream>
#include <string>
#include <utility>

Truck::Truck(const std::string& id, int capacity)
    : 
    plate(id), 
    trailerCapacity(capacity), 
    weights(new int[capacity]), 
    size(0) {
    std::cout << "Created new truck: " << this->plate << std::endl;
}

Truck::~Truck() {
    delete[] this->weights;
    this->weights = nullptr;
    std::cout << "Deleted a truck '" << this->plate << "' from existence" << std::endl;
}

Truck::Truck(const Truck& other)
    : 
    plate(other.plate + "(c)"), 
    trailerCapacity(other.trailerCapacity), 
    size(other.size), 
    weights(new int[other.size]) {
    for (int i = 0; i < other.size; i++) {
        this->weights[i] = other.weights[i];
    }

    std::cout << "Copy-pasted truck '" << other.plate << "'" << std::endl;
}

Truck::Truck(Truck&& other) noexcept
    : 
    plate(std::move(other.plate) + "(m)"), 
    trailerCapacity(other.trailerCapacity),
    size(other.size),
    weights(other.weights) {
        other.trailerCapacity = 0;
        other.size = 0;
        other.weights = nullptr;

        std::cout << "Moved a truck: " << this->plate << std::endl;
}

void Truck::addTrailer(int weight) {
    if (this->size >= this->trailerCapacity) {
        std::cout << "[" << this->plate << "] Could not add trailer " << weight << std::endl;
        return;
    }

    this->weights[this->size++] = weight;
    std::cout << "[" << this->plate << "] Added trailer " << weight << std::endl;
}

void Truck::removeTrailer(int id) {
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

void Truck::toString() {
    std::cout << "Truck(plate = '" << this->plate << "', trailerCapacity = " << this->trailerCapacity << ", size = " << this->size << ", weights = [";

    for (int i = 0; i < this->size; i++) {
        std::cout << this->weights[i];
        if (i < size - 1) std::cout << ", ";
    }

    std::cout << "])" << std::endl;
}