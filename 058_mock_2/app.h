#ifndef APP_H
#define APP_H

typedef enum
{
    APP_OK = 0,
    APP_RF_ERROR = -1,
    APP_RF_SEND,
    APP_RF_RECV,
    APP_ERR_SYS,
    APP_ERR_INIT,
    APP_HARD_FAULT,
    APP_SYS_OUT,
    APP_ERR_TMSTMP
} app_status_t;

app_status_t app_run(void);

#endif

