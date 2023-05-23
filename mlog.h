#ifndef __MLOG_H__
#define __MLOG_H__

#include "spdlog/spdlog.h"

// format 
#define LOG_FMT_DEFT    "{}"
#define LOG_FMT_UINT    FMT_DEFT
#define LOG_FMT_FLOAT   "{:.2f}"
#define LOG_FMT_STR     FMT_DEFT
#define LOG_FMT_HEX     "{0:x}"
#define LOG_FMT_OCT     "{0:o}"
#define LOG_FMT_BIN     "{0:b}"

// pattern
#define LOG_PATTERN_0   "[%Y-%m-%d %H:%M:%S.%e] %^[%L]%$: %v"
#define LOG_PATTERN_1   "[%Y-%m-%d %H:%M:%S.%e] [%n] %^[%l]%$: %v"

// TODO: multi log
#define LOG_MULTI_ENABLE 0
#if LOG_MULTI_ENABLE
#define MLOGI       spdlog::get("multi")->info
#define MLOGW       spdlog::get("multi")->warn
#define MLOGE       spdlog::get("multi")->error
#endif

// console log
#define CLOGI       spdlog::get("console")->info
#define CLOGW       spdlog::get("console")->warn
#define CLOGE       spdlog::get("console")->error

// daily log
#define DLOGI       spdlog::get("daily")->info
#define DLOGW       spdlog::get("daily")->warn
#define DLOGE       spdlog::get("daily")->error

// log
#define LOGI        CLOGI
#define LOGW        CLOGW
#define LOGE        CLOGE

void mlog_init(void);
void mlog_deinit(void);


#endif
