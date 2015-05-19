#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long uint32_t;
#define MAXN_P 100003

void rotate_one(uint32_t *a)
{
    uint32_t tmp;
    int i;
    tmp = a[0];
    for(i = 0;i < 5; i++)
        a[i] = a[i + 1];
    a[5] = tmp;
}
void rerotate_one(uint32_t *a)
{
    uint32_t tmp;
    int i;
    tmp = a[5];
    for(i = 5;i >= 1; i--)
        a[i] = a[i-1];
    a[0] = tmp;
}

#define SAME(a, b) \
    ((a[0] == b[0] && \
      a[1] == b[1] && \
      a[2] == b[2] && \
      a[3] == b[3] && \
      a[4] == b[4] && \
      a[5] == b[5])|| \
     (a[0] == b[5] && \
      a[1] == b[4] && \
      a[2] == b[3] && \
      a[3] == b[2] && \
      a[4] == b[1] && \
      a[5] == b[0]))


uint32_t hashint( uint32_t a)
{
    a += ~(a<<15);
    a ^=  (a>>10);
    a +=  (a<<3);
    a ^=  (a>>6);
    a += ~(a<<11);
    a ^=  (a>>16);

    return a;
}

/*
uint32_t hash_key(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t a6)
{
    return hashint(a1 + a2 + a3 + a4 + a5 + a6) % MAXN_P;
}
*/

uint32_t hash_key(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t a6)
{
	uint32_t key;
    key = 0;
	key  = a1 & MAXN_P;
	key ^= a1 >> 8;
	
    key ^= a2 & MAXN_P;
	key ^= a2 >> 8;
	
    key ^= a3 & MAXN_P;
	key ^= a3 >> 8;
	
    key ^= a4 & MAXN_P;
	key ^= a4 >> 8;
    
    key ^= a5 & MAXN_P;
	key ^= a5 >> 8;
    
    key ^= a6 & MAXN_P;
	key ^= a6 >> 8;

	return key % MAXN_P; 
}

typedef struct list_node_t
{
    uint32_t a[6];
    struct list_node_t *next;
}list_node_t;

list_node_t list_node_pool[MAXN_P + 1024];
int ntot;

typedef struct 
{
    list_node_t *root;
}hash_node_t;

hash_node_t hash_table[MAXN_P];

void hash_init()
{
    memset(hash_table, 0x0, sizeof(hash_table));
    ntot = 0;
}

void hash_set(uint32_t *a)
{
    uint32_t key;
    hash_node_t *hash_node = NULL;
    list_node_t *p = NULL;

    key = hash_key(a[0], a[1], a[2], a[3], a[4], a[5]);

    hash_node = hash_table + key;
    if(hash_node->root == NULL)
    {
        p = list_node_pool + ntot++;
        p->a[0] = a[0];
        p->a[1] = a[1];
        p->a[2] = a[2];
        p->a[3] = a[3];
        p->a[4] = a[4];
        p->a[5] = a[5];
        p->next = NULL;
        hash_node->root = p;
    }
    else
    {
        /* insert into list */
        p = list_node_pool + ntot++;
        p->a[0] = a[0];
        p->a[1] = a[1];
        p->a[2] = a[2];
        p->a[3] = a[3];
        p->a[4] = a[4];
        p->a[5] = a[5];
        p->next = hash_node->root;
        hash_node->root = p;
    }
}

int hash_find(uint32_t *a)
{
    uint32_t key;
    hash_node_t *hash_node = NULL;
    list_node_t *p = NULL;

    key = hash_key(a[0], a[1], a[2], a[3], a[4], a[5]);

    hash_node = hash_table + key;
    if(hash_node->root != NULL)
    {
        p = hash_node->root;
        while(p)
        {
            if(SAME(p->a, a))
                return 1;
            p = p->next;
        }
    }
    return 0;
}

int main()
{
    uint32_t a[6];
    uint32_t b[6];
    int flag;
    int n;
    int i;
    hash_init();
    scanf("%d", &n);
    flag = 0;
    while(n--)
    {
        scanf("%lu %lu %lu %lu %lu %lu", a, a + 1, a + 2, a + 3, a + 4, a + 5);
        if(flag == 0)
        {
            memcpy(b, a, sizeof(uint32_t) * 6);
            for(i = 0;i < 6; i++)
            {
                rotate_one(b);
                if((flag = hash_find(b)))
                    break;
            }
        }
        if(flag == 0)
        {
            memcpy(b, a, sizeof(uint32_t) * 6);
            for(i = 0;i < 6; i++)
            {
                rerotate_one(b);
                if((flag = hash_find(b)))
                    break;
            }
        }
        if(flag == 0)
            hash_set(a);
    }
    printf("%s\n", flag ? "Twin snowflakes found." : "No two snowflakes are alike.");
    return 0;
}
