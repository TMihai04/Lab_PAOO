#pragma once
#include <string>

class Truck {
    private:
        std::string plate;
        int trailerCapacity;
        int size;
        int* weights;

    public:
        Truck(const std::string& id, int capacity);
        ~Truck();
        Truck(const Truck& other);
        Truck(Truck&& other) noexcept;

        void addTrailer(int weight);
        void removeTrailer(int id);
        void toString();

        bool canHaveTrailers() const { return weights != nullptr; }
};