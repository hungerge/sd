
#ifndef Untitled1_h
#define Untitled1_h

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    void *data;                   //数据域指针
    struct node *next;            //指向当前结点的下一结点
} Node;

typedef struct
{
    int type;
    int integer;
    double point;
    char character;
    char string[100];
}Type;

typedef enum
{
    CHARACTER = 1,
    STRING = 2,
    INTEGER = 3,
    POINT = 4
}D_Type;

typedef struct Lqueue
{
    Node *front;                   //队头
    Node *rear;                    //队尾
    size_t length;            //队列长度
} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;
/**************************************************************
 *    Prototype Declare Section
 **************************************************************/



void InitLQueue(LQueue *Q);


void DestoryLQueue(LQueue *Q);


Status IsEmptyLQueue(const LQueue *Q);


Status GetHeadLQueue(LQueue *Q, void *e);


int LengthLQueue(LQueue *Q);


Status EnLQueue(LQueue *Q, void *data);


Status DeLQueue(LQueue *Q);


void ClearLQueue(LQueue *Q);


Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q));


void LPrint(void *q);

void *getType(Type *temp);


/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/

#endif /* Lqueue_h */
