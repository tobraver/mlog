#include "mlog.h"

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/daily_file_sink.h"

void mlog_init(void)
{
    try
    {
    #if LOG_MULTI_ENABLE

        std::vector<spdlog::sink_ptr> sinks;
        sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        sinks.push_back(std::make_shared<spdlog::sinks::daily_file_sink_mt>("log/info.log", 23, 59));
        auto multi_logger = std::make_shared<spdlog::logger>("multi", begin(sinks), end(sinks));

        multi_logger->set_pattern(LOG_PATTERN_0);

        //register it if you need to access it globally
        spdlog::register_logger(multi_logger);

        // replace spdlog default log
        spdlog::set_default_logger(multi_logger);
    #else
        // create a console log
        auto console_log = spdlog::stdout_color_mt("console");    
        console_log->set_pattern(LOG_PATTERN_0);

        // create a daily logger - a new file is created every day at 23:59 am
        auto daily_log = spdlog::daily_logger_mt("daily", "log/info.log", 23, 59);
        daily_log->set_pattern(LOG_PATTERN_0);

        // periodically flush all *registered* loggers every 3 seconds:
        spdlog::flush_every(std::chrono::seconds(3));

        // replace spdlog default log
        spdlog::set_default_logger(console_log);
    #endif
    }
    catch (const spdlog::spdlog_ex& ex)
    {
        std::cout << "Log initialization failed: " << ex.what() << std::endl;
    }
}

void mlog_deinit(void)
{
    spdlog::drop_all();
}



