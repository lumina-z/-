#include<stdio.h>
#include<time.h>          //产生随机数时时钟做种子
#include<stdlib.h>
#include"AnySort.h"
//直接插入排序
void InsertSort(RecordType r[], int length)
{
	int i;
    for (i = 2; i < length; i++)
    {
        r[0] = r[i];             //将待插入的记录放在监视哨中
        int j = i - 1;
        while (r[0].key < r[j].key)
        {
            r[j + 1] = r[j];
            j = j - 1;
        }
        r[j + 1] = r[0];      //将待插入记录插入到已排序的序列中
    }
}
//简单选择排序
void SelectSort(RecordType r[], int length)
{
    int x;
    //假设待排序列有n个数从第一个开始，以次与其后面的数比较，需要比较n-1次
    for (int i = 1; i <= length - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j <= length; j++)  //j从2开始
        {
            if (r[j].key < r[k].key)
            {
                k = j;
            }
        }
        if (k != i)             //当r[j].key>=r[k].key 将r[k]的值借助中间变量X与x[i]的值交换
        {
            x = r[i].key;               //r[i].key为最小数
            r[i].key = r[k].key;
            r[k].key = x;

        }
    }
}
//冒泡排序
void BubbleSort(RecordType r[], int length)
{
    int t;
    for (int i = 1; i <= length; i++)
    {
        for (int j = 1; j <= length - i - 1; j++)
        {
            if (r[j].key > r[j + 1].key)
            {
                t = r[j+1].key;
                r[j + 1].key = r[j].key;
                r[j].key = t;
            }
        }
    }
}
//快速排序
int QKPass(RecordType r[], int left, int right) //一趟快速排序算法
{
    int low = left;
    int high = right;
    r[0] = r[left];
    while (low < high)
    {
        while (low<high && r[high].key>r[0].key)
        {
            high--;
        }
        if (low < high)
        {
            r[low] = r[high];
            low++;
        }
        while (low < high && r[low].key < r[0].key)
        {
            low++;
        }
        if (low < high)
        {
            r[high] = r[low];
            high--;
        }
    }
    r[low] = r[0];
    return low;               //返回基准记录的位置
}
//快速排序
void QKSort(RecordType r[], int low, int high)
{
    if (low < high)
    {
        int pos = QKPass(r, low, high);         //调用一趟快速排序，以枢轴元素为界划分两个子区间
        QKSort(r, low, pos - 1);             //对左部子表进行快速排序
        QKSort(r, pos + 1, high);             //对右部子表进行快速排序
    }
}
//堆排序
void sift(RecordType r[], int n, int m)
{//对编号为m的节点进行调整
    int i = m;
    r[0] = r[i];
    int j = 2 * i;
    while (j <= n)
    {
        if (j < n && r[j].key<r[j + 1].key)
        {
            j = j + 1;
        }
        if (r[j].key>r[0].key)
        {
            r[i] = r[j];
            i = j;
            j = 2 * i;
        }
        else
        {
            break;
        }
    }
    r[i] = r[0];
}
void HeapSort(RecordType r[], int length)
{
    //初建堆
    int i;
    for (i = length / 2; i > 0; i--)
    {
        sift(r, length, i);
    }
    //调整
    for (i = length; i > 1; i--)
    {
        r[0] = r[1];
        r[1] = r[i];
        r[i] = r[0];
        sift(r, i - 1, 1);
    }
}
//希尔排序
void ShellInsert(RecordType r[], int length, int delta)  //Shell插入，其中delta 为增量
{
    int i, j;
    for (i = 1 + delta; i <= length; i++)
    {
        if (r[i].key < r[i - delta].key)
        {
            r[0] = r[i];          //备份r[i](不做监视哨)
            for (j = i - delta; j > 0 && r[j].key > r[0].key; j -= delta)
            {
                r[j + delta] = r[j];
            }
            r[j + delta] = r[0];
        }
    }
}
void ShellSort(RecordType r[], int length, int delta[], int n)//希尔排序,delta为增量数组，n为增量数组长度
{
    for (int i = 0; i < n; i++)
    {
        ShellInsert(r, length, delta[i]);
    }
}
void ShowResult(RecordType* r, int length)        //输出结果
{

    for (int i = 1; i <= length; i++)
    {
        printf("%d\t", r[i]);

        if (i % 10 == 0)
        {
            printf("\n");
        }
    }
}
void RandNum(RecordType r[MaxSize])
{
    srand((unsigned)time(NULL)); //初始化随机数
    for (int i = 1; i <= LEN; i++)
    {
        r[i].key = rand() % 100 + 1;       //产生1-100之间的随机数
        printf("%d\t", r[i]);
        if (i % 10 == 0)                    //每行输出10个数
        {
            printf("\n");
        }
    }
}
void Select()
{
    printf("------------排序算法-----------\n");
    printf("* * * * 1：直接插入排序 * * * *\n");
    printf("* * * * 2：简单选择排序 * * * *\n");
    printf("* * * * 3：  冒泡排序   * * * *\n");
    printf("* * * * 4：  快速排序   * * * *\n");
    printf("* * * * 5：   堆排序    * * * *\n");
    printf("* * * * 6：  希尔排序   * * * *\n");
    printf("-------------------------------\n");

}
