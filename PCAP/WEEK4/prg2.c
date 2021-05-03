#include "mpi.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
int ierr,errclass,resultlen;
char err_buffer[MPI_MAX_ERROR_STRING];
/* code */
int rank,size,i;
float rect ,pi;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN); /* return info
about errors */
float x = (rank+0.5)/size;
float x2 = x*x;
rect = (4/(1+x2))*(1/(float)size);
// printf("%f\n",rect);
ierr =MPI_Reduce(&rect,&pi,1,MPI_FLOAT,MPI_SUM,0,MPI_COMM_WORLD );
if (ierr != MPI_SUCCESS) {
MPI_Error_class(ierr,&errclass);
if (errclass== MPI_ERR_RANK) {
fprintf(stderr,"Invalid rank used in MPI send call\n");
MPI_Error_string(ierr,err_buffer,&resultlen);
printf("%s\n",err_buffer);
// fprintf(stderr,err_buffer);
MPI_Abort(MPI_COMM_WORLD,ierr); /* abort*/
}
}
if(rank==0){
printf("Val of pi = %f\n",pi);
}
MPI_Finalize();
return 0;
}