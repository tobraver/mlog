#include "mlog.h"

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/daily_file_sink.h"

void mlog_init(void)
{
    // create a console log
    auto console_log = spdlog::stdout_color_mt("console");    
    console_log->set_pattern(LOG_PATTERN_0);

    // create a daily logger - a new file is created every day at 0:0 am
    auto daily_log = spdlog::daily_logger_mt("daily", "log/info.log", 0, 0);
    daily_log->set_pattern(LOG_PATTERN_0);

    // periodically flush all *registered* loggers every 3 seconds:
    spdlog::flush_every(std::chrono::seconds(3));

#if LOG_MUTI_ENABLE
    // TODO: 
#endif
    // replace spdlog default log
    spdlog::set_default_logger(console_log);
}

void mlog_deinit(void)
{

}



