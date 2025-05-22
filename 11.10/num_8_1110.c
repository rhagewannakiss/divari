#include <stdio.h>

struct Date {
    int month;
    int year;
};


int compareDates(struct Date date1, struct Date date2);
int isDateInRange(struct Date date, struct Date startDate, struct Date endDate);



int main() {
    struct Date dates[3] = {
        {4, 1812},
        {7, 2018},
        {0, 0}
    };

    printf("Enter the month and year of the third date (separated by spaces): ");
    scanf("%d %d", &dates[2].month, &dates[2].year);

    if (isDateInRange(dates[2], dates[0], dates[1]))
    {
        printf("Data %02d.%d  is in range from %02d.%d to %02d.%d.\n",
               dates[2].month, dates[2].year,
               dates[0].month, dates[0].year,
               dates[1].month, dates[1].year);
    }
    else
    {
        printf("Data %02d.%d is NOT in range from %02d.%d to %02d.%d.\n",
               dates[2].month, dates[2].year,
               dates[0].month, dates[0].year,
               dates[1].month, dates[1].year);
    }

    return 0;
}

int compareDates(struct Date date1, struct Date date2)
{
    if (date1.year < date2.year)
    {
        return -1;
    }
    else if (date1.year > date2.year)
    {
        return 1;
    }
    else
    {
        if (date1.month < date2.month)
        {
            return -1;
        }
        else if (date1.month > date2.month)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int isDateInRange(struct Date date, struct Date startDate, struct Date endDate) {
    return (compareDates(date, startDate) >= 0 && compareDates(date, endDate) <= 0);
}