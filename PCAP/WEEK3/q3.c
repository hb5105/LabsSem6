#include<mpi.h>
#include<stdio.h>
#include<string.h>

int non_count(char* b){
	int non=0;
	for (int i = 0; i < strlen(b); ++i)
	{
		if(isalpha(b[i]))
		if (b[i]!='a'&&b[i]!='e'&&b[i]!='i'&&b[i]!='o'&&b[i]!='u'&&b[i])
		{
			non++;
		}
	}
	return non;
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
	int c[size];
	int m;
	if(rank==root){
		printf("enter a string having multiple of %d characters\n",size );
		gets(a);
		m=(strlen(a)/size);
		

	}
	MPI_Bcast(&m,1,MPI_INT,0,MPI_COMM_WORLD);
	
	MPI_Scatter(a,m,MPI_CHAR,&b,m,MPI_CHAR,0,MPI_COMM_WORLD);
	
	int nonc=non_count(b);
	printf("process %d: non-vowel alphabet count is: %d\n",rank,nonc );

	MPI_Gather(&nonc,1,MPI_INT,c,1,MPI_INT,0,MPI_COMM_WORLD);
	
	if (rank==0)
	{	int recv=0;
		for (int i = 0; i < size; ++i)
		{
			recv+=c[i];
		}
		printf("process %d: final non-vowel alphabet count is: %d\n",rank,recv );
	}

	MPI_Finalize();
	return 0;
}