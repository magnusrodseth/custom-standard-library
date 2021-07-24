//
// Created by Magnus Rødseth on 22/07/2021.
//

#include "../include/String.h"

String::String(const std::string &value) {
    m_resize(value.length());
    m_count = value.length();

    int index = 0;
    for (char ch : value) {
        m_characters[index] = ch;
        index++;
    }
}

String::String() {
    m_count = DEFAULT_ARRAY_SIZE;
    m_characters[m_count];
}

bool String::operator==(const String &other) const {
    if (m_count != other.m_count) {
        return false;
    }

    for (int i = 0; i < m_count; i++) {
        if (m_characters[i] != other.m_characters[i]) {
            return false;
        }
    }

    return true;
}

bool String::operator!=(const String &other) const {
    return !(other == *this);
}

int String::length() const {
    return (int) m_count;
}

char String::operator[](int index) const {
    if (index < 0 || index >= m_count) {
        throw std::invalid_argument("Index is out of bounds.");
    }

    return m_characters[index];
}

char &String::operator[](int index) {
    if (index < 0 || index >= m_count) {
        throw std::invalid_argument("Index is out of bounds.");
    }

    return m_characters[index];
}

bool String::operator<(const String &other) const {
    return m_compare(other) < 0;
}

bool String::operator<=(const String &other) const {
    return m_compare(other) <= 0;
}

bool String::operator>(const String &other) const {
    return m_compare(other) > 0;
}


bool String::operator>=(const String &other) const {
    return m_compare(other) >= 0;
}

String &String::operator+=(const String &other) {
    int previousLength = this->length();

    m_resize(this->length() + other.length());

    int otherIndex = 0;
    for (int i = previousLength; i < this->length(); i++) {
        m_characters[i] = other.m_characters[otherIndex];
        otherIndex++;
    }

    return *this;
}

String String::substring(int start, int length) {
    if (start < 0 || start >= m_count) {
        throw std::invalid_argument("Start index is out of bounds.");
    }
    if (length <= 0 || length + start > m_count) {
        throw std::invalid_argument(
                "Length of slice must be greater than zero and cannot exceed length of string."
        );
    }

    std::string slice;

    for (int i = start; i < start + length; i++) {
        slice.push_back(m_characters[i]);
    }

    // Returns a new String instance with the slice parameter in the constructor
    return {slice};
}

void String::insert(int start, String string) {
    if (start < 0 || start >= m_count) {
        throw std::invalid_argument("Start index is out of bounds.");
    }
    // We should not throw if the string is empty.
    if (string.m_isEmpty()) {
        return;
    }

    // Find left and right substring
    String left = this->substring(0, start);
    String right = this->substring(start, this->length() - start);

    m_resize(this->length() + string.length());

    // Rebuild string with new string inserted
    for (int i = 0; i < left.length(); i++) {
        m_characters[i] = left.m_characters[i];
    }

    int stringIndex = 0;
    for (int i = left.length(); i < (left.length() + string.length()); i++) {
        m_characters[i] = string.m_characters[stringIndex];
        stringIndex++;
    }

    int rightIndex = 0;
    for (int i = left.length() + string.length();
         i < (left.length() + string.length() + right.length());
         i++) {
        m_characters[i] = right.m_characters[rightIndex];
        rightIndex++;
    }
}

int String::find(String value) {
    int i = 0;

    while (i < this->length()) {
        // We have a potential match
        if (m_characters[i] == value.m_characters[0]) {
            int j = 0;

            // Check rest of value for a match
            while (j <= value.length()) {

                // This means that the entire string we searched for has been found
                if (j == value.length()) {
                    return i;
                }

                if (m_characters[i + j] != value.m_characters[j]) {
                    break;
                }
                j++;
            }
        }
        i++;
    }

    return -1;
}

void String::replace(int start, String value) {
    if (start < 0 || start >= m_count) {
        throw std::invalid_argument("Start index is out of bounds.");
    }

    // In this case, we need to handle a memory leak
    if (start + value.length() > this->length()) {
        m_resize(this->length() + value.length());
    }

    int otherIndex = 0;
    for (int i = start; i < (start + value.length()); i++) {
        m_characters[i] = value.m_characters[otherIndex];
        otherIndex++;
    }
}

char *String::toCString() {
    return m_characters;
}

std::ostream &operator<<(std::ostream &os, const String &string) {
    os << string.m_characters;
    return os;
}

void String::m_resize(size_t size) {
    char *newCharacters = new char[size];

    memcpy(newCharacters, m_characters, size * sizeof(char));

    m_count = size;
    delete[] m_characters;
    m_characters = newCharacters;
}

int String::m_compare(String other) const {
    for (int i = 0; i < this->length() && i < other.length(); i++) {
        // Continue if the current characters are equal.
        if (m_characters[i] == other.m_characters[i]) {
            continue;
        }

        // If characters are unequal, return the difference.
        return m_characters[i] - other.m_characters[i];
    }

    return this->length() < other.length()
           ? other.m_characters[this->length()]
           : m_characters[other.length()];
}

bool String::m_isEmpty() const {
    return length() == 0;
}