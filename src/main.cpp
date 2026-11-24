#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>
#include "Resource.hpp"
#include "MutexLock.hpp"

void demonstrateExceptionSafety() {
    // RAII guarantees cleanup even if an exception is thrown
    auto res = std::make_unique<Resource>("TempConnection");
    res->use();
    throw std::runtime_error("Simulated failure");
    // No manual delete needed; unique_ptr destructor runs during stack unwinding
}

int main() {
    std::cout << "=== Item 13: std::unique_ptr (Single Ownership & RAII) ===\n";
    {
        auto p1 = std::make_unique<Resource>("FileBuffer");
        p1->use();

        // auto p2 = p1; // Compile error: unique_ptr cannot be copied
        auto p2 = std::move(p1); // Transfer ownership explicitly
        std::cout << "p1 is now " << (p1 ? "valid" : "null") << "\n";
        p2->use();
    } // p2 leaves scope -> FileBuffer automatically released

    std::cout << "\n=== Item 13: Exception Safety with RAII ===\n";
    try {
        demonstrateExceptionSafety();
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    std::cout << "\n=== Item 13: std::shared_ptr (Shared Ownership) ===\n";
    {
        auto s1 = std::make_shared<Resource>("SharedCache");
        std::cout << "use_count: " << s1.use_count() << "\n";
        {
            auto s2 = s1; // Both own the resource
            std::cout << "use_count after copy: " << s1.use_count() << "\n";
            s2->use();
        } // s2 destroyed, but resource stays alive
        std::cout << "use_count after inner scope: " << s1.use_count() << "\n";
    } // Last owner (s1) destroyed -> SharedCache released

    std::cout << "\n=== Item 14: Prohibit Copying (UniqueLock) ===\n";
    Mutex m1{"DB_Mutex"};
    {
        UniqueLock lock1(&m1);
        // UniqueLock lock2(lock1); // Compile error: copy constructor is deleted
        std::cout << "Inside critical section (DB_Mutex)...\n";
    } // lock1 leaves scope -> DB_Mutex unlocked automatically

    std::cout << "\n=== Item 14: Reference-Counted Copying (SharedLock) ===\n";
    Mutex m2{"Log_Mutex"};
    {
        SharedLock sl1(&m2);
        std::cout << "SharedLock count: " << sl1.useCount() << "\n";
        {
            SharedLock sl2(sl1); // Allowed: both share ownership of the lock
            std::cout << "SharedLock count after copy: " << sl1.useCount() << "\n";
        } // sl2 destroyed -> mutex stays locked
        std::cout << "SharedLock count after inner scope: " << sl1.useCount() << "\n";
    } // Last copy (sl1) destroyed -> custom deleter calls unlock(&m2)

    return 0;
}
