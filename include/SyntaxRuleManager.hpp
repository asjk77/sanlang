#ifndef SYNTAXRULEMANAGER_HPP
#define SYNTAXRULEMANAGER_HPP

typedef std::string __syntax;
typedef std::vector< __syntax > SyntaxRule;

class SyntaxRuleManager
{
public:
    SyntaxRuleManager()
        : mRootSyntax( Syntax::CreateSyntax() ), mSize(0) {}
    ~SyntaxRuleManager() { Release(); }

    static std::unique_ptr< SyntaxRuleManager > sInstance;
    static void StaticInit();

    void RegisterSyntaxRule( SyntaxRule& inSyntaxRule );
    // 임시로 이렇게 합니다.
    void RegisterSyntaxRule( __syntax inSyntaxGroupName, SyntaxRule& inSyntaxRule );

    const SyntaxPtr GetRootSyntax() const { return mRootSyntax; }
    const size_t GetSize() const { return mSize; }

    void Release();
private:
    SyntaxPtr mRootSyntax;
    size_t mSize; // 모든 총량
};

namespace SyntaxRuleGroupConstant {
    inline const char * GLOBAL_RULE = "<GJ";
    inline const char * FUNCTION_INNER_RULE = "<FI";
    inline const char * FUNCTION_ARGS_RULE= "<FR";
    inline const char * CLASS_INNER_RULE= "<CI";
    inline const char * CALL_FUNCTION_ARGS = "<CFA";

    inline const char * SYNTAX_GROUP_CONST_LIST[] = {
        GLOBAL_RULE,
        FUNCTION_INNER_RULE,
        FUNCTION_ARGS_RULE,
        CLASS_INNER_RULE,
        CALL_FUNCTION_ARGS
    };
    inline const size_t SYNTAX_GROUP_CONST_LIST_SIZE = 5;
}

namespace IdentifierSyntax {
    inline const char * IDENTIFIED = "<ID";
    inline const char * UNIDENTIFIED = "<UI";
}

#endif /* SYNTAXRULEMANAGER_HPP */
