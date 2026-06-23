#include <stdio.h>
#include "logic.h"
#include "storage.h"
#include "ui.h"
#define MAX 100

int main(void)
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    Task list[MAX];
    int count = 0;
    int choice;
    load_tasks("todo.csv", list, MAX);
    while(1)
    {
        showMenu();
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addTask(list, &count);
                break;
 
            case 2:
                showTask(list, count);
                break;
 
            case 3:
                completeTask(list, count);
                break;
 
            case 4:
                deleteTask(list, &count);
                break;
 
            case 5:
                searchTask(list, count);
                break;
 
            case 6:
                clearAll(&count);
                break;
 
            case 7:
                save_tasks("todo.csv", list, count);
                return 0;

            default:
                printf("もう一度選択してください\n");
        }
    }
}
 