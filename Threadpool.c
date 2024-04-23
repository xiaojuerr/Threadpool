//
// Created by 肖珏 on 2024/4/23.
//
#include <pthread.h>
#define LL_INSERT(item, list) do{   \
    item->prev = NULL;              \
    item->next = list;              \
    if(list != NULL) list->prev = item;     \
    list = item;                    \
}while(0)

#define LL_REMOVE(item, list) do{                       \
    if(item->prev != NULL) it->prev->next = item->next;  \
    if(item->next != NULL) it->next->prev = item->prev;   \
    if(list == item) list = item->next;                    \
    item->prev = item->next = NULL;                         \
}while(0)

struct NWORKER{

    pthread_t id;
    struct NWORKER *prev;
    struct NWORKER *next;
};


struct NTASK{
    void (*task_func)(void *arg);
    void *user_data;
    struct NTASK *prev;
    struct NTASK *next;


};


struct NTHREADPOOL { //管理组件
    struct NWORKER *workers;
    struct NTASK *tasks;

    pthread_mutex_t  mtx; //避免两个同时操作
    pthread_cond_t cond; //条件变量
};


