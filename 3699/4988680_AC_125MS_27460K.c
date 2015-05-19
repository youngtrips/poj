#include <stdio.h>

#include <string.h>

#define INT 0

#define STR 1

#define MAX 200

typedef struct

{

	char name[MAX];

 	int type;

}Column;

typedef struct

{

	char value[MAX];

}Table;

typedef struct

{

	char op;

 	char v[MAX];

 	int index;

}Condition;

Column col[11];

Table table[10001][11];

Table result[10001][11];

int m_r;

int n_r;

int outputcol[11];

Condition cond;

int get_col_pos(char* str,int m)

{

	int i;

 	for(i = 0;i < m; i++)

  		if(!strcmp(str,col[i].name))

   			return i;

 	return -1;

}

int get_col_type(int p)

{

	if(col[p].type == INT)

		return INT;

	return STR;

}

void init_db(int m,int n)

{

	char tmp[MAX];

 	int i;

 	int j;

 	for(i = 0;i < m; i++)

 	{

  		scanf("%s %s",col[i].name,tmp);

  		if(!strcmp(tmp,"INT"))

   		col[i].type = INT;

  		else

   		col[i].type = STR;

 	}

 

 	for(i = 0;i < n; i++)

  		for(j = 0;j < m; j++)

   			scanf("%s",table[i][j].value);

}

int str_to_int(char* str)

{

	int tmp;

	int flag;

 	int i;

	flag = 1;

 	tmp = 0;

 	i = 0;

	if(str[i] == '-')

	{

		flag = -1;

		i++;

	}

 	while(str[i])

 	{

  		tmp = tmp * 10 + (str[i] - '0');

  		i++;

 	}

 	return tmp * flag;

}

void preoutput(int* outputcol, Condition cond,int n,int num_out)

{

	char str_cond[MAX];

 	int int_cond;

 	int con_col_type;

 	int flag;

 	int i;

 	int j;

 	con_col_type = get_col_type(cond.index);

 

 	for(i = 0;i < num_out; i++)

  		strcpy(result[0][i].value,col[outputcol[i]].name);

 	m_r = 1;

 	n_r = num_out;

 	if(con_col_type == INT)

 	{

  		int_cond = str_to_int(cond.v);

 		for(i = 0;i < n; i++)

  		{

   			flag = 0;

   			for(j = 0;j < num_out; j++)

   			{

    			if(cond.op == '>')

    			{

     				if(int_cond < str_to_int(table[i][cond.index].value))

     				{

      					flag = 1;

      					strcpy(result[m_r][j].value,table[i][outputcol[j]].value);

     				}

     				else

     			 		break;

    			}

    			else if(cond.op == '<')

    			{

     				if(int_cond > str_to_int(table[i][cond.index].value))

     				{

      					strcpy(result[m_r][j].value,table[i][outputcol[j]].value);

      					flag = 1;

     				}

    			 	else

     					break;

    			}

   		 		else if(cond.op == '=')

    			{

     				if(int_cond == str_to_int(table[i][cond.index].value))

     				{

      					strcpy(result[m_r][j].value,table[i][outputcol[j]].value);

      					flag = 1;

     				}

     				else

      					break;

   			 	}    

   			}

   			if(flag)

    			m_r++;

  		}

 	}

 	else

 	{

  		strcpy(str_cond,cond.v);

  		for(i = 0;i < n; i++)

  		{

   			flag = 0;

   			for(j = 0;j < num_out; j++)

   			{

    			if(!strcmp(table[i][cond.index].value,str_cond))

    			{

     				strcpy(result[m_r][j].value,table[i][outputcol[j]].value);

     				flag = 1;

    			}

    			else

     				break;

   			}

   			if(flag)

    			m_r++;

  		}

 	}

}

void format_output()

