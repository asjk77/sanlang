#include <SanLangPCH.h>

namespace SANLANG_NAMESPACE
{
void StaticInit()
{ 
    // init SanLangLibs
    SanLangEngine::StaticInit();
    SyntaxRuleManager::StaticInit();
    Processor::StaticInit();
    TokenCache::StaticInit();
    ProcedureManager::StaticInit();
}
void Release() { return;}
}
