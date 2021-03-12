#include<mpi.h>
#include<stdio.h>
#include<string.h>

double avrg(int* b,int m){
	double sum=0,avv;
	for (int i = 0; i < m; ++i)
	{
		sum+=b[i];
	}
	avv=sum/m;
	return avv;
}
int main(int argc, char const *argv[])
{
	int rank;int size;
	int root=0;int flag=1;

	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);\
	int n=size;
	int m;
	int *a;
	double avr[n];
	if (rank==root)
	{
		printf("enter the value of m\n");
		scanf("%d",&m);
		a=malloc(m*n*(sizeof(int)));
		printf("enter %d elements\n",n*m);
		for (int i = 0; i < n*m; ++i)
		{
			scanf("%d",&a[i]);
		}
		
	}

	MPI_Bcast(&m,1,MPI_INT,0,MPI_COMM_WORLD);
	int *b;
	b=malloc(m*sizeof(int));

	MPI_Scatter(a,m,MPI_INT,b,m,MPI_INT,0,MPI_COMM_WORLD);
	double avg=avrg(b,m);
	printf("process %d: average of my m nos is: %f\n",rank,avg);

	MPI_Gather(&avg,1,MPI_DOUBLE,avr,1,MPI_DOUBLE,0,MPI_COMM_WORLD);
	if (rank==0)
	{double sum=0;
		for (int i = 0; i < n; ++i)
		{
			sum+=avr[i];

		}
		double avg1=((sum)/n);
		printf("process 0: average of all nos is: %f\n",avg1);
	}

	MPI_Finalize();
	return 0;
}