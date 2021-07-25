#include <gtest/gtest.h>
#include <sanlang.hpp>

using namespace SANLANG_NAMESPACE;

TEST( SyntaxRuleManagerTest , RegisterTest1 )
{
    SyntaxRuleManager syntax_rule_manager;
    SyntaxRule syntax_rule;
    syntax_rule.emplace_back("Sanho");
    syntax_rule.emplace_back("LocalValue");
    syntax_rule.emplace_back("Test");
    syntax_rule.emplace_back("IsFa");
    syntax_rule.emplace_back("IsTest");
    syntax_rule_manager.RegisterSyntaxRule( syntax_rule );

    const Syntax * root_syntax = syntax_rule_manager.GetRootSyntax();

    EXPECT_TRUE( root_syntax );

    Syntax * current_syntax = const_cast< Syntax* > ( root_syntax );

    for ( auto& i: syntax_rule )
    {
        EXPECT_TRUE( current_syntax->mNextSyntaxList[i] );
        current_syntax = current_syntax->mNextSyntaxList[i];
    }

    EXPECT_EQ(5, syntax_rule_manager.GetSize());

    syntax_rule_manager.Release();
    EXPECT_EQ(0, syntax_rule_manager.GetSize());
    root_syntax = syntax_rule_manager.GetRootSyntax();
    EXPECT_FALSE( root_syntax );
}

TEST( SyntaxRuleManagerTest , RegisterTest2 )
{
    SyntaxRuleManager syntax_rule_manager;
    SyntaxRule syntax_rule;
    syntax_rule.emplace_back("Sanho");
    syntax_rule.emplace_back("LocalValue");
    syntax_rule.emplace_back("Test");
    syntax_rule.emplace_back("IsFa");
    syntax_rule.emplace_back("IsTest");
    syntax_rule_manager.RegisterSyntaxRule( syntax_rule );

    syntax_rule.emplace_back("BackToTheHelloworld");
    syntax_rule_manager.RegisterSyntaxRule( syntax_rule );

    // double Register
    EXPECT_EQ(6, syntax_rule_manager.GetSize());


}

int main( int argc, char * argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
