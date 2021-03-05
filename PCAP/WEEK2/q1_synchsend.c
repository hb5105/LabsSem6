#include<mpi.h>
#include<stdio.h>
#include<string.h>
#define  comm MPI_COMM_WORLD
int main(int argc, char const *argv[])
{
	char str[10];
	MPI_Status status;
	int len;
	int rank,size;
	MPI_Init(NULL,NULL);
	MPI_Comm_rank(comm, &rank);
	MPI_Comm_size(comm,&size);
	if (size!=2)
	{
		printf("requires 2 processes \n");
		MPI_Abort(comm,911);
	}
	if (rank==0)
	{
		printf("enter a string \n");
		scanf("%s",str);
		len=strlen(str);

		MPI_Ssend(&len,1,MPI_INT,1,0,comm);
		MPI_Ssend(&str,len+1,MPI_CHAR,1,1,comm);

		MPI_Recv(&str,len+1,MPI_CHAR,1,3,comm,&status);
		printf("updated string sent by process 1 is: %s \n",str);

	}

	if (rank==1)
	{
		MPI_Recv(&len,1,MPI_INT,0,0,comm,&status);

		MPI_Recv(&str,len+1,MPI_CHAR,0,1,comm,&status);

		for (int i = 0; i < len; ++i)
		{	
			if (str[i]>='A'&&str[i]<='Z')
				{
					str[i]+=32;
					
				}
				else
					str[i]-=32;
		}
		MPI_Ssend(&str,len+1,MPI_CHAR,0,3,comm);
	}
	MPI_Finalize();
	return 0;
}