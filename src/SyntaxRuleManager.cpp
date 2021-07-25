#include <SanLangPCH.h>

namespace SANLANG_NAMESPACE
{
    std::unique_ptr< SyntaxRuleManager > SyntaxRuleManager::sInstance;

    void SyntaxRuleManager::StaticInit()
    {
        sInstance.reset( new SyntaxRuleManager());

        // all syntax_rule
        SyntaxRuleUtils::MakeAllSyntaxRule( sInstance.get() );
    }

    void ClearSyntax( Syntax * inSyntax )
    {
        if ( !inSyntax )
            return;

        for( auto &i : inSyntax->mNextSyntaxList )
        {
            ClearSyntax( i.second );
        }
        delete inSyntax;
    }

    void SyntaxRuleManager::Release()
    {
        // Release Node
        ClearSyntax( mRootSyntax );
        mRootSyntax = nullptr;
        mSize = 0;
    }

    void SyntaxRuleManager::RegisterSyntaxRule(SyntaxRule &inSyntaxRule)
    {
        Syntax * current_syntax = mRootSyntax;

        for( auto& i : inSyntaxRule )
        {
            auto & temp_syntax = current_syntax->mNextSyntaxList[i];
            //  NextSyntax 의 값이 없다면!
            if ( ! temp_syntax )
            {
                temp_syntax = Syntax::CreateSyntax();
                ++mSize;
            }
            current_syntax = temp_syntax;
        }
    }
    void SyntaxRuleManager::RegisterSyntaxRule( __syntax inSyntaxGroupName, SyntaxRule& inSyntaxRule )
    {
        // Grop을 추가합니다.
        SyntaxPtr& group_syntax = mRootSyntax->mNextSyntaxList[ inSyntaxGroupName ];

        if ( group_syntax )
            group_syntax = Syntax::CreateSyntax();

        Syntax * current_syntax = group_syntax;

        for( auto& i : inSyntaxRule )
        {
            auto & temp_syntax = current_syntax->mNextSyntaxList[i];
            //  NextSyntax 의 값이 없다면!
            if ( ! temp_syntax )
            {
                temp_syntax = Syntax::CreateSyntax();
                ++mSize;
            }
            current_syntax = temp_syntax;
        }
    }
}
