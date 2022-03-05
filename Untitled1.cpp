#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 10 
#define inputfile "C:/Users/Admin/Desktop/Test2/Test2.txt" 

typedef struct GRAPH {
	int n; 
	int a[MAX][MAX]; 
}DOTHI;

int DocMaTranKe(char TenFile[100], DOTHI &g)
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

void TimCacDinhLienThong (DOTHI g, int nhan[MAX], int i)
{
	for (int j = 0; j < g.n; j++)
	{
		if (g.a[i][j] != 0 && nhan[j] != nhan[i]) 
		{
			nhan[j] = nhan[i]; 
			TimCacDinhLienThong (g, nhan, j); 
		}
	}
}

void XetLienThong(DOTHI g)
{
	int Nhan[MAX]; 
	int i;
	for (i=0;i<g.n;i++) 
	Nhan[i] =0;
	int SoThanhPhanLT = 0; 
	for (i=1; i<g.n; i++)
	{
		if (Nhan[i] == 0) 
		{
			SoThanhPhanLT ++; 
			Nhan[i] = SoThanhPhanLT; 
			TimCacDinhLienThong(g, Nhan, i); 
		}
	}
	printf ("So thanh phan lien thong la %d\n",SoThanhPhanLT);
	for (i = 1; i <= SoThanhPhanLT; i++)
	{
		printf("Thanh phan lien thong thu %d gom cac dinh: %d", i,Nhan[i]);
		printf("\n");
	}
}

int main()
{
	DOTHI g;
	if (DocMaTranKe(inputfile, g) == 1)
	{
		printf("Da lay thong tin do thi tu file thanh cong.\n\n");
		XuatMaTranKe(g);
		printf("Bam 1 phim bat ki de tien hanh kiem tra do thi ...\n\n");
		getch();
		if (KiemTraMaTranKeHopLe(g) == 1)
		printf ("Do thi hop le.\n");
		else
		printf ("Do thi khong hop le.\n");
		XetLienThong(g);
		return 0;
	}
}

