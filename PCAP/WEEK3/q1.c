#include<mpi.h>
#include<stdio.h>
#include<string.h>

int facto(int c){
	int t=1;int flag=1;
	for (int i = 1; i <=c; ++i)
	{
		t*=i;
	}
	return t;
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
	int a[size],b[size];
	if(rank==root){
		printf("enter %d no of elemnts\n",size );
		for (int i = 0; i < size; ++i)		
		{
			scanf("%d",&a[i]);
		}

	}
	MPI_Scatter(a,1,MPI_INT,&x,1,MPI_INT,0,MPI_COMM_WORLD);
	
	fact=facto(x);
	printf("process %d: factorial of %d: %d\n",rank,x,fact );

	MPI_Gather(&fact,1,MPI_INT,b,1,MPI_INT,0,MPI_COMM_WORLD);
	
	if (rank==0)
	{	int recv=0;
		for (int i = 0; i < size; ++i)
		{
			recv+=b[i];
		}
		printf("process 0: sum of factorials:%d\n",recv );
	}

	MPI_Finalize();
	return 0;
}