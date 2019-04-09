#include "Untitled1.h"

void InitLQueue(LQueue *Q)
{
    Q->front = NULL;
    Q->rear = Q->front;
    Q->length = 0;
    return;
}

Status IsEmptyLQueue(const LQueue *Q)
{
    if(Q->front == NULL) return TRUE;
    return FALSE;
}



Status GetHeadLQueue(LQueue *Q, void *e)
{
    if(Q->length == 0) return FALSE;
    *(Type*)e = *(Type*)(Q->front->data);
    return TRUE;
}

void ClearLQueue(LQueue *Q)
{
   while(Q->front != NULL)
   {
       Q->front->data = NULL;
       Q->front = Q->front->next;
   }
    Q->rear = Q->front;
    Q->length = 0;
    return;
}

void DestoryLQueue(LQueue *Q)
{
    Node *temp = Q->front;
    while(Q->front != NULL)
    {
        Q->front = Q->front->next;
        free(temp);
        temp = Q->front;
    }
    Q->rear = Q->front;
    Q->length = 0;
}

int LengthLQueue(LQueue *Q)
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

Status EnLQueue(LQueue *Q, void *data)
{
    if(Q->front == NULL)
    {
        Q->front = (Node*)malloc(sizeof(Node));
        if(Q->front == NULL) return FALSE;
        Q->rear = Q->front;
        Q->rear->next = NULL;
        Q->length++;
        Q->front->data = data;
        return TRUE;
    }
    Q->rear->next = (Node*)malloc(sizeof(Node));
    if(Q->rear->next == NULL) return FALSE;
    Q->rear = Q->rear->next;
    Q->rear->data = data;
    Q->rear->next = NULL;
    Q->length++;
    return TRUE;
}

Status DeLQueue(LQueue *Q)
{
    if(Q->front == NULL) return FALSE;
    Node *temp = Q->front;
    Q->front = Q->front->next;
    free(temp);
    Q->length--;
    return TRUE;
}

void LPrint(void *q)
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

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
    if(Q->length == 0) return FALSE;
    Node *temp = Q->front;
    while(temp != NULL)
    {
        foo(temp->data);
        temp = temp->next;
    }
    return TRUE;
}
