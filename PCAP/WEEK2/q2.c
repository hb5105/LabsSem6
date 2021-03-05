#include<mpi.h>
#include<stdio.h>
#include<string.h>
#define  comm MPI_COMM_WORLD
 int main(int argc, char const *argv[])
 {
 	int root=0;
 	int a;
 	int rank,size;
 	MPI_Init(NULL, NULL);
 	MPI_Status status;
 	MPI_Comm_rank(comm,&rank);
 	MPI_Comm_size(comm,&size);

 	if (rank==root)
 	{
 		printf("enter a number\n");
 		scanf("%d",&a);
 		 for (int i = 1; i < size; ++i)
 		 {
 		 	MPI_Send(&a,1,MPI_INT,i,i,comm);
 		 }
 		 printf("process %d: %d sent to all other processes\n",rank,a);
 	}
 	else{
 		MPI_Recv(&a,1,MPI_INT,0,rank,comm,&status);
 		printf("process %d: %d\n",rank,a);
 	}

 	MPI_Finalize();
 	return 0;
 }