#include "Document.hpp"
#include <iostream>
#include <utility>

Document::Document(const std::string& title, const std::string& text)
    : title(title), content(new std::string(text)) {}

Document::~Document() {
    delete content;
}

Document::Document(const Document& rhs)
    : title(rhs.title),
      content(rhs.content ? new std::string(*rhs.content) : nullptr) {}

Document::Document(Document&& rhs) noexcept
    : title(std::move(rhs.title)), content(rhs.content) {
    rhs.content = nullptr;
}

// Careful ordering. Handles self-assignment
Document& Document::operator=(const Document& rhs) {
    std::string* pOrig = content;
    content = rhs.content ? new std::string(*rhs.content) : nullptr;
    delete pOrig;

    title = rhs.title;
    return *this;
}

// Free old resource, take new one, empty source
Document& Document::operator=(Document&& rhs) noexcept {
    if (this != &rhs) {
        delete content;
        content = rhs.content;
        rhs.content = nullptr;
        title = std::move(rhs.title);
    }
    return *this; // Item 10
}

Document& Document::operator+=(const std::string& extraText) {
    if (content) {
        *content += extraText;
    } else {
        content = new std::string(extraText);
    }
    return *this;
}

void Document::printDetails() const {
    std::cout << "Title: " << title << "\n"
              << "Content: " << (content ? *content : "[empty/moved-from]") << "\n";
}
