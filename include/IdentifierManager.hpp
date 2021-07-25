#ifndef SANLANG_IDENTIFIERMANAGER_HPP
#define SANLANG_IDENTIFIERMANAGER_HPP

struct Address 
{
public:
    void * mRealAddress;
    unsigned int mRealAddressPtr;
};

typedef std::string Identifier;


class IdentifierManager
{
public:
    IdentifierManager() {}
    ~IdentifierManager() {}
private:
};

typedef IdentifierManager* IdentifierManagerPtr;

#endif /* SANLANG_IDENTIFIERMANAGER_HPP */
