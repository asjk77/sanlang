#ifndef SANLANG_TOKENCACHE_HPP
#define SANLANG_TOKENCACHE_HPP

typedef std::vector< Token > TokenList;

//토큰을 캐싱합니다.
class TokenCache
{
public:
    TokenCache() {}
    ~TokenCache() {}

    static std::unique_ptr< TokenCache > sInstance;
    static void StaticInit() { sInstance.reset( new TokenCache ); }

    void Cache( const Token & inToken );

    const Token& GetToken( uint32_t inAddress ) const { return mTokens[inAddress]; }
    const size_t GetSize() const { return mTokens.size(); }
private:
    TokenList mTokens;
};

#endif /* SANLANG_TOKENCACHE_HPP */