{

	int max_x;

 	int x[11];

 	int tmp;

 	int left;

 	int right;

 	int i;

 	int j;

 	int k;

 	for(i = 0;i < 11; i++)

  		x[i] = 0;

 	for(i = 0;i < m_r; i++)

 	{

  		for(j = 0;j < n_r; j++)

  		{

   			tmp = strlen(result[i][j].value);

   			if(tmp > x[j])

    		x[j] = tmp;

  		}

 	}

 	max_x = 0;

 	for(i = 0;i < n_r; i++)

  		max_x += x[i];	

 	printf("+");

 	for(i = 0;i < max_x + 2 * n_r + n_r - 1; i++)

  		printf("-");

 	printf("+\n");

 	printf("|");

 	for(i = 0;i < n_r; i++)

 	{

  		left = (x[i] + 2 - strlen(result[0][i].value)) / 2;

  		right = x[i] + 2 - left - strlen(result[0][i].value);

  		for(j = 0;j < left; j++)

   			printf(" ");

  		printf("%s",result[0][i].value);

  		for(j = 0;j < right; j++)

   			printf(" ");

  		printf("|");

 	}

 	printf("\n");

 	printf("|");

 	for(i = 0;i < n_r; i++)

 	{

  		for(j = 0;j < x[i] + 2; j++)

   			printf("-");

  		printf("|");

 	}

 	printf("\n");

 	for(k = 1;k < m_r; k++)

 	{

  		printf("|");

  		for(i = 0;i < n_r; i++)

  		{

   			left = (x[i] + 2 - strlen(result[k][i].value)) / 2;

   			right = x[i] + 2 - left - strlen(result[k][i].value);

   			for(j = 0;j < left; j++)

    			printf(" ");

   			printf("%s",result[k][i].value);

   			for(j = 0;j < right; j++)

    			printf(" ");

   			printf("|");

  		}

  		printf("\n");

 	}

 	printf("+");

 	for(i = 0;i < max_x + 2 * n_r + n_r - 1; i++)

  		printf("-");

 	printf("+\n");

}

void query(char* sql,int m,int n)

{

	char tmp[MAX];

 	int num_out;

 	int i;

 	int j;

 	int k;

 	i = 0;

 	k = 0;

 	while(sql[i] == ' ')

  		i++;

 	while(sql[i] != ' ')

  		i++;

 	while(sql[i] == ' ')

		i++;

 	while(1)

 	{

  		j = 0;

  		while(sql[i] != ',' && sql[i] != ' ')

  		{

   			tmp[j] = sql[i];

   			j++;

   			i++;

  		}

		if(j != 0)

		{

  			tmp[j] = '\0';

			if(!strcmp(tmp,"where") || !strcmp(tmp,"WHERE"))

				break;

  			outputcol[k] = get_col_pos(tmp,m);

			k++;

		}

  		i++;

 	}

 	num_out = k;

 	while(sql[i] == ' ')

		i++;

 	j = 0;

 	while(sql[i] != '=' && sql[i] != '>' && sql[i] != '<' && sql[i] != ' ')

 	{

  		tmp[j] = sql[i];

  		j++;

  		i++;

 	}

 	tmp[j] = '\0';

 	k = get_col_pos(tmp,m);

 	cond.index = k;

	

	while(sql[i] == ' ')

		i++;



 	cond.op = sql[i];

	i++;

	while(sql[i] == ' ' || sql[i] == '\"')

		i++;



	j = 0;

	while(sql[i] != '\0' && sql[i] != '\"')

 	{

  		tmp[j] = sql[i];

  		j++;

  		i++; 

 	}

 	tmp[j] = '\0';

 	strcpy(cond.v,tmp);

 	preoutput(outputcol,cond,n,num_out);

 	format_output();

}

int main()

{

	char sql[1001];

 	int m;

 	int n;

 	int k;

 	int i;

 	int j;

 	scanf("%d %d %d",&m,&n,&k);

 	init_db(m,n);

 	getchar();

 	while(k--)

 	{

  		gets(sql);

  		query(sql,m,n);

  		printf("\n");

 	}

 	return 0;

}

