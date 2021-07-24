# C++ Standard Library: My implementation 📚

## Description ✏️

My custom replication of the C++ standard library. The main purpose of this repository is to become more familiar with memory management in C++.

## Support ✅

The following classes are currently implemented:

### `String` class

- `length()`. Gets the number of characters in a string, including spaces and punctuation.

- `==`, `!=`, `<`, `<=`, `>`, `>=`. Checks this string with another string for various equalities.

- `[]`. Gets or sets the character at the given index.

- `+=`. Appends a string value to this string.

- `find(String value)`. Gets the index of the first occurrence of a given value, or -1 if it is not found.

- `substring(int start, int length)`. Returns a new string consisting of the characters from this string starting at the position start and continuing for length characters.

- `insert(int start, String string)`. Inserts string value at position start within this string, shifting the remaining characters of this string value over.

- `replace(int start, String value)`. Removes a total of length characters from this string value, starting at the position start, replacing them with a copy of the provided string value.

- `toCString()`. Returns a pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string) representing the current value of the string object.

- `<<`. Prints the string content of the String object.

## Developer Information 🙋🏼‍♂️

Developed by Magnus Rødseth, Summer 2021.

## Running the application ✅

...
