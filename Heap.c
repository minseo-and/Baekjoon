#include <stdio.h>

int n;
int min[100001];
int max[100001];
int minSize = 0;
int maxSize = 0;

void minPush(int value)
{
    min[minSize] = value;
    int res = minSize;
    while (res > 0 && min[res] < min[(res - 1) / 2])
    {
        int tmp = min[(res - 1) / 2];
        min[(res - 1) / 2] = min[res];
        min[res] = tmp;
        res = (res - 1) / 2;
    }
    minSize++;
}

void maxPush(int value)
{
    max[maxSize] = value;
    int res = maxSize;
    while (res > 0 && max[res] > max[(res - 1) / 2])
    {
        int tmp = max[(res - 1) / 2];
        max[(res - 1) / 2] = max[res];
        max[res] = tmp;
        res = (res - 1) / 2;
    }
    maxSize++;
}

void minHeapify()
{
    int res = 0;
    while (res * 2 + 1 < minSize)
    {
        int a;
        if (res * 2 + 2 == minSize) a = res * 2 + 1;
        else a = min[res * 2 + 1] < min[res * 2 + 2] ? res * 2 + 1 : res * 2 + 2;

        if (min[res] < min[a]) break;

        int tmp = min[res];
        min[res] = min[a];
        min[a] = tmp;
        res = a;
    }
}

void maxHeapify()
{
    int res = 0;
    while (res * 2 + 1 < maxSize)
    {
        int a;
        if (res * 2 + 2 == maxSize) a = res * 2 + 1;
        else a = max[res * 2 + 1] > max[res * 2 + 2] ? res * 2 + 1 : res * 2 + 2;

        if (max[res] > max[a]) break;

        int tmp = max[res];
        max[res] = max[a];
        max[a] = tmp;
        res = a;
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        int value;
        scanf("%d", &value);

        if (maxSize == minSize)
            maxPush(value);
        else
            minPush(value);

        if (maxSize > 0 && minSize > 0 && max[0] > min[0])
        {
            int tmp = max[0];
            max[0] = min[0];
            min[0] = tmp;

            minHeapify();
            maxHeapify();
        }

        printf("%d\n", max[0]);
    }
}