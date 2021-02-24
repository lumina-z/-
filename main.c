#include<stdio.h>
#include<time.h>          //产生随机数时时钟做种子
#include<stdlib.h>
#include"AnySort.h"
int main(void)
{
    int n, m;
    RecordType r[LEN+1] ;
    /*delta[] 是希尔排序的增量数组。增量的选取采用的是希尔提出的d=n/2 向下取整，
    直到d=1为止的方法，随机产生30个数30/2=15、15/2=7(向下取整的结果)、依次运算
    得到增量数组元素为15、7、3、1 */
    int delta[] = { 15, 7, 3, 1 };
    clock_t start, finish;
    double duration;
    do
    {	Select();
        printf("请选择排序算法：");
        scanf("%d", &m);
        system("cls");      //清屏
        switch (m)
        {
        case 1:
            printf("你选择了直接插入排序!\n");
            printf("\n");
            printf("产生的随机待排序列为：\n");
            RandNum(r);
            start = clock();
            InsertSort(r, LEN);
            finish = clock();
            duration = (double)(finish - start) / (double)CLOCKS_PER_SEC;
            printf("排序结果为：\n");
            ShowResult(r, LEN);
            printf( "算法执行时间是%f 秒\n", duration );
            break;
            system("cls");
        case 2:
            printf("你选择了简单选择排序!\n");
            printf("\n");
            printf("产生的随机待排序列为：\n");
            RandNum(r);
            start = clock();
            SelectSort(r, LEN);
            finish = clock();
            duration = (double)(finish - start) / (double)CLOCKS_PER_SEC;
            printf("排序结果为：\n");
            ShowResult(r, LEN);
            printf( "算法执行时间是%f 秒\n", duration );
            break;
        case 3:
            printf("你选择了冒泡排序!\n");
            printf("\n");
            printf("产生的随机待排序列为：\n");
            RandNum(r);
            start = clock();
            BubbleSort(r, LEN);
            finish = clock();
            duration = (double)(finish - start) / (double)CLOCKS_PER_SEC;
            printf("排序结果为：\n");
            ShowResult(r, LEN);
            printf( "算法执行时间是%f 秒\n", duration );
            break;
        case 4:
            printf("你选择了快速排序!\n");
            printf("\n");
            printf("产生的随机待排序列为：\n");
            RandNum(r);
            start = clock();
            QKSort(r, 1, LEN-1);
            finish = clock();
            duration = (double)(finish - start) / (double)CLOCKS_PER_SEC;
            printf("排序结果为：\n");
            ShowResult(r, LEN);
            printf( "算法执行时间是%f 秒\n", duration );
            break;
        case 5:
            printf("你选择了堆排序!\n");
            printf("\n");
            printf("产生的随机待排序列为：\n");
            RandNum(r);
            start = clock();
            HeapSort(r, LEN);
            finish = clock();
            duration = (double)(finish - start) / (double)CLOCKS_PER_SEC;
            printf("排序结果为：\n");
            ShowResult(r, LEN);
            printf( "算法执行时间是%f 秒\n", duration );
            break;
        case 6:
            printf("你选择了希尔排序!\n");
            printf("\n");
            printf("产生的随机待排序列为：\n");
            RandNum(r);
            start = clock();
            ShellSort(r, LEN, delta, 4);
            finish = clock();
            duration = (double)(finish - start) / (double)CLOCKS_PER_SEC;
            printf("排序结果为：\n");
            ShowResult(r, LEN);
            printf( "算法执行时间是%f 秒\n", duration );
            break;
        default:
            printf("输入有误！");
            return false;
            break;
        }
    } while (true);
    return 0;
}
