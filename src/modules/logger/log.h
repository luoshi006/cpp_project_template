#pragma once
#include "quill/Quill.h"

#include <string_view>

// Logger
// https://github.com/Tearnote/Minote/blob/master/src/base/log.hpp

namespace cpt::base
{
class Log {
public:
    typedef quill::Logger Logger;

    // get instance
    static Logger* get_logger() {
        if (nullptr == m_logger) {
            init(log_name, log_level);
        }
        return m_logger;
    }

private:
	static Logger* m_logger;
    static constexpr std::string_view log_name = "log_cpt.txt";
    //TODO: change log level for debug
    static constexpr quill::LogLevel log_level = quill::LogLevel::TraceL3;

	// Start logging to console and specified logfile. All messages below
	// the provided log level will be dropped.
	static void init(std::string_view filename, quill::LogLevel level);
};

// Logging functions, fmtlib formatting is supported.
#define log_trc(fmt, ...) LOG_TRACE_L1(Log::get_logger(), fmt, ##__VA_ARGS__)
#define log_dbg(fmt, ...) LOG_DEBUG(Log::get_logger()   , fmt, ##__VA_ARGS__)
#define log_inf(fmt, ...) LOG_INFO(Log::get_logger()    , fmt, ##__VA_ARGS__)
#define log_war(fmt, ...) LOG_WARNING(Log::get_logger() , fmt, ##__VA_ARGS__)
#define log_err(fmt, ...) LOG_ERROR(Log::get_logger()   , fmt, ##__VA_ARGS__)
#define log_crt(fmt, ...) LOG_CRITICAL(Log::get_logger(), fmt, ##__VA_ARGS__)

} // namespace