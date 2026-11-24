#ifndef MUTEX_LOCK_HPP
#define MUTEX_LOCK_HPP

#include <memory>
#include <string>

// Simulated C-style Mutex API
struct Mutex {
    std::string id;
    bool isLocked = false;
};

void lock(Mutex* pm);
void unlock(Mutex* pm);

// A unique lock should not be copied; doing so would risk unlocking twice.
class UniqueLock {
private:
    Mutex* mutexPtr;

public:
    explicit UniqueLock(Mutex* pm);
    ~UniqueLock();

    // Disallow copying
    UniqueLock(const UniqueLock&) = delete;
    UniqueLock& operator=(const UniqueLock&) = delete;
};

// Reference-count the underlying resource. Uses std::shared_ptr with a custom deleter (unlock)
class SharedLock {
private:
    std::shared_ptr<Mutex> mutexPtr;

public:
    explicit SharedLock(Mutex* pm);
    long useCount() const;
    // Compiler-generated copy constructor, copy assignment, and destructor automatically manage the shared_ptr reference count.
};

#endif
