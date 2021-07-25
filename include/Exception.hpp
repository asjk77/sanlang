#ifndef SANLANG_EXCEPTION_HPP
#define SANLANG_EXCEPTION_HPP

class Exception
{
public:
    Exception( const char * inDescription )
        : mDescription( inDescription ) {}
    ~Exception() {}

    const char * WhatIs() { return mDescription; }
private:
    const char * mDescription;
};

#endif /* SANLANG_EXCEPTION_HPP */
