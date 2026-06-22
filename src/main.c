#include <stdio.h>
#include "todo.h"
#include "logic.h"
#include "storage.h"
#include "ui.h"

#define MAX 100

int main(){
    Todo todo[MAX];
    int count=0;
    int choice;

    loadData((todo,&choice)!=1){
        printf("数字を入力してください\n");

        while(getchar()!='\n');
        continue;
    }
    switch(choice){
        case 1:
        addTask(todo,&count);
        break;

        case 2:
        showTask(todo,count);

        case 3:
        delateTask(todo,&count);
        
        case 4:
        completeTask(todo,count);
        break;

        case 5:
        searchTask(list,count);
        break;

        case 6:
        clearAll(&count);
        break;

        case 7:
        return 0;

        default:
        printf("もう一度選択してください\n");
        }
    }