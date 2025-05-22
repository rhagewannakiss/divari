#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

void printDates(Date* dates, int n);
int compareByYearAndMonth(const void* a, const void* b);
int compareByMonth(const void* a, const void* b);
int compareByDay(const void* a, const void* b);


int main()
{
    int n = 0;
    printf("Enter number of datas: ");
    scanf("%d", &n);

    Date dates[n] = {};

    for (int i = 0; i < n; i++)
    {
        printf("Enter data %d (day month year): ", i + 1);
        scanf("%d %d %d", &dates[i].day, &dates[i].month, &dates[i].year);
    }

    qsort(dates, n, sizeof(Date), compareByDay);
    printf("\nSorted by days:\n");
    printDates(dates, n);

    qsort(dates, n, sizeof(Date), compareByMonth);
    printf("\nSorted by month:\n");
    printDates(dates, n);

    qsort(dates, n, sizeof(Date), compareByYearAndMonth);
    printf("\nSorted by year:\n");
    printDates(dates, n);

    return 0;
}

int compareByDay(const void* a, const void* b)
{
    Date* dateA = (Date*)a;
    Date* dateB = (Date*)b;
    return dateA->day - dateB->day;
}

int compareByMonth(const void* a, const void* b)
{
    Date* dateA = (Date*)a;
    Date* dateB = (Date*)b;
    return dateA->month - dateB->month;
}

int compareByYearAndMonth(const void* a, const void* b)
{
    Date* dateA = (Date*)a;
    Date* dateB = (Date*)b;
    if (dateA->year == dateB->year)
    {
        return dateA->month - dateB->month;
    }
    return dateA->year - dateB->year;
}


void printDates(Date* dates, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%02d-%02d-%d\n", dates[i].day, dates[i].month, dates[i].year);
    }
}