#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "dbg.h"
#include "bstrlib.h"
#include "stringhelp.h"
#include <unistd.h>





int init_dir()
{
    DIR *main_dir;
    struct dirent *dir;

    char *default_install_dir = "/tmp/devpkg";
    char *db_dir = "/db";
    char *pkg_dir = "/pkg";

    


    char *db_install_dir = concat(default_install_dir, db_dir);
    char *pkg_install_dir = concat(default_install_dir, pkg_dir);

    

    int rc;

    printf("Initialzing install at: %s", default_install_dir);

    rc = mkdir(default_install_dir, 0777);
    check(rc == 0, "Main folder not created!");
    printf("Created main folder at /tmp/devpkg\n");
    printf("db_install is: %s\n", db_install_dir);

    rc = mkdir(db_install_dir, 0777);
    check(rc == 0, "DB Folder not created!\n");
    printf("Created Database Folder\n");

    rc = mkdir(pkg_install_dir, 0777);
    check(rc == 0, "Package folder not created!\n");
    printf("Created Package Folder\n");


    main_dir = opendir(default_install_dir);
    check(main_dir != NULL, "Failed to open main directory\n");

    if(main_dir == NULL)
    {
        printf("Directory Error");
        return 1;
    }


    if(main_dir)
    {
        while((dir = readdir(main_dir)))
        {
            printf("%s\n", dir->d_name);
        }

        closedir(main_dir);
    }

    free(db_install_dir);
    free(pkg_install_dir);

    return 0;

error:
    if(errno == EEXIST)
        printf("FILE EXISTS!");
    if(db_install_dir)
        free(db_install_dir);
    if(pkg_install_dir)
        free(pkg_install_dir);
    return -1;
}