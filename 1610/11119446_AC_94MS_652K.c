#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 512

typedef unsigned char BYTE;
typedef unsigned long long UINT64;

typedef struct {
        int x;
        int y;
        int n;
} node_t;

BYTE image[MAXN][MAXN];
int n;
node_t que[MAXN * MAXN];
int head;
int tail;

void
partition(int x, int y, int n) {
        UINT64 res;
        int sum;
        int i;
        int j;
        node_t *curr;
        node_t *next;
        head = 0;
        tail = 0;
        que[tail].x = x;
        que[tail].y = y;
        que[tail].n = n;
        ++tail;
        res = 0;
        while (head < tail) {
                curr = &que[head++];
                x = curr->x;
                y = curr->y;
                n = curr->n;

                sum = 0;
                for (i = 0;i < n; i++) {
                        for (j = 0;j < n; j++) {
                                sum += image[i+y][j+x];
                        }
                }

                if (sum == 0 || sum == n * n) {
                        res = (res<<2) | (sum == 0 ? 0x0 : 0x1);
                        continue;
                }

                res = (res<<1) | 0x1;

                n >>= 1;
                if (n > 0) {

                        next = &que[tail++];
                        next->x = x;
                        next->y = y;
                        next->n = n;

                        next = &que[tail++];
                        next->x = x + n;
                        next->y = y;
                        next->n = n;

                        next = &que[tail++];
                        next->x = x;
                        next->y = y + n;
                        next->n = n;

                        next = &que[tail++];
                        next->x = x + n;
                        next->y = y + n;
                        next->n = n;
                }
        }
        printf("%llX\n", res);
}

void
do_solve() {
        partition(0, 0, n);
}


int
main(int argc, char *argv[]) {
        int k;
        int i;
        int j;
        int v;
        scanf("%d", &k);
        while (k--) {
                scanf("%d", &n);
                memset(image, 0, sizeof(image));
                for (i = 0;i < n; i++) {
                        for (j = 0;j < n; j++) {
                                scanf("%d", &v);
                                image[i][j] = v & 0xFF;
                        }
                }
                do_solve();
        }
        return 0;
}
