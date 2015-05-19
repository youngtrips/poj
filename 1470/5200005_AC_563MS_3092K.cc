#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string.h>
using namespace std;
#define MAXN  1000
vector<int>  Tree[MAXN],  query[MAXN];
int  set[MAXN], ancestor[MAXN], rank[MAXN], root[MAXN], num[MAXN];
bool visite[MAXN];
int  n, m;
bool input()
{
    if( scanf("%d",&n)== EOF ) return false;
    for( int i= 0; i<= n; ++i )
    Tree[i].clear(), query[i].clear();
    memset( set, 0, sizeof(set) );
    memset( ancestor, 0, sizeof(ancestor) );
    memset( rank, 0, sizeof(rank) );
    memset( root, 0, sizeof(root) );
    memset( num, 0, sizeof(num) );
    memset( visite,false, sizeof(visite) );
    int u, v, d;
    for( int i= 0; i< n; ++i )
    {
        scanf("%d",&u );
        while( getchar()!= '(' );
        scanf("%d",&d);
        while( getchar()!= ')' );
        for( int j= 0; j< d; ++j )
        {
            scanf("%d",&v);
            Tree[u].push_back(v);
            root[v]++;
        }
    }
    scanf("%d",&m);
    for( int i= 0; i< m; ++i )
    {
        while( getchar()!= '(' );
        scanf("%d",&u );
        scanf("%d",&v );
        if( u== v ) query[u].push_back(u);
        else
        {
            query[u].push_back(v);
            query[v].push_back(u);
        }
        while( getchar()!= ')' );
    }
    return true;
}
void make_set( int u )
{
    set[u]= u;
}
int find_set( int u )
{
    while( u!= set[u] ) u= set[u];
    return u;
}
void union_set( int u, int v )
{
    int x= find_set(u), y= find_set(v);
    if( rank[x]> rank[y] ) set[y]= x;
    else
    {
        set[x]= y;
        if( rank[x]== rank[y] ) rank[y]++;
    }
}
void lca( int u )
{
    make_set(u);
    ancestor[u]= u;
    for( size_t i= 0; i< Tree[u].size(); ++i )
    {
        lca( Tree[u][i] );

        union_set( u, Tree[u][i] );
        ancestor[ find_set(u) ]= u;
    }
    visite[u]= true;
    for( size_t i= 0; i< query[u].size(); ++i )
    if( visite[ query[u][i] ] ) num[ ancestor[ find_set( query[u][i] ) ] ]++;
}
int main()
{
    while( input() )
    {
        for( int i= 1; i<= n; ++i )
        if( root[i]== 0 )
        {
            lca( i );
            break;
        }
        for( int i= 1; i<= n; ++i )
        if( num[i]> 0 ) printf("%d:%d\n", i, num[i] );
    }
    return 0;
}
