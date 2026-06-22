#include <stdio.h>
#include "logic.h"

int load_tasks(const char *path,Task *list,int max){
    FILE *fp=fopen(path,"r");
    if (!fp) return 0;

    char line[256];
    fgets(line, sizeof line, fp); //ヘッダ読み飛ばし

    int n=0;

    while (n<max &&
            fscanf(fp,"%d,%63[^,],%10[^,],%d,%d",
                    &list[n].id,
                    list[n].title,
                    list[n].deadline,
                    &list[n].priority,
                    &list[n].done)==5){

                    n++;
                }

                fclose(fp);
                return n;
}
/* 保存 */
int save_tasks(const char *path, Task *list, int count) {
    FILE *fp = fopen(path, "w");
    if (!fp) return 0;

    fprintf(fp, "id,title,deadline,priority,done\n");

    for (int i = 0; i < count; i++) {
        fprintf(fp,
                "%d,%s,%s,%d,%d\n",
                list[i].id,
                list[i].title,
                list[i].deadline,
                list[i].priority,
                list[i].done);
    }

    fclose(fp);
    return 1;
}
