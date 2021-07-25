#ifndef SANLANG_HPP
#define SANLANG_HPP

#ifndef SANLANG_NAMESPACE
    #define SANLANG_NAMESPACE sanlang
#endif /* S*/

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <unordered_map>
#include <list>
#include <stack>
#include <functional>

namespace SANLANG_NAMESPACE
{

#include "Logger.hpp"
#include "Exception.hpp"

typedef std::string Token;

#include "IdentifierManager.hpp"
#include "Syntax.hpp"
#include "LocalStack.hpp"

#include "SyntaxRuleUtils.hpp"

// singletons
#include "SyntaxRuleManager.hpp"
#include "SanLangEngine.hpp"
#include "Processor.hpp"
#include "TokenCache.hpp"
#include "ProcedureManager.hpp"
    
void StaticInit();
void Release();

}

#endif /* SANLANG_HPP */
