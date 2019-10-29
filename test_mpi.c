
/*************************** HEADER FILES ***************************/
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <mpi.h>
#include "sha256.h"

/*********************** FUNCTION DEFINITIONS ***********************/
/*int sha256_test()
{

    MPI_Init(&argc, &argv);
    int rank; //Le rang du processeur
    int size; //Le nombre de processeur
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;

	BYTE text1[100];
    BYTE buf[SHA256_BLOCK_SIZE];
    SHA256_CTX ctx;
    int pass=1;
    int i;
    int max=500000;

    for(long nonce=max/size*rank; nonce<max/size*(rank+1); nonce++){
        sprintf((char*)text1,"1%ldTouraya",nonce);  
    
	    sha256_init(&ctx);
	    sha256_update(&ctx, text1, strlen(text1));
	    sha256_final(&ctx, buf);  
        
        if ((buf[0]==0x00) && (buf[1]==0x00))
        //if ((buf[0]==0x00) && (buf[1]==0x00) && (buf[2]==0x00))
        {
            printf("nonce=%ld\n", nonce);
        }
    }


	/*sha256_init(&ctx);
	sha256_update(&ctx, text2, strlen(text2));
	sha256_final(&ctx, buf);
	pass = pass && !memcmp(hash2, buf, SHA256_BLOCK_SIZE);

	sha256_init(&ctx);
	for (idx = 0; idx < 100000; ++idx)
	   sha256_update(&ctx, text3, strlen(text3));
	sha256_final(&ctx, buf);
	pass = pass && !memcmp(hash3, buf, SHA256_BLOCK_SIZE);*/

	//return(pass);
//}*/ 

int main(int argc, char ** argv)
{
    MPI_Init(&argc, &argv);
    int rank; //Le rang du processeur
    int size; //Le nombre de processeur
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;

	BYTE text1[100];
    BYTE buf[SHA256_BLOCK_SIZE];
    SHA256_CTX ctx;
    int pass=1;
    int i;
    int max=50000000;

    for(long nonce=max/size*rank; nonce<max/size*(rank+1); nonce++){
        sprintf((char*)text1,"1%ldTouraya",nonce);  
    
	    sha256_init(&ctx);
	    sha256_update(&ctx, text1, strlen(text1));
	    sha256_final(&ctx, buf);  
        
        //if ((buf[0]==0x00) && (buf[1]==0x00))
        if ((buf[0]==0x00) && (buf[1]==0x00) && (buf[2]==0x00))
        {
            printf("le processus %d a trouve comme nonce=%ld\n", rank, nonce);
        }
    }


    MPI_Finalize();


}
