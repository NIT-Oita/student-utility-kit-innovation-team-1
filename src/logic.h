#ifndef LOGIC_H
#define LOGIC_H

#define MAX_TASKS 100

typedef struct {
    int id;
    char title[64];
    char deadline[11];   // YYYY-MM-DD
    int priority;        // 1～5
    int done;            // 0:未完了 1:完了
} Task;

/* 緊急度を計算 */
int task_urgency(const Task *t, const char *today);

/* 緊急度順に並び替え */
void task_sort(Task *list, int n);

/* 完了済みか判定 */
int task_is_done(const Task *t);

/* 3日以内の課題か判定 */
int task_is_today_view(const Task *t, const char *today);

#endif