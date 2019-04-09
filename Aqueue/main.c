#include <stdio.h>
#include <stdlib.h>

#include "Aqueue.h"

int main(int argc, const char * argv[]) {
    AQueue Q;
    InitAQueue(&Q);
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
    printf("\t\t\t10.�ж��Ƿ�Ϊ��\n");
    printf("\t\t\t11.����\n");
    printf("\t\t\t�����");
    int i = 0;
    scanf("%d",&i);
    while(1)
    {
        switch (i) {
            case 1:
            {
                AQueue Q;
                InitAQueue(&Q);
                printf("�����ɹ�\n");
                break;
            }
            case 2:
            {
                if(IsEmptyAQueue(&Q))
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
                if(!GetHeadAQueue(&Q, &temp))
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
                ClearAQueue(&Q);
                break;
            }
            case 5:
            {
                DestoryAQueue(&Q);
                break;
            }
            case 6:
            {
                int a;
                a = LengthAQueue(&Q);
                printf("����Ϊ%d\n",a);
                break;
            }
            case 7:
            {
                Type *e = NULL;
                void *a = getType(e);
                if(!EnAQueue(&Q, a))
                {
                    printf("����ʧ��\n");
                    break;
                }
                printf("����ɹ�");
                break;
            }
            case 8:
            {
                if(!DeAQueue(&Q))
                {
                    printf("���п�\n");
                    break;
                }
                printf("����ɹ�");
                break;
            }
            case 9:
            {
                if(!TraverseAQueue(&Q, APrint))
                {
                    printf("���п�\n");
                    break;
                }
                printf("��������");
                break;
            }
            case 10:
            {
                if(IsFullAQueue(&Q))
                {
                    printf("������\n");
                    break;
                }
                printf("����δ��");
                break;
            }
            case 11:
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
        printf("\t\t\t10.�ж��Ƿ�Ϊ��\n");
        printf("\t\t\t11.����\n");
        printf("\t\t\t�����");
        scanf("%d",&i);
    }
    return 0;
}