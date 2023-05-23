#include "mlog.h"

int main(int argc, const char** argv) 
{
    mlog_init();

#if LOG_MULTI_ENABLE

    LOGI("hello world");
    LOGW("hello world");
    LOGE("hello world");

#else

    CLOGI("hello world " LOG_FMT_FLOAT ", ok", 3.2);
    CLOGW("hello world");
    CLOGE("hello world");

    DLOGI("hello world");
    DLOGW("hello world");
    DLOGE("hello world");

#endif

    return 0;
}

