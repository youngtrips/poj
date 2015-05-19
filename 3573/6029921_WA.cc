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
}set_t;
set_t has[MAXM];

int hash(const char* key) {
	int res, tmp, i;
	for(res = 0, i = 0;key[i] != '\0'; i++) {
		if(key[i] >= 'A' && key[i] <= 'Z') {
			tmp = key[i] - 'A' + 1;
			if(tmp >= 10) {
				res = res * 100 + tmp;
			} else {
				res = res * 10 + tmp;
			}
		} else if(key[i] >= 'a' && key[i] <= 'z') {
			tmp = key[i] - 'a' + 1;
			if(tmp >= 10) {
				res = res * 100 + tmp;
			} else {
				res = res * 10 + tmp;
			}
		} else {
			res = res * 10 + key[i] - '0';
		}
	}
	return res;
}

void init() {
	memset(has, 0, sizeof(has));
}

int is_alph(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void get_abb(char* abb, const char* wd) {
	int len = strlen(wd);
	int cnt;
	cnt = len - 2;
	abb[0] = wd[0];
	if(cnt >= 10) {
		abb[1] = cnt / 10 + '0';
		abb[2] = cnt % 10 + '0';
		abb[3] = wd[len - 1];
		abb[4] = '\0';
	} else {
		abb[1] = cnt + '0';
		abb[2] = wd[len - 1];
		abb[3] = '\0';
	}
}

int is_abb(const char* str) {
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
	char ab[MAXL];
	char ch, a, b;
	int i, p;
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
			if(is_abb(wd)) {
				p = strlen(wd);
				a = wd[0];
				b = wd[p-1];

				p = hash(wd);
				if(has[p].flag == 1) {
					strcpy(wd, has[p].key);
				}
				wd[0] = a;
				wd[strlen(wd)-1] = b;
				printf("%s", wd);
			} else {
				if(strlen(wd) >= 4) {
					get_abb(ab, wd);
					p = hash(ab);
					if(has[p].flag == 0) {
						has[p].flag = 1;
						strcpy(has[p].key, wd);
					} else if(has[p].flag == 1) {
						if(strcmp(has[p].key, wd) != 0) {
							has[p].flag = -1;
						}
					}
				}
				printf("%s", wd);
			}
		}
		printf("%c", ch);
	}
}
int main() {
//	freopen("input.txt", "r", stdin);
	init();
	solve();
	return 0;
}

