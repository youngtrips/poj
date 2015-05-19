#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct point {
    int x;
    int y;
    int step;
}temp, tt;

int n, m;
point q[1500000];
int hash[1002][1002];
char map[1002][1002];
int rear, front;

void bfs(point temp) {
    int i;

    memset(hash, 0, sizeof(hash));
    rear = front = 0;

    hash[ temp.x ][ temp.y ] = 0;
    q[ rear ++ ] = temp;
    while(front < rear) {
        temp = q[ front++ ];

        for(i = 0; i < 4; i++) {
            tt.x = temp.x + dir[i][0];
            tt.y = temp.y + dir[i][1];
            tt.step = temp.step + 1;
            if(tt.x < 0 || tt.y < 0 || tt.x >= n || tt.y >= m)
                continue;
            if(map[tt.x][tt.y] == '.' && !hash[ tt.x ][ tt.y ]) {
                hash[ tt.x ][ tt.y ] = tt.step;
                q[ rear ++ ] = tt;
            }
        }
    }
}

int main() {

    int t;
    int i, j;
    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &m, &n);

        for(i = 0; i < n; i++) {
            scanf("%s", map[i]);
        }

        int flag = 0;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                if(map[i][j] == '.') {
                    temp.x = i;
                    temp.y = j;
                    temp.step = 0;
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }

        bfs(temp);
        temp.step = 0;

        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                if(hash[i][j] > temp.step) {
                    temp.step = hash[i][j];
                    temp.x = i;
                    temp.y = j;
                }
            }
        }


        temp.step = 0;
        bfs(temp);
        temp.step = 0;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                if(hash[i][j] > temp.step) {
                    temp.step = hash[i][j];
                    temp.x = i;
                    temp.y = j;
                }
            }
        }
        printf("Maximum rope length is %d.\n", temp.step);


    }
}
