#include <SanLangPCH.h>

namespace SANLANG_NAMESPACE
{
    std::unique_ptr<TokenCache> TokenCache::sInstance;

    void TokenCache::Cache( const Token & inToken )
    {
        mTokens.push_back( inToken );
    }
}

