#include <stdio.h>
#include <stdlib.h>

int can_queen_move(int x1, int y1, int x2, int y2);

int main() {
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;

    printf("Enter the coordinates of the first chessboard square (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second chessbord square (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    if (can_queen_move(x1, y1, x2, y2)) {
        printf("Queen can move.\n");
    } else {
        printf("Queen can't move.\n");
    }

    return 0;
}

int can_queen_move(int x1, int y1, int x2, int y2) {
    return (x1 == x2)
        || (y1 == y2)
        || (abs(x1 - x2) == abs(y1 - y2));
}