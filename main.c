#include <stdio.h>
#include <stdlib.h>

struct Sack
{
    int weight;
    int profit;
};

//array size is made 3 as 3 items are present in the Bag
struct Sack arr[3] = {
             {20, 100},{10, 60},{30, 120}
            };

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b =temp;
}

int partition(int d[], int low, int high)
{
    int pivot = d[high];
    int pIndex = low;
    int i;
    for(i = low; i < high; i++)
    {
        if(d[i] > pivot)
        {
            swap(&d[i], &d[pIndex]);
            swap(&arr[i].profit, &arr[pIndex].profit);
            swap(&arr[i].weight, &arr[pIndex].weight);
            pIndex++;
        }
    }
            swap(&d[high], &d[pIndex]);
            swap(&arr[high].profit, &arr[pIndex].profit);
            swap(&arr[high].weight, &arr[pIndex].weight);
    return pIndex;
}

void qSort(int d[], int low, int high)
{
    if(low < high)
    {
        int pIndex = partition(d, low, high);
        qSort(d, low, pIndex-1);
        qSort(d, pIndex+1, high);
    }
}

int fractional_Knap_Sack(struct Sack arr[], int maxWeight, int n)
{
    int d[n];
    int i;
    double finalProfit;
    int currentWeight, remainingWeight;

    for(i = 0; i < n; i++)
        d[i] = arr[i].profit / arr[i].weight;

    qSort(d, 0, n-1);

    for(i = 0; i < n; i++)
    {
        if(currentWeight + arr[i].weight <= maxWeight)
        {
            currentWeight += arr[i].weight;
            finalProfit += arr[i].profit;
        }
        else
        {
            remainingWeight = maxWeight - currentWeight;
            finalProfit += arr[i].profit * ((double)remainingWeight / arr[i].weight);
            break;
        }
    }

    return finalProfit;
}

int main()
{
    int maxWeight = 50;
    printf("The maximum profit can be made is Rs.%d\n", fractional_Knap_Sack(arr, maxWeight, 3));
    return 0;
}
