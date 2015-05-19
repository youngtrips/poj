#include <cstdio>
#include <string.h>
#include <map>
using namespace std;
struct spec_t
{
   char name[81];
};
bool operator==(const spec_t &a, const spec_t &b) 
{
   return !strcmp(a.name, b.name);
}
bool operator<(const spec_t &a, const spec_t &b) 
{
   return strcmp(a.name, b.name) < 0;
}
map <spec_t, int> spec;
spec_t tmp;
int cnt;
int main()
{
	cnt = 0;
	while(gets(tmp.name))
	{
		spec[tmp]++;
		cnt++;
	}
	for(map <spec_t,int>::iterator i = spec.begin(); i != spec.end(); *i++) 
      printf("%s %0.4lf\n", i->first.name, 100.0 * i->second / cnt);
	return 0;
}
