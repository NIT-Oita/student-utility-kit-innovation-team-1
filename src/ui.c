#include <stdio.h>
#include <string.h>
#include "ui.h"

void showMenu(){
    printf("\n===== ToDo =====\n");
    printf("1.新しい項目を追加する");
    printf("2.ToDoリストを表示する");
    printf("3.この項目を「完了」にする");
    printf("4.この項目を削除する");
    printf("5.ToDoを検索する");
    printf("6.すべての項目を削除する");
    printf("7.ToDoリストを閉じる");
    printf("選択してください。");
}

void addTask(Todo.todo[],int *count){
    printf("内容を入力してください。\n");
    scanf("%[^\n]",todo[*count].task);
    todo[*count].done=0;
    (*count)++;

void showTask(Todo todo[],int count){
    for(int i=0;i<count;i++){
        printf("%d,[%s] %s\n",
        i+1,todo[i].done ? "✓" : " ",todo[i].task);
    }
}

void completeTask(Todo todo[],int count){
    int n;
    printf("完了する番号を入力してください。: ");
    scanf("%d",&n);

    if(n>=1 && n<=count)
        todo[n-1].done=1;
}

void deleteTask(Todo todo[],int *count){
    int n;
    printf("削除する番号を入力してください。: ");
    scanf("%d",&n);

    if(n>=1 && n<=*count){
        for(int i=n-1;i<*count;i++){
                todo[i]=todo[i+1];
        }
        (*count)--;
    }
}

void searchTask(Todo todo[],int count){
    char key[100];
    printf("検索: ");
    scanf("%[^\n]",key);

    for(inti=0;i<count;i++){
        if(strstr(todo[i].task,key))
        printf("%d.%s\n",i+1,todo[i].task);
    }
}

void clearAll(int *count){
    *count=0;
    printf("すべての項目を削除しました。\n");
}