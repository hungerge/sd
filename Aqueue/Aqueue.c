#include "Aqueue.h"

void InitAQueue(AQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    Q->length = 0;
    return;
}
Status IsFullAQueue(const AQueue *Q)
{
    if((Q->rear+1)%MAXQUEUE == Q->front) return TRUE;
    return FALSE;
}

Status IsEmptyAQueue(const AQueue *Q)
{
    if(Q->front == Q->rear) return TRUE;
    return FALSE;
}

Status GetHeadAQueue(AQueue *Q, void *e)
{
    if(Q->length == 0) return FALSE;
    *(Type*)e = *(Type*)(Q->data[Q->front]);
    return TRUE;
}

void ClearAQueue(AQueue *Q)
{
    if(Q->length == 0) return;
    while(Q->front != Q->rear)
    {
        Q->data[Q->front] = NULL;
        Q->front = (Q->front+1)%MAXQUEUE;
    }
    Q->length = 0;
    return;
}

void DestoryAQueue(AQueue *Q)
{
    if(Q->length == 0) return;
    if(Q->front == Q->rear)
    {
        Type *temp = (Type*)(Q->data[Q->front]);
        free(temp);
        Q->length--;
        return;
    }
    while(Q->front != Q->rear)
    {
        Type *temp = (Type*)(Q->data[Q->front]);
        free(temp);
        Q->front = (Q->front+1)%MAXQUEUE;
    }
    Q->length = 0;
    return;
}

int LengthAQueue(AQueue *Q)
{
    return Q->length;
}


void *getType(Type *temp)
{
    temp = (Type*)malloc(sizeof(Type));
    char a[100] = {'0'};
    printf("\t\t\t输入一个数 字符\'\',字符串\"\"");
    scanf("%s",a);
    int i = 0;
    int k = 0;
    while(a[i] != '\0')
    {
        if(a[i] == ' ') continue;
        if(a[i] == '\'')
        {
            i++;
            temp->character = a[i];
            temp->type = CHARACTER;
            return temp;
        }
        if(a[i] == '\"')
        {
            i++;
            temp->type = STRING;
            while(a[i] != '\"' && a[i] != '\0')
            {
                temp->string[k] = a[i];
                i++;
                k++;
            }
            return temp;
        }
        if(a[i] <= '9' && a[i] >= '0')
        {
            int ans = 0;
            while(a[i] <= '9'&&a[i] >= '0')
            {
                ans = ans*10 + (a[i] - '0');
                i++;
            }
            if(a[i] == '.')//小数
            {
                i++;
                float anss = 0;//计算小数
                k = i;
                while(a[k+1] <= '9'&&a[k+1] >= '0') k++;
                while(a[k] <= '9'&&a[k] >= '0')
                {
                    anss = anss/10 + (a[k] - '0');
                    k--;
                }
                anss = ans + anss/10;
                temp->type = POINT;
                temp->point = anss;
                return temp;
            }
            temp->type = INTEGER;
            temp->integer = ans;
            return temp;
        }
        printf("输入有误\n");
        return getType(temp);
    }
    return NULL;
}

Status EnAQueue(AQueue *Q, void *data)
{
    if(Q->front == Q->rear)
    {
        Q->data[Q->front] = data;
        Q->rear = (Q->rear+1)%MAXQUEUE;
        Q->length++;
        return TRUE;
    }
    if((Q->rear+1)%MAXQUEUE == Q->front) return FALSE;
    Q->data[Q->rear] = data;
    Q->rear = (Q->rear+1)%MAXQUEUE;
    Q->length ++;
    return TRUE;
}

Status DeAQueue(AQueue *Q)
{
    if(Q->length == 0) return FALSE;
    Type *temp = (Type*)(Q->data[Q->front]);
    free(temp);
    Q->front = (Q->front+1)%MAXQUEUE;
    Q->length--;
    return TRUE;
}

void APrint(void *q)
{
    Type *c = (Type*)q;
    int a = c->type;
    switch(a)
    {
        case 1:
        {
            printf("%c\n",c->character);
            break;
        }
        case 2:
        {
            printf("%s\n",c->string);
            break;
        }
        case 3:
        {
            printf("%d\n",c->integer);
            break;
        }
        case 4:
        {
            printf("%lf\n",c->point);
            break;
        }
    }
}
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
    if(Q->length == 0) return FALSE;
    int temp = Q->front;
    while(temp != Q->rear)
    {
        foo(Q->data[temp]);
        temp ++;
    }
    return TRUE;
}

