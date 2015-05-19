/*
 * Author: youngtrips
 * Created Time:  Tue 20 Oct 2009 07:14:23 PM CST
 * File Name: 3573.cpp
 * Description: 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define SQR(x) ((x)*(x))
#define MAXINT 0x7FFFFFFF
#define MAXINT64 0x7FFFFFFFFFFFFFFFLL
typedef long long int64;

#define MAXN 80002
#define MAXL 82
#define MAXM 300002

typedef struct {
	char key[MAXL];
	int flag;
}node_t;
node_t map[26][32][26];


void init() {
	memset(map, 0, sizeof(map));
}

int is_alph(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void get_abb(char& s, int& n, char& t, const char* wd) {
	int len = strlen(wd);
	int cnt;
	cnt = len - 2;
	s = wd[0];
	t = wd[len - 1];
	n = cnt;
	if(s >= 'A' && s <= 'Z') {
		s += 32;
	}
	if(t >= 'A' && t <= 'Z') {
		t += 32;
	}
}

int is_abb(char& s, int& n, char& t, const char* str) {
	int len = strlen(str);
	int tmp, i;
	if(len == 3 || len == 4) {
		tmp = 0;
		for(i = 1;i < len - 1; i++) {
			if(is_alph(str[i])) {
				return 0;
			}
			tmp = tmp * 10 + str[i] - '0';
		}
		if(tmp >= 2 && tmp <= 30) {
			s = str[0];
			t = str[len - 1];
			n = tmp;
			return 1;
		}
	}
	return 0;
}
int is_sep(char ch) {
	switch(ch) {
		case '-':
		case ',':
		case '.':
		case '"':
		case '(':
		case ')':
		case ':':
		case ';':
		case '!':
		case '?': 
			return 1;
	}
	return 0;
}

void solve() {
	char wd[MAXL];
	char ch, a, b;
	int i, n, x, y;
	while(1) {
		ch = getchar();
		if(ch == EOF) break;
		i = 0;
		while(ch != ' ' && !is_sep(ch) && ch != '\n' && ch != EOF) {
			wd[i++] = ch;
			ch = getchar();
		}
		wd[i] = '\0';
		if(i > 0) {
			if(is_abb(a, n, b, wd)) {
				if(a >= 'A' && a <= 'Z') {
					x = a - 'A';
				} else {
					x = a - 'a';
				}
				if(b >= 'A' && b <= 'Z') {
					y = b - 'A';
				} else {
					y = b - 'a';
				}
				if(map[x][n][y].flag == 1) {
					strcpy(wd, map[x][n][y].key);
					wd[0] = a;
					wd[strlen(wd) - 1] = b;
				}
				printf("%s", wd);
			} else {
				if(strlen(wd) >= 4) {
					get_abb(a, n, b, wd);
					x = a - 'a';
					y = b - 'a';
					if(map[x][n][y].flag == 1 && strcmp(map[x][n][y].key, wd) != 0) {
						map[x][n][y].flag = -1;
					}
					if(map[x][n][y].flag == 0) {
						map[x][n][y].flag = 1;
						strcpy(map[x][n][y].key, wd);
					}
				}
				printf("%s", wd);
			}
		}
		printf("%c", ch);
	}
}
int main() {
	init();
	solve();
	return 0;
}

