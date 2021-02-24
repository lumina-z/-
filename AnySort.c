#include<stdio.h>
#include<time.h>          //���������ʱʱ��������
#include<stdlib.h>
#include"AnySort.h"
//ֱ�Ӳ�������
void InsertSort(RecordType r[], int length)
{
	int i;
    for (i = 2; i < length; i++)
    {
        r[0] = r[i];             //��������ļ�¼���ڼ�������
        int j = i - 1;
        while (r[0].key < r[j].key)
        {
            r[j + 1] = r[j];
            j = j - 1;
        }
        r[j + 1] = r[0];      //���������¼���뵽�������������
    }
}
//��ѡ������
void SelectSort(RecordType r[], int length)
{
    int x;
    //�������������n�����ӵ�һ����ʼ���Դ������������Ƚϣ���Ҫ�Ƚ�n-1��
    for (int i = 1; i <= length - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j <= length; j++)  //j��2��ʼ
        {
            if (r[j].key < r[k].key)
            {
                k = j;
            }
        }
        if (k != i)             //��r[j].key>=r[k].key ��r[k]��ֵ�����м����X��x[i]��ֵ����
        {
            x = r[i].key;               //r[i].keyΪ��С��
            r[i].key = r[k].key;
            r[k].key = x;

        }
    }
}
//ð������
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
//��������
int QKPass(RecordType r[], int left, int right) //һ�˿��������㷨
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
    return low;               //���ػ�׼��¼��λ��
}
//��������
void QKSort(RecordType r[], int low, int high)
{
    if (low < high)
    {
        int pos = QKPass(r, low, high);         //����һ�˿�������������Ԫ��Ϊ�绮������������
        QKSort(r, low, pos - 1);             //�����ӱ���п�������
        QKSort(r, pos + 1, high);             //���Ҳ��ӱ���п�������
    }
}
//������
void sift(RecordType r[], int n, int m)
{//�Ա��Ϊm�Ľڵ���е���
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
    //������
    int i;
    for (i = length / 2; i > 0; i--)
    {
        sift(r, length, i);
    }
    //����
    for (i = length; i > 1; i--)
    {
        r[0] = r[1];
        r[1] = r[i];
        r[i] = r[0];
        sift(r, i - 1, 1);
    }
}
//ϣ������
void ShellInsert(RecordType r[], int length, int delta)  //Shell���룬����delta Ϊ����
{
    int i, j;
    for (i = 1 + delta; i <= length; i++)
    {
        if (r[i].key < r[i - delta].key)
        {
            r[0] = r[i];          //����r[i](����������)
            for (j = i - delta; j > 0 && r[j].key > r[0].key; j -= delta)
            {
                r[j + delta] = r[j];
            }
            r[j + delta] = r[0];
        }
    }
}
void ShellSort(RecordType r[], int length, int delta[], int n)//ϣ������,deltaΪ�������飬nΪ�������鳤��
{
    for (int i = 0; i < n; i++)
    {
        ShellInsert(r, length, delta[i]);
    }
}
void ShowResult(RecordType* r, int length)        //������
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
    srand((unsigned)time(NULL)); //��ʼ�������
    for (int i = 1; i <= LEN; i++)
    {
        r[i].key = rand() % 100 + 1;       //����1-100֮��������
        printf("%d\t", r[i]);
        if (i % 10 == 0)                    //ÿ�����10����
        {
            printf("\n");
        }
    }
}
void Select()
{
    printf("------------�����㷨-----------\n");
    printf("* * * * 1��ֱ�Ӳ������� * * * *\n");
    printf("* * * * 2����ѡ������ * * * *\n");
    printf("* * * * 3��  ð������   * * * *\n");
    printf("* * * * 4��  ��������   * * * *\n");
    printf("* * * * 5��   ������    * * * *\n");
    printf("* * * * 6��  ϣ������   * * * *\n");
    printf("-------------------------------\n");

}
