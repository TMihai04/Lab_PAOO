#pragma once
#include <string>

class BadTruck {
    private:
        std::string plate;
        int trailerCapacity;
        int size;
        int* weights;

    public:
        BadTruck(const std::string& id, int capacity);
        ~BadTruck();

        void addTrailer(int weight);
        void removeTrailer(int id);
        void toString();

        bool canHaveTrailers() const { return weights != nullptr; }
};