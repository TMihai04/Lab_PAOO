#include "MutexLock.hpp"
#include <iostream>

void lock(Mutex* pm) {
    if (pm) {
        pm->isLocked = true;
        std::cout << "[Mutex] Locked: " << pm->id << "\n";
    }
}

void unlock(Mutex* pm) {
    if (pm) {
        pm->isLocked = false;
        std::cout << "[Mutex] Unlocked: " << pm->id << "\n";
    }
}

// --- UniqueLock implementation ---
UniqueLock::UniqueLock(Mutex* pm) : mutexPtr(pm) {
    lock(mutexPtr);
}

UniqueLock::~UniqueLock() {
    unlock(mutexPtr);
}

// --- SharedLock implementation ---
SharedLock::SharedLock(Mutex* pm)
    : mutexPtr(pm, unlock)
{
    lock(mutexPtr.get());
}

long SharedLock::useCount() const {
    return mutexPtr.use_count();
}
