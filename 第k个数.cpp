/*����һ������Ϊ n���������У��Լ�һ������ k�����ÿ���ѡ���㷨������д�С���������ĵ� k������
 �����ʽ
 ��һ�а����������� n �� k��
 
 �ڶ��а��� n �������������������� 1�6�5109��Χ�ڣ�����ʾ�������С�
 
 �����ʽ
 ���һ����������ʾ���еĵ� k С����
 
 ���ݷ�Χ
 1��n��100000, 1��k��n
 
 ����������
 5 3
 2 4 1 5 3
 ���������
 3*/

 #include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n, k;
int q[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++; while (q[i] < x);
        do j --; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    quick_sort(q, 0, n - 1);
    printf("%d", q[k - 1]);
    
    return 0;
}