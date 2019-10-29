
/*************************** HEADER FILES ***************************/
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include "sha256.h"

/*********************** FUNCTION DEFINITIONS ***********************/
int sha256_test()
{
	BYTE text1[100];
    BYTE buf[SHA256_BLOCK_SIZE];
    SHA256_CTX ctx;
    int pass=1;
    int i;

    long nonce=0;

    while(1){
        sprintf((char*)text1,"1%ldTouraya",nonce);  
    
	    sha256_init(&ctx);
	    sha256_update(&ctx, text1, strlen(text1));
	    sha256_final(&ctx, buf);  
        
        if ((buf[0]==0x00) && (buf[1]==0x00))
        {
            printf("nonce=%ld\n", nonce);
            break;
        }
        nonce++;
    }

	return(pass);
}

int main()
{
	int dummy=sha256_test();

	return(0);
}
