#include <sanlang.hpp>
#include <stdarg.h>

namespace SANLANG_NAMESPACE
{

std::unique_ptr< Logger > Logger::sInstance;

void Logger::StaticInit()
{
    Logger::sInstance.reset( new Logger() );
}
void Logger::WhiteLog( const char * inFormat, ...)
{
    char temp_memory[1024];
    va_list ap;
    va_start( ap, inFormat );

    // vsnprintf
    // vsprintf( temp_memory, inFormat, ap );
    vsnprintf( temp_memory, 1024, inFormat, ap ); 
    va_end(ap);

    mLogs.emplace_back( temp_memory );
}
void Logger::WhiteLog(std::string&& inLog)
{
    mLogs.emplace_back( inLog );
}


}

