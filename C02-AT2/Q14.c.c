#include <stdio.h>

struct Point {
    int x, y;
};

int main() {
    int n, i, j, k;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    struct Point p[n];

    printf("Enter the coordinates (x y):\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &p[i].x, &p[i].y);
    }

    printf("\nEdges of the Convex Hull are:\n");

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {

            int pos = 0, neg = 0;

            for (k = 0; k < n; k++) {
                if (k == i || k == j)
                    continue;

                int value = (p[j].x - p[i].x) * (p[k].y - p[i].y) -
                            (p[j].y - p[i].y) * (p[k].x - p[i].x);

                if (value > 0)
                    pos++;
                else if (value < 0)
                    neg++;
            }

            if (pos == 0 || neg == 0) {
                printf("(%d,%d) -> (%d,%d)\n",
                       p[i].x, p[i].y,
                       p[j].x, p[j].y);
            }
        }
    }

    return 0;
}