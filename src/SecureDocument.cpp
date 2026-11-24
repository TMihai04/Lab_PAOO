#include "SecureDocument.hpp"
#include <iostream>
#include <utility>

SecureDocument::SecureDocument(const std::string& title, const std::string& text, int level)
    : Document(title, text), securityLevel(level) {}

SecureDocument::SecureDocument(const SecureDocument& rhs)
    : Document(rhs), securityLevel(rhs.securityLevel) {}

SecureDocument::SecureDocument(SecureDocument&& rhs) noexcept
    : Document(std::move(rhs)), securityLevel(rhs.securityLevel) {
    rhs.securityLevel = 0;
}

SecureDocument& SecureDocument::operator=(const SecureDocument& rhs) {
    Document::operator=(rhs); // Copy base class part
    securityLevel = rhs.securityLevel; // Copy derived class part
    return *this;
}

SecureDocument& SecureDocument::operator=(SecureDocument&& rhs) noexcept {
    if (this != &rhs) {
        Document::operator=(std::move(rhs));
        securityLevel = rhs.securityLevel;
        rhs.securityLevel = 0;
    }
    return *this;
}

void SecureDocument::printDetails() const {
    Document::printDetails();
    std::cout << "Security Level: " << securityLevel << "\n";
}
