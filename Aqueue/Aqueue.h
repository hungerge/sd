
#ifndef Aqueue_h
#define Aqueue_h

#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 10

/**************************************************************
 *    Struct Define Section
 **************************************************************/
//ѭ�����нṹ
typedef struct Aqueue
{
    void *data[MAXQUEUE];      //������
    int front;
    int rear;
    size_t length;        //���г���
} AQueue;

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

typedef enum
{
    FALSE=0, TRUE=1
} Status;

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/


void InitAQueue(AQueue *Q);


void DestoryAQueue(AQueue *Q);




Status IsFullAQueue(const AQueue *Q);


Status IsEmptyAQueue(const AQueue *Q);




Status GetHeadAQueue(AQueue *Q, void *e);




int LengthAQueue(AQueue *Q);




Status EnAQueue(AQueue *Q, void *data);




Status DeAQueue(AQueue *Q);




void ClearAQueue(AQueue *Q);




Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q));




void APrint(void *q);
void *getType(Type *temp);

#endif /* Aqueue_h */