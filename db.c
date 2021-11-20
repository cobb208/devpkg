#include <stdio.h>
#include <stdlib.h>

#include "dbg.h"

int init_db()
{
    FILE *db;

    db = fopen("/tmp/devpkg/db/db", "w");


    fclose(db);


    return 0;
}