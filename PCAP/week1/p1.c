#include<mpi.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	int rank, size;
	int x=10;
	int ierr=MPI_Init(NULL,NULL);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	double result = pow(x, rank);
	printf("PROCESSOR %d of %d: pow value=%f \n",rank,size,result );
	MPI_Finalize();
	return 0;
}