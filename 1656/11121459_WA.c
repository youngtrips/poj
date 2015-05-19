#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;

#define BLACK   0x1
#define WHITE   0x2
#define MIXING  0x4
#define MAXN 128

/*
   NW | NE
   ---+---
   SW | SE
*/

#define INIT_NODE(node, x1, y1, x2, y2) \
        do { \
                node->x1 = x1; \
                node->y1 = y1; \
                node->x2 = x2; \
                node->y2 = y2; \
                node->color = WHITE; \
                node->nw = NULL; \
                node->ne = NULL; \
                node->sw = NULL; \
                node->se = NULL; \
        } while(0)

typedef struct quadtree_s {
        struct quadtree_s *nw;
        struct quadtree_s *ne;
        struct quadtree_s *sw;
        struct quadtree_s *se;
        short x1;
        short y1;
        short x2;
        short y2;
    BYTE color;
} quadtree_t;

quadtree_t nodes[MAXN * MAXN];
int tot = 0;

quadtree_t*
alloc_node(int x1, int y1,
                   int x2, int y2) {
        quadtree_t *node = &nodes[tot++];
        INIT_NODE(node, x1, y1, x2, y2);
        return node;
}

void
quadtree_build(quadtree_t *curr) {
        short x1 = curr->x1;
        short y1 = curr->y1;
        short x2 = curr->x2;
        short y2 = curr->y2;
        short midx = 0;
        short midy = 0;

        if (x1 == x2 && y1 == y2) {
                return;
        }

        midx = (x1 + x2) >> 1;
        midy = (y1 + y2) >> 1;

        curr->nw = alloc_node(x1, y1, midx, midy);
        quadtree_build(curr->nw);

        if (x1 != x2) {
                curr->sw = alloc_node(midx + 1, y1, x2, midy);
                quadtree_build(curr->sw);
        }
        if (y1 != y2) {
                curr->ne = alloc_node(x1, midy + 1, midx, y2);
                quadtree_build(curr->ne);
        }
        if (x1 != x2 && y1 != y2) {
                curr->se = alloc_node(midx + 1, midy + 1, x2, y2);
                quadtree_build(curr->se);
        }
}

quadtree_t*
init_quadtree(int n) {
        quadtree_t *root = alloc_node(1, 1, n, n);
        quadtree_build(root);
        return root;
}

void
quadtree_set(quadtree_t *curr,
                         int x1, int y1,
                         int x2, int y2,
                         BYTE color) {
    if (x1 > curr->x2 || x2 < curr->x1 ||
        y1 > curr->y2 || y2 < curr->y1) {
        return;
    }
    if (x1 <= curr->x1 && x2 >= curr->x2 &&
        y1 <= curr->y1 && y2 >= curr->y2) {
        curr->color = color;
        return;
    }
        BYTE mask = WHITE | BLACK;

    if (curr->nw) {
        if (curr->color & mask) curr->nw->color = curr->color;
        quadtree_set(curr->nw, x1, y1, x2, y2, color);
    }
    if (curr->ne) {
        if (curr->color & mask) curr->ne->color = curr->color;
        quadtree_set(curr->ne, x1, y1, x2, y2, color);
    }
    if (curr->sw) {
        if (curr->color & mask) curr->sw->color = curr->color;
        quadtree_set(curr->sw, x1, y1, x2, y2, color);
    }
    if (curr->se) {
        if (curr->color & mask) curr->se->color = curr->color;
        quadtree_set(curr->se, x1, y1, x2, y2, color);
    }
    curr->color = MIXING;
}

int
in_rect(int x1, int y1, int x2, int y2, int x, int y) {
        return (x >= x1 && x <= x2) && (y >= y1 && y <= y2);
}

int
quadtree_query(quadtree_t *curr, int x1, int y1, int x2, int y2) {
        if (curr == NULL) {
                return 0;
        }
        if (x1 <= curr->x1 && x2 >= curr->x2 &&
                y1 <= curr->y1 && y2 >= curr->y2) {
                if (curr->color & BLACK) {
                        return (curr->x2 - curr->x1 + 1) * (curr->y2 - curr->y1 + 1);
                } else if (curr->color & WHITE) {
                        return 0;
                }
        }
        return quadtree_query(curr->nw, x1, y1, x2, y2) +
                   quadtree_query(curr->ne, x1, y1, x2, y2) +
                   quadtree_query(curr->sw, x1, y1, x2, y2) +
                   quadtree_query(curr->se, x1, y1, x2, y2);
}

int
main(int argc, char *argv[]) {
        quadtree_t *root;
        char str[8];
        int x1, y1;
        int x2, y2;
        int l;
        int t;
        while (scanf("%d", &t) != EOF) {
                tot = 0;
                root = init_quadtree(100);
                while (t--) {
                        scanf("%s %d %d %d", str, &x1, &y1, &l);
                        x2 = x1 + l - 1;
                        y2 = y1 + l - 1;
                        if (str[0] == 'T') {
                                printf("%d\n", quadtree_query(root, x1, y1, x2, y2));
                        } else {
                                quadtree_set(root, x1, y1, x2, y2, str[0] == 'W' ? WHITE : BLACK);
                        }
                }
        }
        return 0;
}