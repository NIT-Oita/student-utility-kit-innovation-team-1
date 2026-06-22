#include <stdio.h>
#include <string.h>
#include "logic.h"

void showMenu(){
    printf("\n===== ToDo =====\n");
    printf("1.新しい項目を追加する\n");
    printf("2.ToDoリストを表示する\n");
    printf("3.この項目を「完了」にする\n");
    printf("4.この項目を削除する\n");
    printf("5.ToDoを検索する\n");
    printf("6.すべての項目を削除する\n");
    printf("7.終了する\n");
    printf("選択してください。\n");
}

void addTask(Task list[],int *count){
    Task*t=&list[*count];

    printf("ID:");
    scanf("%d",&t->id);

    printf("タスク名");
    scanf(" %63[^\n]", t->title);

    printf("締切日");
    scanf("%10s",t->deadline);

    printf("優先度");
    scanf("%d",&t->priority);

    t->done=0;

    (*count)++;
}

void showTask(Task list[],int count){
    printf("\nID\tタスク名\t締切日\t優先度\t状態\n");

    for(int i=0;i<count;i++){
        printf("%d\t%s\t%s\t%d\t%s\n",
        list[i].id,
        list[i].title,
        list[i].deadline,
        list[i].priority,
        list[i].done?"完了":"未完了");
    }
}

void completeTask(Task list[],int count){
    int id;
    printf("完了するIDを入力してください。: ");
    scanf("%d",&id);

    for(int i=0;i<count;i++){
        if(list[i].id==id){
            list[i].done=1;
            printf("完了にしました。\n");
            return;
        }
    }
printf("該当するIDが見つかりません。\n");
}


void deleteTask(Task list[],int *count){
    int id;
    printf("削除するIDを入力してください。: ");
    scanf("%d",&id);

    for(int i=0;i<*count;i++){
        if(list[i].id==id){
            for(int j=i;j<*count-1;j++){
                list[j]=list[j+1];
            }

            (*count)--;
            printf("削除しました。\n");
            return ;
        }
    }
    printf("該当するIDが見つかりません。\n");
    }

void searchTask(Task list[],int count){
    char key[64];
    
    printf("検索語:");
    scanf(" %63[^\n]", key);

    for(int i = 0; i < count; i++){
         if(strstr(list[i].title, key)){
            printf("%d %s %s %d %s\n",
                  list[i].id,
                  list[i].title,
                  list[i].deadline,
                  list[i].priority,
                  list[i].done ? "完了" : "未完了");
         }
    }
}

void clearAll(int *count) {
   *count = 0;
   printf("すべての項目を削除しました。\n");
}