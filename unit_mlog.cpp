#include "mlog.h"

int main(int argc, const char** argv) 
{
    mlog_init();

    CLOGI("hello world " LOG_FMT_FLOAT ", ok", 3.2);
    CLOGW("hello world");
    CLOGE("hello world");

    DLOGI("hello world");
    DLOGW("hello world");
    DLOGE("hello world");

    return 0;
}

