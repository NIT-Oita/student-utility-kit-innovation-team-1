#ifndef STORAGE_H
#define STORAGE_H

#include "logic.h"


int load_tasks(const char *path, Task *list, int max);

int save_tasks(const char *path, Task *list, int count);

#endif