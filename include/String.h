//
// Created by Magnus Rødseth on 22/07/2021.
//

#ifndef STRING_STRING_H
#define STRING_STRING_H


static const int DEFAULT_ARRAY_SIZE = 10;

#include <string>
#include <ostream>

class String {
    size_t m_count;
    char *m_characters = new char[DEFAULT_ARRAY_SIZE];

    // Resizes the internal char array to the provided size, keeping the current char array's content.
    void m_resize(size_t size);

    // Compares this string value with another string value.
    // Returns 1 if this string value is greater than the other string value.
    // Returns 0 if this string value is equal to the other string value.
    // Returns -1 if this string value is less than the other string value.
    int m_compare(String other) const;

    // Checks if this string value is empty.
    bool m_isEmpty() const;

public:
    // Initializes a new string with the provided value.
    String(const std::string &value);

    // Initializes a new empty string with a size of DEFAULT_ARRAY_SIZE.
    String();

    // Gets the number of m_characters in a string, including spaces and punctuation.
    int length() const;

    // Checks this string with another string for equality based on string value.
    bool operator==(const String &other) const;

    // Checks this string with another string for inequality based on string value.
    bool operator!=(const String &other) const;

    // Checks this string with another string for "less than" based on string value.
    bool operator<(const String &other) const;

    // Checks this string with another string for "less than or equal to" based on string value.
    bool operator<=(const String &other) const;

    // Checks this string with another string for "greater than" based on string value.
    bool operator>(const String &other) const;

    // Checks this string with another string for "greater than or equal to" based on string value.
    bool operator>=(const String &other) const;

    // Gets the character at the given index.
    char operator[](int index) const;

    // Sets the character at the given index.
    char &operator[](int index);

    // Appends a string value to this string.
    String &operator+=(const String &other);

    // Gets the index of the first occurrence of a given value, or -1 if it is not found.
    int find(String value);

    // Returns a new string consisting of the characters from this string starting
    // at the position start and continuing for length characters.
    // If start is negative, it will cause a run-time error.
    // If start is past the end of the string, it will return an empty string (e.g., "").
    // If length is longer than the number of characters from the start position
    // to the end of the string, it truncates to the end of the string.
    // If length is negative, then the behavior is undefined,
    // so make sure that length is always non-negative.
    // If you leave off the second argument, the number of characters from the
    // starting position to the end of the receiver string is assumed.
    String substring(int start, int length);

    // Inserts string value at position start within this string,
    // shifting the remaining characters of this string value over.
    void insert(int start, String string);

    // Removes a total of length characters from this string value,
    // starting at the position start, replacing them with a copy of the provided string value.
    void replace(int start, String value);

    // Returns a pointer to an array that contains a null-terminated sequence of
    // characters (i.e., a C-string) representing the current value of the string object.
    // This array includes the same sequence of characters that make up the value
    // of the string object plus an additional terminating null-character ('\0') at the end.
    char *toCString();

    friend std::ostream &operator<<(std::ostream &os, const String &string);
};


#endif //STRING_STRING_H
