#ifndef INC_LOGGER_HPP
#define INC_LOGGER_HPP

class Logger
{
public:
    Logger() {}
    ~Logger() {}

    static std::unique_ptr< Logger > sInstance;
    static void StaticInit();

    void WhiteLog( const char * inFormat, ...);
    void WhiteLog(std::string&& inLog);
private:
    std::vector<std::string> mLogs;
};

#define LOG(...) if ( Logger::sInstance ) Logger::sInstance->WhiteLog(__VA_ARGS__)

#endif /* INC_LOGGER_HPP */
