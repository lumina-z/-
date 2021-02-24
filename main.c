#include<stdio.h>
#include<time.h>          //���������ʱʱ��������
#include<stdlib.h>
#include"AnySort.h"
int main(void)
{
    int n, m;
    RecordType r[LEN+1] ;
    /*delta[] ��ϣ��������������顣������ѡȡ���õ���ϣ�������d=n/2 ����ȡ����
    ֱ��d=1Ϊֹ�ķ������������30����30/2=15��15/2=7(����ȡ���Ľ��)����������
    �õ���������Ԫ��Ϊ15��7��3��1 */
    int delta[] = { 15, 7, 3, 1 };
    clock_t start, finish;
    double duration;
    do
    {	Select();
        printf("��ѡ�������㷨��");
        scanf("%d", &m);
        system("cls");      //����
        switch (m)
        {
        case 1:
            printf("��ѡ����ֱ�Ӳ�������!\n");
            printf("\n");
            printf("�����������������Ϊ��\n");
            RandNum(r);
            start = clock();
            InsertSort(r, LEN);
            finish = clock();
            duration = (double)(finish - start) / (double)CLOCKS_PER_SEC;
            printf("������Ϊ��\n");
            ShowResult(r, LEN);
            printf( "�㷨ִ��ʱ����%f ��\n", duration );
            break;
            system("cls");
        case 2:
            printf("��ѡ���˼�ѡ������!\n");
            printf("\n");
            printf("�����������������Ϊ��\n");
            RandNum(r);
            start = clock();
            SelectSort(r, LEN);
            finish = clock();
            duration = (double)(finish - start) / (double)CLOCKS_PER_SEC;
            printf("������Ϊ��\n");
            ShowResult(r, LEN);
            printf( "�㷨ִ��ʱ����%f ��\n", duration );
            break;
        case 3:
            printf("��ѡ����ð������!\n");
            printf("\n");
            printf("�����������������Ϊ��\n");
            RandNum(r);
            start = clock();
            BubbleSort(r, LEN);
            finish = clock();
            duration = (double)(finish - start) / (double)CLOCKS_PER_SEC;
            printf("������Ϊ��\n");
            ShowResult(r, LEN);
            printf( "�㷨ִ��ʱ����%f ��\n", duration );
            break;
        case 4:
            printf("��ѡ���˿�������!\n");
            printf("\n");
            printf("�����������������Ϊ��\n");
            RandNum(r);
            start = clock();
            QKSort(r, 1, LEN-1);
            finish = clock();
            duration = (double)(finish - start) / (double)CLOCKS_PER_SEC;
            printf("������Ϊ��\n");
            ShowResult(r, LEN);
            printf( "�㷨ִ��ʱ����%f ��\n", duration );
            break;
        case 5:
            printf("��ѡ���˶�����!\n");
            printf("\n");
            printf("�����������������Ϊ��\n");
            RandNum(r);
            start = clock();
            HeapSort(r, LEN);
            finish = clock();
            duration = (double)(finish - start) / (double)CLOCKS_PER_SEC;
            printf("������Ϊ��\n");
            ShowResult(r, LEN);
            printf( "�㷨ִ��ʱ����%f ��\n", duration );
            break;
        case 6:
            printf("��ѡ����ϣ������!\n");
            printf("\n");
            printf("�����������������Ϊ��\n");
            RandNum(r);
            start = clock();
            ShellSort(r, LEN, delta, 4);
            finish = clock();
            duration = (double)(finish - start) / (double)CLOCKS_PER_SEC;
            printf("������Ϊ��\n");
            ShowResult(r, LEN);
            printf( "�㷨ִ��ʱ����%f ��\n", duration );
            break;
        default:
            printf("��������");
            return false;
            break;
        }
    } while (true);
    return 0;
}
