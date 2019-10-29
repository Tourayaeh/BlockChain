
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

#pragma omp parallel for 
    for(long nonce=0; nonce<500000; nonce++){
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

	return(pass);
}

int main()
{
	int dummy=sha256_test();

	return(0);
}
