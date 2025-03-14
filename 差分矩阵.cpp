#include <iostream>

using namespace std;

const int N = 100010;
int n, m, q;
int a[N][N], b[N][N];

void insert(int l1, int r1, int l2, int r2, int c)
{
    b[l1][r1] += c;
    b[l1][r2 + 1] -= c;
    b[l2 + 1][r1] -= c;
    b[l2 + 1][r2 + 1] += c;
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
            insert(i, j, i, j, a[i][j]);
        }
    }

    while (q--)
    {
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + b[i][j];
            printf("%d", a[i][j]);
        }
    }

    puts(" ");

    return 0;
}