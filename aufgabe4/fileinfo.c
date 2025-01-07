#define _POSIX_C_SOURCE 200112L

#include "fileinfo.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

typedef enum filetype {
    filetype_regular,
    filetype_directory,
    filetype_other
} filetype;

typedef struct fileinfo {
    char name[NAME_MAX + 1];
    filetype type;
    struct fileinfo *next;
    union {
        off_t size;
        struct fileinfo *entries;
    } info;
} fileinfo;

fileinfo *fileinfo_create(const char *name) {
    if (strlen(name) > NAME_MAX) {
        errno = ENAMETOOLONG;
        return NULL;
    }

    if (lstat(name) == -1) {
        return NULL;
    }
}
