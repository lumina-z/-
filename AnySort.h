#include<stdio.h>
#include<time.h>          //���������ʱʱ��������
#include<stdlib.h>
#define MaxSize 50
#define LEN 10000
#define false 0
#define true 1
typedef struct
{
    int key;      //��¼�ؼ���
}RecordType;
void InsertSort(RecordType r[], int length);//ֱ�Ӳ�������
void SelectSort(RecordType r[], int length);//��ѡ������
void BubbleSort(RecordType r[], int length);//ð������
int QKPass(RecordType r[], int left, int right); //һ�˿��������㷨
void QKSort(RecordType r[], int low, int high); //��������
void sift(RecordType r[], int n, int m);//�ѵ���
void HeapSort(RecordType r[], int length);//������
void ShellInsert(RecordType r[], int length, int delta);  //ϣ������,Shell���룬����delta Ϊ����
void ShellSort(RecordType r[], int length, int delta[], int n);//ϣ������,deltaΪ�������飬nΪ�������鳤��
void ShowResult(RecordType* r, int length);        //������
void RandNum(RecordType r[MaxSize]);//���������
void Select();//ѡ��˵�
