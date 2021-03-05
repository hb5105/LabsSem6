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
 	int b[size];
 	char buff[100];
 	int sl=100;
 	MPI_Buffer_attach(buff,sl);
 	if (rank==root)
 	{
 		printf("\nenter an arry of length %d \n",size);
 		for (int i = 0; i < size; ++i)
 		{
 			scanf("%d",&b[i]);
 		}
 		
 		 for (int i = 1; i < size; ++i)
 		 {
 		 	a=b[i];
 		 	
 		 	MPI_Bsend(&a,1,MPI_INT,i,i,comm);

 		 }
 		 printf("process %d: Array elements sent to respective processes\n",rank);
 	}
 	else 
 		if (rank%2==0)
	 	{
	 		MPI_Recv(&a,1,MPI_INT,0,rank,comm,&status);
 			printf("process %d: %d recieved\n",rank,a);
 			int x=a*a;
 			printf("process %d: square: %d \n",rank,x);
	 	}
	 	else
	 	{
	 		MPI_Recv(&a,1,MPI_INT,0,rank,comm,&status);
 			printf("process %d: %d recieved\n",rank,a);
 			int x=a*a*a;
 			printf("process %d: cube: %d \n",rank,x);
 	}
 	MPI_Buffer_detach(&buff,&sl);
 	MPI_Finalize();
 	return 0;
 }