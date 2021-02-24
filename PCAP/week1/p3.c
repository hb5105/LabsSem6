#include<mpi.h>
#include<stdio.h>
int main(int argc, char const *argv[])
{
	int rank, size;
	int a=7,b=10;
	

	int ierr=MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	switch(rank){
		case 0:
		printf("PROCESSOR %d of %d: A: %d B:%d \n",rank,size,a,b );
		break;
		case 1:
		printf("PROCESSOR %d of %d:ADDITION: %d \n",rank,size,a+b );
		break;
		case 2:
		printf("PROCESSOR %d of %d:SUBTRACTION: %d \n",rank,size,a-b );
		break;
		case 3:
		printf("PROCESSOR %d of %d:MULTIPLICATION: %d \n",rank,size,a*b );
		break;
		case 4:
		printf("PROCESSOR %d of %d:DIVISION: %f \n",rank,size,a/b );
		break;

	}
	
	MPI_Finalize();
	return 0;
}