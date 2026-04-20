#include "ExceptionsClassHeader.h"

GeneralException::GeneralException(const string& errorMsg)
{
    error = errorMsg;
}

const char* GeneralException::what() const noexcept
{
    return error.c_str();
}

BorrowedException::BorrowedException(const string& media)
                  : GeneralException(media + " has been checked out."){}

FileOpenException::FileOpenException(const string& filename)
                  : GeneralException(filename + " failed to open."){}

MediaTypeException::MediaTypeException(const string& type)
                   :GeneralException("Unknown media type: " + type + ". "){}
