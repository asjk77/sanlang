#include <SanLangPCH.h>

namespace SANLANG_NAMESPACE
{
namespace SyntaxRuleUtils
{
    void MakeAllSyntaxRule( SyntaxRuleManager * ioSyntaxRuleManager )
    {
        SyntaxRule syntax_rule;
        syntax_rule.push_back("Func");
        syntax_rule.push_back(IdentifierSyntax::UNIDENTIFIED);
        syntax_rule.push_back("{");
        syntax_rule.push_back(SyntaxRuleGroupConstant::FUNCTION_INNER_RULE );
        syntax_rule.push_back("}");
        ioSyntaxRuleManager->RegisterSyntaxRule(SyntaxRuleGroupConstant::GLOBAL_RULE, syntax_rule );
    }
}
}
