#ifndef SANLANG_SYNTAX_HPP
#define SANLANG_SYNTAX_HPP

class Syntax
{
public:
    Syntax() {} //nothing
    ~Syntax() {}

    static Syntax* CreateSyntax() { return new Syntax(); }

    std::unordered_map< std::string, Syntax * > mNextSyntaxList;
};

typedef Syntax* SyntaxPtr;

#endif /* SANLANG_SYNTAX_HPP */
