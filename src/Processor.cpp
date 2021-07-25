#include <SanLangPCH.h>

namespace SANLANG_NAMESPACE
{
    Processor::Processor( SyntaxPtr& inRootSyntax )
    {
        // First Stack Push
        mLocalStack.Push( inRootSyntax, 0 );
    }
    std::unique_ptr< Processor > Processor::sInstance;

    void Processor::StaticInit()
    {
        if ( ! SyntaxRuleManager::sInstance )
            throw Exception("Processor StaticInitError: SyntaxRuleManager 가 필요합니다.");

        auto root_syntax = SyntaxRuleManager::sInstance->GetRootSyntax();

        sInstance.reset( new Processor( root_syntax ) );
    }

    bool Processor::Process( const Token& inToken )
    {
        while ( ProcessSyntaxGroup() ) {}

        return ProcessLiterialSyntax( inToken );
    }
    bool Processor::ProcessSyntaxGroup()
    {
        for( int i = 0;  i < SyntaxRuleGroupConstant::SYNTAX_GROUP_CONST_LIST_SIZE ; i++ )
        {
            auto &temp = mLocalStack.GetTop().
                mCurrentSyntax->mNextSyntaxList[ SyntaxRuleGroupConstant::SYNTAX_GROUP_CONST_LIST[i] ];

            if ( temp )
            {
                mLocalStack.Push( temp, 0);
                return true; // ok 한번 이동했으니 종료해라! 
            }
        }
        // 검색 결과과 없네  다음으로 넘어가!
        return false;
    }

    bool Processor::ProcessIdentfier() {
        // auto& local_stack_top = mLocalStack.GetTop();
        // auto& next_syntax_list = local_stack_top.mCurrentSyntax->mNextSyntaxList; 
        // if( next_syntax_list[IdentifierSyntax::IDENTIFIED] )
        // {
            // //IDENTIFIED`
        // }
        // else if ( next_syntax_list[IdentifierSyntax::UNIDENTIFIED] )
        // {
            // //UNIDENTIFIE
        // }
        return false;
    }
    // LocalStack에서 찾습니다.

    bool Processor::ProcessLiterialSyntax( const Token& inToken )
    {
        auto& local_stack_top = mLocalStack.GetTop();
        auto & next_syntax = local_stack_top.mCurrentSyntax->mNextSyntaxList[inToken]; 

        if ( next_syntax ) {
            local_stack_top.mCurrentSyntax = next_syntax;

            return true;
        }

        return false;
    }
}
