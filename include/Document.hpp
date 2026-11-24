#pragma once
#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <string>

class Document {
private:
    std::string title;
    std::string* content; // Heap-allocated resource

public:
    Document(const std::string& title, const std::string& text);
    virtual ~Document();

    Document(const Document& rhs);
    Document(Document&& rhs) noexcept;

    // Copy assignment
    Document& operator=(const Document& rhs);

    // Move assignment
    Document& operator=(Document&& rhs) noexcept;

    // Compound assignment
    Document& operator+=(const std::string& extraText);

    virtual void printDetails() const;
};

#endif
