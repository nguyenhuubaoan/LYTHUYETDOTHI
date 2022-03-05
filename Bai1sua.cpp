#include <iostream>
#include <fstream>
#include <conio.h>
#define MAX 10
#define inputfile "M:/Test1_01.txt"

typedef struct GRAGPH
{
	int n;
	int a[MAX][MAX];
}DOTHI;

int DocMaTranKe(const char TenFile[100], DOTHI &g)
{
	FILE* f; 
	f = fopen(TenFile, "rt");
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

int KiemTraMaTranKeHopLe(DOTHI g)
{
	int i;
	for (i=0; i<g.n; i++)
	{
		if (g.a[i][i] != 0)
		return 0;
	}
		return 1;
}

int KiemTraDoThiVoHuong(DOTHI g)
{
	int i, j;
	for (i=0; i<g.n; i++)
	{
		for (j=0; j<g.n; j++)
		{
			if (g.a[i][j] != g.a[j][i])
			return 0;
		}
	}
return 1;
}
int Timbaccuadinh(DOTHI g)
{
	int Bac,i,j;
   	for(i = 0; i<g.n; i++) 
	{
      printf("bac cua dinh %d la:",i);
	  Bac = 0;
      for (j = 0; j<g.n; j++)
      if(g.a[i][j]>0)        
         Bac++;
    printf("%d",Bac);
	}
}

int main()
{
	DOTHI g;
	int n;
	int dinh;
	if (DocMaTranKe(inputfile, g) == 1)
	{
		printf("Da lay thong tin do thi tu file thanh cong.\n\n");
		XuatMaTranKe(g);
		printf("Bam 1 phim bat ki de bat dau xet tinh lien thong cua do thi ...\n\n");
		getch();
		if (KiemTraMaTranKeHopLe(g) == 1)
		printf ("Do thi hop le.\n");
		else
		printf ("Do thi khong hop le.\n");
		if (KiemTraDoThiVoHuong(g) == 1)
		printf ("Do thi vo huong.\n");
		else
		printf ("Do thi co huong.\n");
		Timbaccuadinh(g);
	}
}
