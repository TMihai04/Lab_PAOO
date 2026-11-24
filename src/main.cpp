#include <iostream>
#include <utility>
#include "Document.hpp"
#include "SecureDocument.hpp"

int main() {
    std::cout << "=== Item 10: Chained Assignment & operator+= ===\n";
    Document d1("Draft", "Initial text");
    Document d2("Notes", "Some notes");
    Document d3("Final", "Approved content");

    d1 = d2 = d3; // Works because operator= returns Document& (*this)
    d1 += " [Edited]";
    std::cout << "d1 after chained assignment and +=:\n";
    d1.printDetails();

    std::cout << "\n=== Item 11: Self-Assignment Safety ===\n";
    Document& refToD1 = d1;
    d1 = refToD1; // Self-assignment via alias; careful ordering keeps content intact
    std::cout << "d1 after self-assignment:\n";
    d1.printDetails();

    std::cout << "\n=== Item 12: Copy All Parts of an Object ===\n";
    SecureDocument sec1("Top Secret", "Launch codes", 5);
    SecureDocument sec2(sec1); // Copies both Document base part and securityLevel

    SecureDocument sec3("Public", "Hello world", 1);
    sec3 = sec1; // Assigns both Document base part and securityLevel

    std::cout << "sec2 (copy constructed from sec1):\n";
    sec2.printDetails();
    std::cout << "sec3 (copy assigned from sec1):\n";
    sec3.printDetails();

    std::cout << "\n=== C++11 Move Assignment ===\n";
    SecureDocument sec4("Temp", "Temporary data", 2);
    sec4 = std::move(sec2);
    std::cout << "sec4 (moved from sec2):\n";
    sec4.printDetails();
    std::cout << "sec2 (after move):\n";
    sec2.printDetails();

    return 0;
}
