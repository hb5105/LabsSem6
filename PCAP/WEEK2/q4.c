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

 		MPI_Ssend(&a,1,MPI_INT,rank+1,rank,comm);
 		printf("process %d: %d sent to process %d\n",rank,a,rank+1);
 		MPI_Recv(&a,1,MPI_INT,size-1,size-1,comm,&status);
 		printf("process %d: %d recieved from process %d\n",rank,a,size-1);
 	}
 	else{
 		MPI_Recv(&a,1,MPI_INT,rank-1,rank-1,comm,&status);
 		a=a+1;
 		MPI_Ssend(&a,1,MPI_INT,(rank+1)%size,rank,comm);
 		printf("process %d: %d sent to process %d\n",rank,a,(rank+1)%size);
 		
 	}

 	MPI_Finalize();
 	return 0;
 }