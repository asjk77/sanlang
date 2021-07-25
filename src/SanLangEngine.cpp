#include <SanLangPCH.h>

namespace {
    // 특수문자 <> ; : 등등 일경우 true 반환
    bool IsSep(const char inCode) {
        if (
            inCode >= 33 && inCode <= 47 ||
            inCode >= 58 && inCode <= 64 ||
            inCode >= 91 && inCode <= 96 ||
            inCode >= 123 && inCode <= 126
                )
            return true;

        return false;
    }
    // space, \n \t 일 경우 true 반환
    bool IsIgnoreSep( const char inCode ) {
        if ( inCode == '\n' || inCode == '\t' || inCode == ' ' )
            return true;

        return false;
    }
    // Charector or Number
    bool IsCharacter( const char inCode ) {
        if(
            inCode >= 48 && inCode <= 57 || // number;
            inCode >= 65 && inCode <= 90 || // 대문자
            inCode >= 97 && inCode <= 122  // 소문자
                )
            return true;

        return false;
    }
}

namespace SANLANG_NAMESPACE
{
    std::unique_ptr< SanLangEngine > SanLangEngine::sInstance;

    SanLangEngine::SanLangEngine()
        : mErrorCode( true ), mShouldKeepInterpreting( true ) { }

    SanLangEngine::~SanLangEngine() {}

    // 해당 파일을 인터프린터 합니다.
    bool SanLangEngine::Interpret( const char* inText, int inCharSize )
    {
        Tokenize( inText, inCharSize );
        return mErrorCode;
    }
    
    void SanLangEngine::Tokenize( const char * inText, const int inCharSize )
    {
        int current_index = 0;
        char temp_current_index = 0;

        Token temp_token;
        
        while( mShouldKeepInterpreting &&
                current_index < inCharSize-1)
        {
            temp_current_index = inText[current_index];

            if ( IsSep( inText[current_index] ) ) {
                if ( temp_token.size() != 0 )
                {
                    ProcessToken( temp_token );
                    temp_token.clear();
                }

                temp_token += inText[current_index];
                ProcessToken( temp_token );
                temp_token.clear();

            } else if ( IsIgnoreSep( inText[current_index] ) ) {
                ProcessToken( temp_token );
                temp_token.clear();
            } else if ( IsCharacter( inText[current_index] ) ) {
                temp_token += inText[current_index];
            } else {
                // parse Error 
                mErrorCode = true;
                return;
            }
            ++current_index;
        }
        // last process
        ProcessToken( temp_token );

        // 다시 동작해도 문제 없게..
        if  (! mShouldKeepInterpreting )
            mShouldKeepInterpreting = true;
    }

    void SanLangEngine::ProcessToken( Token & inToken )
    {
        bool result = Processor::sInstance->Process( inToken );

        if ( ! result ) // 만약 값이 거짓이라면
            Stop();

        // 토큰을 캐싱합니다.
        TokenCache::sInstance->Cache( inToken );

    }
}
