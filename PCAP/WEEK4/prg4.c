#include "mpi.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
int ierr,errclass,resultlen;
char err_buffer[MPI_MAX_ERROR_STRING];
/* code */
int rank,size,i,j,a[4][4],b[4],c[4],count=0,countsum;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
if(rank==0){
printf(" Enter values in 4x4 matrix:\n");
for(int i=0;i<4;++i){
for(int j=0;j<4;++j){
scanf("%d",&a[i][j]);
}
}
}
ierr = MPI_Scatter(a,4,MPI_INT,b,4,MPI_INT,0,MPI_COMM_WORLD);
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
ierr=MPI_Scan(b,c,4,MPI_INT,MPI_SUM,MPI_COMM_WORLD );
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
// for(int i=0;i<4;++i){
// MPI_Scan(&b[i],&c[i],1,MPI_INT,MPI_SUM,MPI_COMM_WORLD );
// }
if(rank==0){
printf(" output 4x4 matrix:\n");
}
printf(" process %d :",rank);
for(int i=0;i<4;++i){
printf("%d ",c[i]);
}
printf("\n");
MPI_Finalize();
return 0;
}