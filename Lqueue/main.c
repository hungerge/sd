#include <stdio.h>
#include <stdlib.h>
#include "Untitled1.h"
int main(int argc, const char * argv[]) {
    LQueue Q;
    InitLQueue(&Q);
    printf("\t\t\t������\n");
    printf("\t\t\t1.�½�����\n");
    printf("\t\t\t2.�ж��Ƿ�Ϊ��\n");
    printf("\t\t\t3.�õ����ж�Ԫ��\n");
    printf("\t\t\t4.���ջ\n");
    printf("\t\t\t5.����ջ\n");
    printf("\t\t\t6.��ⳤ��\n");
    printf("\t\t\t7.���\n");
    printf("\t\t\t8.��ջ\n");
    printf("\t\t\t9.��������\n");
    printf("\t\t\t10.����\n");
    printf("\t\t\t�����");
    int i = 0;
    scanf("%d",&i);
    while(1)
    {
        switch (i) {
            case 1:
            {
                LQueue Q;
                InitLQueue(&Q);
                printf("�����ɹ�\n");
                break;
            }
            case 2:
            {
                if(IsEmptyLQueue(&Q))
                {
                    printf("���п�\n");
                    break;
                }
                printf("����δ��");
                break;
            }
            case 3:
            {
                Type temp;
                if(!GetHeadLQueue(&Q, &temp))
                {
                    printf("���п�\n");
                    break;
                }
                int a = temp.type;
                switch(a)
                {
                    case 1:
                    {
                        printf("���ж�Ϊ%c",temp.character);
                        break;
                    }
                    case 2:
                    {
                        printf("���ж�Ϊ%s",temp.string);
                        break;
                    }
                    case 3:
                    {
                        printf("���ж�Ϊ%d",temp.integer);
                        break;
                    }
                    case 4:
                    {
                        printf("���ж�Ϊ%lf",temp.point);
                        break;
                    }
                }
                break;
            }
            case 4:
            {
                ClearLQueue(&Q);
                break;
            }
            case 5:
            {
                DestoryLQueue(&Q);
                break;
            }
            case 6:
            {
                int a;
                a = LengthLQueue(&Q);
                printf("����Ϊ%d\n",a);
                break;
            }
            case 7:
            {
                Type *e = NULL;
                void *a = getType(e);
                if(!EnLQueue(&Q, a))
                {
                    printf("����ʧ��\n");
                    break;
                }
                printf("����ɹ�");
                break;
            }
            case 8:
            {
                if(!DeLQueue(&Q))
                {
                    printf("���п�\n");
                    break;
                }
                printf("����ɹ�");
                break;
            }
            case 9:
            {
                if(!TraverseLQueue(&Q, LPrint))
                {
                    printf("���п�\n");
                    break;
                }
                printf("��������");
                break;
            }
            case 10:
            {
                return 0;
            }

            default:
                break;
        }
        rewind(stdin);
        printf("\t\t\t������\n");
        printf("\t\t\t1.�½�����\n");
        printf("\t\t\t2.�ж��Ƿ�Ϊ��\n");
        printf("\t\t\t3.�õ����ж�Ԫ��\n");
        printf("\t\t\t4.���ջ\n");
        printf("\t\t\t5.����ջ\n");
        printf("\t\t\t6.��ⳤ��\n");
        printf("\t\t\t7.���\n");
        printf("\t\t\t8.��ջ\n");
        printf("\t\t\t9.��������\n");
        printf("\t\t\t10.����\n");
        printf("\t\t\t�����");
        scanf("%d",&i);
    }
    return 0;
}