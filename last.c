/*      ali.sh      */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

int n,m;//n = satr, m = soton

char list[100][100]={'\0'};

struct adres
{
	int i;
	int j;
};

struct adres setare[1000000];

int t=0;//teadad setareha

void open (){
	FILE *ptf = fopen("testcase02.txt","r");
	int i = 0,j = 0;
	char w;
	fscanf(ptf,"%c",&w);
	while(1){
		char a[10];
		while (1){
			fscanf(ptf,"%s",a);
			if (j==0) list[i][j]=a[4];
			else list[i][j]=a[3];
			j++;
			if (a[7]=='}') break;
		}
		if (a[8]=='}') break;
		i++;
		j=0;
	}
	fclose(ptf);
}//in marbot be khondan avalie ast

void oopen (){
	FILE *ptf = fopen("testcase02.txt","r");
	int i = 0,j = 0;
	char w;
	fscanf(ptf,"%c",&w);
	while(1){
		char a[10];
		while (1){
			fscanf(ptf,"%s",a);
			if (j==0) list[i][j]=a[4];
			else list[i][j]=a[3];
			j++;
			if (a[7]=='}') break;
		}
		if (a[8]=='}') break;
		i++;
		j=0;
	}
	fclose(ptf);
}//in marbot be khondan avalie ast baraye bakhsh 2

void setereha(){
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (list[i][j]=='0')
			{
				setare[t].i=i;
				setare[t].j=j;
				t++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (list[i][j]=='*')
			{
				setare[t].i=i;
				setare[t].j=j;
				t++;
			}
		}
	}
}//peyda kardan makan setareha

void matrisyab(int x,int y,int rah[]){
	int a1=0,a2=0,a3=0,a4=0;
	if (rah[x*n+y+1]==-1) a1=1;
	if (rah[x*n+y-1]==-1) a2=1;
	if (rah[(x+1)*n+y]==-1) a3=1;
	if (rah[(x-1)*n+y]==-1) a4=1;
	if (y<m-1&&list[x][y+1]=='#') rah[x*n+y+1]=0;
	if (y<m-1&&rah[x*n+y+1]==-1) rah[x*n+y+1]=rah[x*n+y]+1;
	if (y>0&&list[x][y-1]=='#') rah[x*n+y-1]=0;
	if (y>0&&rah[x*n+y-1]==-1) rah[x*n+y-1]=rah[x*n+y]+1;
	if (x<n-1&&list[x+1][y]=='#') rah[(x+1)*n+y]=0;
	if (x<n-1&&rah[(x+1)*n+y]==-1) rah[(x+1)*n+y]=rah[x*n+y]+1;
	if (x>0&&list[x-1][y]=='#') rah[(x-1)*n+y]=0;
	if (x>0&&rah[(x-1)*n+y]==-1) rah[(x-1)*n+y]=rah[x*n+y]+1;
	if (y<m-1&&a1==1) matrisyab(x,y+1,rah);
	if (y>0&&a2==1) matrisyab(x,y-1,rah);
	if (x<n-1&&a3==1) matrisyab(x+1,y,rah);
	if (x>0&&a4==1) matrisyab(x-1,y,rah);
}

int rahyab(struct adres key[],int i1,int j1,int i2,int j2){
	int rah[n*m];
	for (int jjj=0;jjj<m*n;jjj++) rah[jjj]=-1;
	int x=j1+n*i1;
	rah[x]=0;
	matrisyab(i1,j1,rah);
	masiryab(key,rah,i1,j1,i2,j2);
	return rah[j2+n*i2];
}//peyda kardan rah baine 2 makan

void masiryab(struct adres key[],int rah[],int i1,int j1,int i2,int j2){
	int x,y,z;
	x=i2;
	y=j2;
	z=x*n+y;
	key[rah[z]].i=x;
	key[rah[z]].j=y;
	if (x==i1&&y==j1) return;
	if (rah[z]==rah[z+1]-1) masiryab(key,rah,i1,j1,i2,j2+1);
	if (rah[z]==rah[z-1]-1) masiryab(key,rah,i1,j1,i2,j2-1);
	if (rah[z]==rah[z+n]-1) masiryab(key,rah,i1,j1,i2+1,j2);
	if (rah[z]==rah[z-n]-1) masiryab(key,rah,i1,j1,i2-1,j2);
}

void printlahzeie(struct adres key[],int nn,int i1,int j1,int i2,int j2){
	int x,y;
	system("cls");
	x=i1;
	y=j1;
	for (int i=0;i<n;i++){
		printf("%s\n",list[i]);
	}
	if (x==i2&&y==j2) return;
	list[i1][j1]='1';
	list[key[1].i][key[1].j]='0';
	nn--;
	i1=key[1].i;
	j1=key[1].j;
	for (int i = 1; i < nn+6; i++){
		key[i-1].i=key[i].i;
		key[i-1].j=key[i].j;
	}
	sleep(1);
	printlahzeie(key,nn,i1,j1,i2,j2);
}

void gameplay(){
	int k=0;
	int nn,mm;
	for (int i=0;i<18;i++){
		for (int j=0;j<18;j++){
			if (list [i][j]=='*') k=1;
			if (list [i][j]=='0'){
				nn=i;
				mm=j;	
			}
		}
	}
	if (k==0) return;
	system("cls");
	for (int i=0;i<18;i++){
		printf("%s\n",list[i]);
	}
	unsigned char a;
	char b='\0';
	a=getch();
	if (a=='-') {
		a=getch();
		if (a=='1') return;
	}
	if (a==0 || a==0xE0) a=getch();
	if (a==72) b='u';//up
	if (a==80) b='d';//down
	if (a==75) b='l';//left
	if (a==77) b='r';//right
	int l=0,kk=0;
	if (b=='u') l--;
	if (b=='d') l++;
	if (b=='r') kk++;
	if (b=='l') kk--;
	if(list[nn+l][mm+kk]!='#'){
		list [nn][mm]='1';
		if (mm+kk>=0&&mm+kk<18&&nn+l>=0&&nn+l<18) list[nn+l][mm+kk]='0';
		else  list [nn][mm]='0';
	}
	gameplay();
}
	
int main(){
	printf("chose a number between 1 and 2?\n(1=faz1,2=faz2)\n");
	int faz;
	scanf("%d",&faz);
	if(faz==1){
		open();
		for (int i = 0; i < 1000; i++)
		{
			if (list[i][0]=='\0') {
				n=i;
				break;
			}
		}
		for (int i = 0; i < 1000; i++)
		{
			if (list[0][i]=='\0') {
				m=i;
				break;
			}
		}
		setereha();
		for (int i = 0; i < t-1; i++)
		{
			struct adres key[10000];
			int nn;
			nn=rahyab(key,setare[i].i,setare[i].j,setare[i+1].i,setare[i+1].j);
			printlahzeie(key,nn,setare[i].i,setare[i].j,setare[i+1].i,setare[i+1].j);
		}
	}
	if (faz==2){
		oopen();
		gameplay();
		system("cls");
		for (int i=0;i<18;i++){
		printf("%s\n",list[i]);
	}
	}
}
