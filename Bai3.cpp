#include <iostream>
#include <fstream>
#include <conio.h>
#define MAX 10
#define inputfile "M:/Test03_01.txt"

typedef struct GRAPH
{
	int n;
	int a[MAX][MAX];
}DOTHI;

int DocMaTranKe(const char TenFile[100], DOTHI &g)
{
	FILE* f; 
	f = fopen("Test03_01.txt", "rt");
	if (f == NULL)
	{
		printf("Khong mo duoc file\n");
		return 0;
	}
	fscanf(f, "%d", &g.n);
	int i, j;
	for (i=0; i<g.n; i++)
		{
			for (j=0; j<g.n; j++)
			{
				fscanf(f, "%d", &g.a[i][j]); 
			}
		}
	fclose(f);
	return 1;
}

void XuatMaTranKe (DOTHI g)
{
	printf("So dinh cua do thi la %d\n", g.n);
	printf("Ma tran ke cua do thi la\n");
	for (int i = 0; i < g.n; i++)
		{
			printf ("\t");
			for (int j = 0; j < g.n; j++)
			{
				printf("%d ",g.a[i][j]);
			}
			printf("\n");
		}
}

struct STACK
{
	int array[100]; 
	int size; 
};

void khoitaoStack(STACK &stack)
{
	stack.size = 0; 
}

void DayGiaTriVaoStack(STACK &stack, int value)
{
	if(stack.size + 1 >= 100)
		return; 
	stack.array[stack.size] = value;
	stack.size++;
}

void TimDuongDi(int i, DOTHI &g, STACK & stack)
{
	for (int j = 0; j < g.n; j++)
	{
		if (g.a[i][j] != 0) 
		{
			g.a[i][j] = g.a[j][i] =0;
			TimDuongDi(j,g,stack);
		}
	}
		DayGiaTriVaoStack(stack,i);
}

int KiemTraChuTrinhEuler(DOTHI g)
{
	int x,d=0;
	for(int i=0;i<g.n;i++)
	{
  		for(int j=0;j<g.n;j++)
   		if(g.a[i][j]!=0)
   		{
    		x=i;
    		d=1;
    		break;
   		}
	if(d==1)
   	break;
 	}
 	int bac;
 	for(int i=0;i<g.n;i++)
 	{
  		bac=0;
  		for(int j=0;j<g.n;j++)
   		if(g.a[i][j]!=0)
    		bac++;
  		if(bac%2)
   		return 0;
 	}
 	DOTHI temp=g;
 	STACK stack;
 	khoitaoStack(stack);
 	TimDuongDi(x,temp,stack);
 	if(stack.array[stack.size-1]!=stack.array[0])
  	return 0;
 	printf("\nChu trinh Euler: ");
 	for(int i=stack.size-1;i>=0;i--)
 	{
  		printf("%d",stack.array[i]);
  		if(i>0)
   		printf("--->");
 	} 
 		return 1;
}

int main()
{
	DOTHI g;
	if (DocMaTranKe(inputfile, g) == 1)
	{
		printf("Da lay thong tin do thi tu file thanh cong.\n\n");
		XuatMaTranKe(g);
		printf("Bam 1 phim bat ki de bat dau xet tim chu trinh euler ...\n\n");
		getch();
		if (!KiemTraChuTrinhEuler(g))
		{
			printf("Khong co chu trinh Euler trong do thi cua ban\n");
			getch();
		}
	}
	getch();
}

