#include "log.h"
#include <string> // std::string needed by quill API

namespace cpt::base
{
using std::string_view;

Log::Logger* Log::m_logger = nullptr;

void Log::init(string_view _filename, quill::LogLevel _level)
{
	quill::start(true);

    const size_t max_log_bytes = 1024*1024*50;      // 50 Mb
    const size_t max_log_sizes = 5;                 // 5 log file
    auto file = quill::rotating_file_handler(std::string(_filename), "w", max_log_bytes, max_log_sizes);

	auto console = quill::stdout_handler();
    static_cast<quill::ConsoleHandler*>(console)->enable_console_colours();

	file->set_pattern(
        // %(filename):%(function_name):%(lineno)
		"%(ascii_time) [%(level_id)]:%(lineno) %(message)",
		"%Y-%m-%d_%H:%M:%S.%Qms",
		quill::Timezone::LocalTime);
	console->set_pattern(
		"%(ascii_time) [%(level_id)]:%(lineno) %(message)",
		"%H:%M:%S.%Qms",
		quill::Timezone::LocalTime);

	m_logger = quill::create_logger("main", {file, console});
	m_logger->set_log_level(_level);
}

} // namespace