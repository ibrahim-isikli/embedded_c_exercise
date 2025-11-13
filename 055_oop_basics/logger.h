#ifndef LOGGER_H
#define LOGGER_H

#include <stdint.h>

typedef enum
{   
    LOGGER_OK = 0,
    LOGGER_ERR_NULL,
    LOGGER_ERR_IO
}logger_status_t;

typedef struct logger logger_t;

// public API
logger_status_t logger_init_console(logger_t **out);
logger_status_t logger_init_file(logger_t **out, const char *filename);
logger_status_t logger_write(logger_t *lg, const char *msg);
logger_status_t logger_destroy(logger_t *lg);


#endif