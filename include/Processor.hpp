#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

class Processor
{
public:
    Processor( SyntaxPtr& inRootSyntax );
    ~Processor() {}

    static std::unique_ptr< Processor > sInstance;
    static void StaticInit();

    bool Process( const Token& inToken );

    bool MoveNextGroupStack(const char * inGroupName);
    bool FindLiteralSyntaxAndMoveStack( const Token& inToken );

    // 처리될시 false  아닐경우 true
    bool ProcessSyntaxGroup();

    bool ProcessIdentfier();
    bool ProcessLiterialSyntax( const Token& inToken );
private:
    LocalStack mLocalStack;
};

#endif /* PROCESSOR_HPP */
