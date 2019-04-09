#include <stdio.h>
#include <stdlib.h>
#include "Untitled1.h"
int main(int argc, const char * argv[]) {
    LQueue Q;
    InitLQueue(&Q);
    printf("\t\t\t请输入\n");
    printf("\t\t\t1.新建队列\n");
    printf("\t\t\t2.判断是否为空\n");
    printf("\t\t\t3.得到队列顶元素\n");
    printf("\t\t\t4.清空栈\n");
    printf("\t\t\t5.销毁栈\n");
    printf("\t\t\t6.检测长度\n");
    printf("\t\t\t7.入队\n");
    printf("\t\t\t8.出栈\n");
    printf("\t\t\t9.遍历队列\n");
    printf("\t\t\t10.结束\n");
    printf("\t\t\t这边请");
    int i = 0;
    scanf("%d",&i);
    while(1)
    {
        switch (i) {
            case 1:
            {
                LQueue Q;
                InitLQueue(&Q);
                printf("建立成功\n");
                break;
            }
            case 2:
            {
                if(IsEmptyLQueue(&Q))
                {
                    printf("队列空\n");
                    break;
                }
                printf("队列未空");
                break;
            }
            case 3:
            {
                Type temp;
                if(!GetHeadLQueue(&Q, &temp))
                {
                    printf("队列空\n");
                    break;
                }
                int a = temp.type;
                switch(a)
                {
                    case 1:
                    {
                        printf("队列顶为%c",temp.character);
                        break;
                    }
                    case 2:
                    {
                        printf("队列顶为%s",temp.string);
                        break;
                    }
                    case 3:
                    {
                        printf("队列顶为%d",temp.integer);
                        break;
                    }
                    case 4:
                    {
                        printf("队列顶为%lf",temp.point);
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
                printf("长度为%d\n",a);
                break;
            }
            case 7:
            {
                Type *e = NULL;
                void *a = getType(e);
                if(!EnLQueue(&Q, a))
                {
                    printf("申请失败\n");
                    break;
                }
                printf("加入成功");
                break;
            }
            case 8:
            {
                if(!DeLQueue(&Q))
                {
                    printf("队列空\n");
                    break;
                }
                printf("弹射成功");
                break;
            }
            case 9:
            {
                if(!TraverseLQueue(&Q, LPrint))
                {
                    printf("队列空\n");
                    break;
                }
                printf("遍历结束");
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
        printf("\t\t\t请输入\n");
        printf("\t\t\t1.新建队列\n");
        printf("\t\t\t2.判断是否为空\n");
        printf("\t\t\t3.得到队列顶元素\n");
        printf("\t\t\t4.清空栈\n");
        printf("\t\t\t5.销毁栈\n");
        printf("\t\t\t6.检测长度\n");
        printf("\t\t\t7.入队\n");
        printf("\t\t\t8.出栈\n");
        printf("\t\t\t9.遍历队列\n");
        printf("\t\t\t10.结束\n");
        printf("\t\t\t这边请");
        scanf("%d",&i);
    }
    return 0;
}
