#include<mpi.h>
#include<stdio.h>
int main(int argc, char const *argv[])
{
	int rank, size;
	int ierr=MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	if(rank%2==0)
		printf("PROCESSOR %d of %d: HELLO \n",rank,size );
	else
		printf("PROCESSOR %d of %d: WORLD \n",rank,size );
	MPI_Finalize();
	return 0;
}