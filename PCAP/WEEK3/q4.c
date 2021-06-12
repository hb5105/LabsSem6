#include<mpi.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* mixed(char* d, char*f){
	char* xx=(char *)calloc(100,sizeof(char));
	int j=0,k=0;
	for (int i = 0; i < strlen(d)*2,j<strlen(d),k<strlen(d); ++i)
	{
		if (i%2==0)
		{
			xx[i]=d[j++];
		}
		else
			xx[i]=f[k++];
	}
	xx[2*strlen(d)]='\0';
	
	return xx;
}
int main(int argc, char const *argv[])
{
	int fact;
	int x;
	int rank;int size;
	int root=0;int flag=1;

	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	char a[100],b[100];
	char a1[100],b1[100];

	char c[100];
	int m;int n=0;
	if(rank==root){
		printf("enter 2 strings having multiple of %d characters\n",size );
		gets(a);
		gets(a1);
		m=(strlen(a)/size);
		n=2*strlen(a);
		

	}
	MPI_Bcast(&m,1,MPI_INT,0,MPI_COMM_WORLD);
	
	MPI_Scatter(a,m,MPI_CHAR,b,m,MPI_CHAR,0,MPI_COMM_WORLD);
	MPI_Scatter(a1,m,MPI_CHAR,b1,m,MPI