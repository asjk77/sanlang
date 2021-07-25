#ifndef INC_SANLANGENGINE_HPP
#define INC_SANLANGENGINE_HPP

#include <IdentifierManager.hpp>


class SanLangEngine
{
public:
    SanLangEngine();
    ~SanLangEngine();

    static std::unique_ptr< SanLangEngine > sInstance;
    static void StaticInit() { sInstance.reset( new SanLangEngine() ); }

    /* 문자를 해석합니다. */
    bool Interpret( const char* inText, int inCharSize );
private:
    /* 해당 문자를 토큰 화 합니다. */
    void Tokenize( const char * inText, const int inCharSize );
    /* 토큰을 처리합니다. */
    void ProcessToken( Token & inToken );

    /* 인터프린트를 중지합니다.*/
    void Stop() { mShouldKeepInterpreting = false; }
private:
    bool mErrorCode; 
    bool mShouldKeepInterpreting;
    
};

#endif /* INC_SANLANGENGINE_HPP */
