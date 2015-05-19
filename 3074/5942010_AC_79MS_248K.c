#include <stdio.h>
#include <string.h>
#define SQ_OFFSET 0
#define RW_OFFSET 81
#define CL_OFFSET 162
#define BX_OFFSET 243
#define MAX_ROW 750
#define MAX_COL 350
#define MAXN 9
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
int map[MAXN][MAXN];
int box[MAXN][MAXN];
int ans[MAX_ROW];
int top;
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
	    ans[++top] = r->r;
		for(j = r->right;j != r; j = j->right)
			cover(j->c);
		if(search(k + 1)) return 1;
		for(j = r->left;j != r; j = j->left)
			uncover(j->c);
        --top;
	}
	uncover(c);
	return 0;
}

int get_r(int r, int c, int num)
{
    return r * 81 + c * 9 + num;
}
int get_sq(int r, int c)
{
    return SQ_OFFSET + r * 9 + c;
}
int get_row(int r, int num)
{
    return RW_OFFSET + r * 9 + num;
}
int get_col(int c, int num)
{
    return CL_OFFSET + c * 9 + num;
}
int get_bx(int r, int c, int num)
{
    return BX_OFFSET + box[r][c] * 9 + num;
}
void init_bx()
{
    int ii, jj, i, j, k, x, y;
    k = -1;
    for(i = 0;i < 3; i++)
    {
        for(j = 0;j < 3; j++)
        {
            ++k;
            for(ii = 0;ii < 3; ii++)
            {
                x = i * 3 + ii;
                for(jj = 0;jj < 3; jj++)
                {
                    y = j * 3 + jj;
                    box[x][y] = k;
                }
            }
        }
    }
}
int init()
{
   char ch;
   int i, j;
   for(i = 0;i < 9; i++)
   {
       for(j = 0;j < 9; j++)
       {
           ch = getchar();
           if(ch == 'e') return 0;
           if(ch == '.') map[i][j] = -1;
           else map[i][j] = ch - '1';
       }
   }
   getchar();
   return 1;
}
void build_dlx()
{
    int sq_c, rw_c, cl_c, bx_c;
    int i, j, k, r;
    for(i = 0;i < 9; i++)
    {
        for(j = 0;j < 9; j++)
        {

            if(map[i][j] == -1)
            {
                for(k = 0;k < 9; k++)
                {
                    r = get_r(i, j, k);
                    sq_c = get_sq(i, j);
                    rw_c = get_row(i, k);
                    cl_c = get_col(j, k);
                    bx_c = get_bx(i, j, k);
                    add_node(r, sq_c);
                    add_node(r, rw_c);
                    add_node(r, cl_c);
                    add_node(r, bx_c);
                }
            }
            else
            {
                k = map[i][j];
                r = get_r(i, j, k);
                sq_c = get_sq(i, j);
                rw_c = get_row(i, k);
                cl_c = get_col(j, k);
                bx_c = get_bx(i, j, k);
                add_node(r, sq_c);
                add_node(r, rw_c);
                add_node(r, cl_c);
                add_node(r, bx_c);
            }
        }
    }
}
void output()
{
    int i, r, c, k;
    for(i = 1;i <= top; i++)
    {
        k = ans[i] % 9;
        c = ((ans[i] - k) % 81) / 9;
        r = (ans[i] - k - c * 9) / 81;
        map[r][c] = k + 1;
    }
    for(r = 0;r < 9; r++)
        for(c = 0;c < 9; c++) printf("%d", map[r][c]);
    printf("\n");
}
int main()
{
    n = 729; m = 324;
	init_bx();
	while(init())
	{
		init_dlx(n, m);
	    build_dlx();
        top = 0;
        search(0);
        output();
	}
	return 0;
}
