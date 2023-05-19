/*Create a library of the following functions:
﻿﻿int mystrlen(const char * str); - the function determines the length of the line
﻿﻿char * mystrcpy (char * str1, const char * str2); - the function copies the string str2 y str1 and returns
pointer to str1
char * mystrcat (char * str1, const char * str2); - the function joins string str2 to string str1.
The function returns a pointer to the first string of str1
char * mystrchr (char * str, char s); - the function searches for character 5 in the string str. The function returns a pointer to the first occurrence of a character in a string, otherwise - 0.
char * mystrstr (char * str1, char * str2); - the function searches for the substring str2 in the string str1. The function returns a pointer to the first occurrence of the substring str2 in the string str1, otherwise
case - 0.*/

#include <iostream>
#include <cstring>

using namespace std;

int myStrlen(const char* str);
char* myStrcpy(char* str1, const char* str2);
char* myStrcat(char* str1, const char* str2);
const char* myStrchr(const char* str, char s);
const char* myStrstr(const char* str1, const char* str2);

int main()
{
    const char* str1 = "Hello";
    const char* str2 = " World";
    char buffer[50];

    // Test myStrlen
    int length = myStrlen(str1);
    cout << "Length of str1: " << length << endl;

    // Test myStrcpy
    char* copiedStr = myStrcpy(buffer, str1);
    cout << "Copied string: " << copiedStr << endl;

    // Test myStrcat
    char* concatenatedStr = myStrcat(buffer, str2);
    cout << "Concatenated string: " << concatenatedStr << endl;

    // Test myStrchr
    char searchChar = 'o';
    const char* foundChar = myStrchr(buffer, searchChar);
    if (foundChar != nullptr)
        cout << "Found character '" << searchChar << "' at position: " << (foundChar - buffer) << endl;
    else
        cout << "Character '" << searchChar << "' not found." << endl;

    // Test myStrstr
    const char* searchString = "World";
    const char* foundStr = myStrstr(buffer, searchString);
    if (foundStr != nullptr)
        cout << "Found substring '" << searchString << "' at position: " << (foundStr - buffer) << endl;
    else
        cout << "Substring '" << searchString << "' not found." << endl;

    return 0;
}

// Function to determine the length of a string
int myStrlen(const char* str)
{
    int length = 0;

    // Loop until the null terminator is reached
    while (str[length] != '\0')    {

        ++length; // Increment the length for each character in the string
    }
    return length; // Return the length of the string
}

// Function to copy a string from str2 to str1 and return a pointer to str1
char* myStrcpy(char* str1, const char* str2)
{
    char* original = str1; // Save the original starting address of str1

    while ((*str1++ = *str2++) != '\0');

    // Copy each character from str2 to str1 until the null terminator is reached
    // Post-increment both pointers to move to the next character
    return original; // Return the pointer to the beginning of str1
}

// Function to concatenate str2 to str1 and return a pointer to str1
char* myStrcat(char* str1, const char* str2)
{
    char* original = str1; // Save the original starting address of str1

    while (*str1 != '\0') {

        str1++; // Move the pointer to the end of str1
    }
    while ((*str1++ = *str2++) != '\0');

    // Copy each character from str2 to the end of str1 until the null terminator is reached
    // Post-increment both pointers to move to the next character
    return original; // Return the pointer to the beginning of str1
}

// Function to search for character s in the string str
// Returns a pointer to the first occurrence of the character in the string, otherwise returns nullptr
const char* myStrchr(const char* str, char s)
{
    while (*str != '\0')    {

        if (*str == s)
            return str; // Return the pointer to the first occurrence of the character
        str++; // Move to the next character in the string
    }

    return nullptr; // Return nullptr if the character is not found
}

// Function to search for the substring str2 in the string str1
// Returns a pointer to the first occurrence of the substring in the string, otherwise returns nullptr
const char* myStrstr(const char* str1, const char* str2)
{
    while (*str1 != '\0') {

        const char* temp1 = str1; // Save the starting address of str1
        const char* temp2 = str2; // Save the starting address of str2
        while (*temp1 != '\0' && *temp2 != '\0' && *temp1 == *temp2) {

            temp1++; // Move to the next character in str1
            temp2++; // Move to the next character in str2
        }
        if (*temp2 == '\0')
            return str1; // Return the pointer to the first occurrence of the substring
        str1++; // Move to the next character in str1 and continue searching
    }
    return nullptr; // Return nullptr if the substring is not found
}
