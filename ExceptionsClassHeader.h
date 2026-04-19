#ifndef EXCEPTIONS_CLASS_HEADER_H
#define EXCEPTIONS_CLASS_HEADER_H

#include <iostream>
#include <string>
#include <exception>
using namespace std;

// --- general exception ---
class GeneralException : public exception 
{
public:
    GeneralException(const string& errorMsg);
    const char* what() const noexcept override; // overrides what() with custom cstring

protected:
    string error;
};

// --- exception thrown when media has been borrowed ---
class BorrowedException : public GeneralException 
{
public:
    BorrowedException(const string& media);
};

// --- exception thrown when input file can't be opened ---
class FileOpenException : public GeneralException
{
public: 
    FileOpenException(const string& filename);
};

// --- exception thrown when the media type listed is invalid ---
class MediaTypeException : public GeneralException
{
public:
    MediaTypeException(const string& type);
};

#endif