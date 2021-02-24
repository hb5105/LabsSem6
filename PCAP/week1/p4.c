#include<mpi.h>
#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
	char c[10];
	strcpy(c,"HeLLO");
	int rank, size;
	int ierr=MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	if(rank==0)
		printf("ORIGINAL STRING %s\n",c);
	if (c[rank]>='A'&&c[rank]<='Z')
	{
		c[rank]+=32;
		/* code */
	}
	else
		c[rank]-=32;
	printf("processor %d: STRING %s\n",rank,c );


	MPI_Finalize();
	return 0;
}