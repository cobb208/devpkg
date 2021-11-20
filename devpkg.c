#if 0
#include <apr-1/apr.h>
#include <apr-1/apr_allocator.h>
#include <apr-1/apr_file_io.h>
#endif

// Standard Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "shell.h"
#include "db.h"
#include "dbg.h"





int main(int argc, char *argv[]) {

    init_db();

    char *condition = argv[1]; // temp setting will need proper way to sort flags
    check(condition != NULL, "No flags were set!");

    if(strcmp(condition, "-s") == 0)
    {
        init_dir();

        return 0;
    }


    printf("No option chosen");



    return 0;

error:
    return -1;
}