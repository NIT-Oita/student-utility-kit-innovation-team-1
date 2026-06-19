#include <stdio.h>
#include <string.h>
#include <time.h>

#include "logic.h"

/* 日付差を計算 */
static int days_between(const char *date1, const char *date2)
{
    struct tm tm1 = {0};
    struct tm tm2 = {0};

    sscanf(date1, "%d-%d-%d",
           &tm1.tm_year,
           &tm1.tm_mon,
           &tm1.tm_mday);

    sscanf(date2, "%d-%d-%d",
           &tm2.tm_year,
           &tm2.tm_mon,
           &tm2.tm_mday);

    tm1.tm_year -= 1900;
    tm1.tm_mon--;

    tm2.tm_year -= 1900;
    tm2.tm_mon--;

    time_t t1 = mktime(&tm1);
    time_t t2 = mktime(&tm2);

    return (int)(difftime(t1, t2) / 86400);
}

/* 緊急度計算
   score = (priority × 10) - 残り日数
*/
int task_urgency(const Task *t, const char *today)
{
    int days_left = days_between(t->deadline, today);

    return (t->priority * 10) - days_left;
}

/* 緊急度順(降順)にソート */
void task_sort(Task *list, int n)
{
    int i, j;

    char today[11] = "2026-05-11";

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {

            if (task_urgency(&list[j], today)
                < task_urgency(&list[j + 1], today)) {

                Task temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

int task_is_done(const Task *t)
{
    return t->done;
}

/* 今日ビュー(3日以内) */
int task_is_today_view(const Task *t, const char *today)
{
    int days_left = days_between(t->deadline, today);

    return (days_left >= 0 && days_left <= 3);
}