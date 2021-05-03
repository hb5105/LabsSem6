#include "mpi.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
int ierr,errclass,resultlen;
char err_buffer[MPI_MAX_ERROR_STRING];
/* code */
int rank,size,i,j,a[3][3],b[3],key,count,countsum;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
if(rank==0){
printf(" Enter values in 3x3 matrix:\n");
for(int i=0;i<3;++i){
for(int j=0;j<3;++j){
scanf("%d",&a[i][j]);
}
}
printf(" Enter ele to search:\n");
scanf("%d",&key);
}
ierr = MPI_Bcast(&key, 1, MPI_INT, 0, MPI_COMM_WORLD);
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
ierr=MPI_Scatter(a,3,MPI_INT,b,3,MPI_INT,0,MPI_COMM_WORLD);
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
for(int i=0;i<3;++i){
if(key==b[i]){
++count;
}
}
ierr=MPI_Reduce(&count,&countsum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD );
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
printf("total no of occurances of %d = %d\n",key,countsum);
}
MPI_Finalize();
return 0;
}