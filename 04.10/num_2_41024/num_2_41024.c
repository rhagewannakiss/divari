#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

int isInside(Point p);

int main() {
    Point p;

    printf("Enter (x y): ");
    scanf("%d %d", &p.x, &p.y);

    if (isInside(p))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}

int isInside(Point p)
{
    if (p.x >= -8 && p.x <= -4 && p.y >= (p.x / -2) && p.y <= ((-p.x + 8) / 2))
    {
        return 1;
    }
    return 0;
}

