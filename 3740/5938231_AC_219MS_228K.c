#include <stdio.h>
#include <string.h>
#define MAX_ROW 18
#define MAX_COL 302
struct node_t
{
	int r, c;
	struct node_t* left;
	struct node_t* right;
	struct node_t* up;
	struct node_t* down;
};
struct node_t spool[MAX_ROW * MAX_COL];
struct node_t row[MAX_ROW];
struct node_t col[MAX_COL];
struct node_t root;
int size[MAX_COL];
int tot, n, m;
void init_dlx(int r, int c)
{
	
	int i;
	root.r = r; root.c = c;
	root.left = &root;
	root.right = &root;
	root.up = &root;
	root.down = &root;
	memset(size, 0, sizeof(size));
	tot = 0;
	for(i = 0;i < c; i++)
	{
		col[i].r = r;
		col[i].c = i;
		col[i].left = &root;
		col[i].right = root.right;
		col[i].left->right = &col[i];
		col[i].right->left = &col[i];
		col[i].up = &col[i];
		col[i].down = &col[i];
	}
	for(i = r - 1;i >= 0; i--)
	{
		row[i].c = c;
		row[i].r = i;
		row[i].left = &row[i];
		row[i].right = &row[i];
		row[i].up = &root;
		row[i].down = root.down;
		row[i].up->down = &row[i];
		row[i].down->up = &row[i];
	}
}

void add_node(int r, int c)
{
	struct node_t* ptr = spool + tot++;
	size[c]++;
	ptr->r = r;
	ptr->c = c;
	ptr->right = &row[r];
	ptr->left = row[r].left;
	ptr->left->right = ptr;
	ptr->right->left = ptr;
	ptr->up = &col[c];
	ptr->down = col[c].down;
	ptr->up->down = ptr;
	ptr->down->up = ptr;
}
void cover(int c)
{
	struct node_t* i;
	struct node_t* j;
	if(c == m) return;
	col[c].right->left = col[c].left;
	col[c].left->right = col[c].right;

	for(i = col[c].down;i != &col[c]; i = i->down)
	{
		if(i->c == m) continue;
		for(j = i->right;j != i; j = j->right)
		{
			j->down->up = j->up;
			j->up->down = j->down;
			size[j->c]--;
		}
	}
}
void uncover(int c)
{
	struct node_t* i;
	struct node_t* j;
	if(c == m) return;
	
	for(i = col[c].up;i != &col[c]; i = i->up)
	{
		if(i->c == m) continue;
		for(j = i->left;j != i; j = j->left)
		{
			size[j->c]++;
			j->down->up = j;
			j->up->down = j;
		}
	}
	col[c].right->left = &col[c];
	col[c].left->right = &col[c];
}

int search(int k)
{
	struct node_t* r;
	struct node_t* j;
	int max = 0x7fffffff;
	int c;
	if(root.right == &root) return 1;
	for(j = root.right;j != &root; j = j->right)
	{
		if(max > size[j->c])
		{
			max = size[j->c];
			c = j->c;
		}
	}
	cover(c);
	for(r = col[c].down;r != &col[c]; r = r->down)
	{
		for(j = r->right;j != r; j = j->right)
			cover(j->c);
		if(search(k + 1)) return 1;
		for(j = r->left;j != r; j = j->left)
			uncover(j->c);
	}
	uncover(c);
	return 0;
}
int main()
{
	int i, j, k;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		init_dlx(n, m);
		for(i = 0;i < n; i++)
		{
			for(j = 0;j < m; j++)
			{
				scanf("%d", &k);
				if(k == 1) add_node(i, j);
			}
		}
		if(search(0)) printf("Yes, I found it\n");
		else printf("It is impossible\n");
	}
	return 0;
}
