#ifndef UI_H
#define UI_H

#include "logic.h"

<<<<<<< HEAD
void showMenu();
void addTask(Todo todo[],int *count);
void showTask(Todo todo[],int count);
void completeTask(Todo todo[],int count);
void deleteTask(Todo todo[],int *count);
=======
/*メニュー表示*/
void showMenu(void);

/*UI操作 (実際の処理はlogic側でもOK)*/
void addTask(Task list[],int *count);
void showTask(Task list[],int count);
void completeTask(Task list[],int count);
void deleteTask(Task list[],int *count);
void searchTask(Task list[],int count);
void clearAll(int *count);
>>>>>>> b381b5f4f1065aed8ef53407cd13860f334b66b1

#endif