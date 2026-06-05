#ifndef UI_H
#define UI_H

typedef strcut{
    char task[100];
    int done;
}Todo;

void showMenu();
void addTask(Todo todo[],int *count);
void showTask(Todo todo[],int count);
void completeTask(Todo todo[],int count);
void deleteTask(Todo todo[],int *count);
void searchTask(Todo todo[],int count);
void clearAll(int *count);

#endif