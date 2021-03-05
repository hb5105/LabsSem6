#include<mpi.h>
#include<stdio.h>
int main(int argc, char const *argv[])
{
	int rank, size;
	int ierr=MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	printf("PROCESSOR %d of %d: HELLO WORLD\n",rank,size );
	MPI_Finalize();
	return 0;
}