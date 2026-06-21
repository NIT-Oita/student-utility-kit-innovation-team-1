#ifndef UI_H
#define UI_H

#include "logic.h"

/*メニュー表示*/
void showMenu(void);

/*UI操作 (実際の処理はlogic側でもOK)*/
void addTask(Task list[],int *count);
void showTask(Task list[],int count);
void completeTask(Task list[],int count);
void deleteTask(Task list[],int *count);
void searchTask(Task list[],int count);
void clearAll(int *count);

#endif