#include<stdio.h>
#include<time.h>          //产生随机数时时钟做种子
#include<stdlib.h>
#define MaxSize 50
#define LEN 10000
#define false 0
#define true 1
typedef struct
{
    int key;      //记录关键字
}RecordType;
void InsertSort(RecordType r[], int length);//直接插入排序
void SelectSort(RecordType r[], int length);//简单选择排序
void BubbleSort(RecordType r[], int length);//冒泡排序
int QKPass(RecordType r[], int left, int right); //一趟快速排序算法
void QKSort(RecordType r[], int low, int high); //快速排序
void sift(RecordType r[], int n, int m);//堆调整
void HeapSort(RecordType r[], int length);//堆排序
void ShellInsert(RecordType r[], int length, int delta);  //希尔排序,Shell插入，其中delta 为增量
void ShellSort(RecordType r[], int length, int delta[], int n);//希尔排序,delta为增量数组，n为增量数组长度
void ShowResult(RecordType* r, int length);        //输出结果
void RandNum(RecordType r[MaxSize]);//随机数生成
void Select();//选择菜单
