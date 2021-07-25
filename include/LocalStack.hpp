#ifndef SANLANG_LOCALSTACK_HPP
#define SANLANG_LOCALSTACK_HPP

class Local
{
public:
    Local( SyntaxPtr& inCurrentSyntax, uint32_t inReturnAddress )
        : mCurrentSyntax( inCurrentSyntax ), mReturnAddress( inReturnAddress ) {}
    ~Local() {}

    SyntaxPtr mCurrentSyntax;
    uint32_t mReturnAddress;
    IdentifierManagerPtr mIdentifierManager;
};

// Wrapping Stack

class LocalStack
{
public:
    LocalStack() {}
    ~LocalStack() {}

    // emplace_back
    void Push( SyntaxPtr& inCurrentSyntax, uint32_t inReturnAddress ) 
    { mLocals.emplace_back( inCurrentSyntax, inReturnAddress ); }

    Local& GetTop() { return mLocals.back(); }

    inline Local& GetPrevTop();

    // iterators
    typedef std::list<Local> LocalList;
    typedef typename LocalList::iterator iterator;

    iterator begin() { return mLocals.begin(); }
    iterator end() { return mLocals.end(); }

private:
    LocalList mLocals;
};

inline Local& LocalStack::GetPrevTop()
{
    return *(--mLocals.end());
}

#endif /* SANLANG_LOCALSTACK_HPP */
