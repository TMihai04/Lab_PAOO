#pragma once
#ifndef SECURE_DOCUMENT_HPP
#define SECURE_DOCUMENT_HPP

#include "Document.hpp"

class SecureDocument : public Document {
private:
    int securityLevel;

public:
    SecureDocument(const std::string& title, const std::string& text, int level);
    ~SecureDocument() override = default;

    // Copy constructor must copy both base and derived parts
    SecureDocument(const SecureDocument& rhs);

    // Move constructor
    SecureDocument(SecureDocument&& rhs) noexcept;

    // Copy assignment must copy base part and local members
    SecureDocument& operator=(const SecureDocument& rhs);

    // Move assignment
    SecureDocument& operator=(SecureDocument&& rhs) noexcept;

    void printDetails() const override;
};

#endif
