
/*************************** HEADER FILES ***************************/
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include "sha256.h"

/*********************** FUNCTION DEFINITIONS ***********************/
int sha256_test()
{
	BYTE text1[] = {"Touradj"};
    BYTE buf[SHA256_BLOCK_SIZE];
	SHA256_CTX ctx;
	int pass = 1;
	int i;

	sha256_init(&ctx);
	sha256_update(&ctx, text1, strlen(text1));
	sha256_final(&ctx, buf);

    for(i=0; i<SHA256_BLOCK_SIZE; i++){
        printf("%x ", buf[i]);
    }
    printf("\n");
    
	return(pass);
}

int main()
{
	int dummy=sha256_test();

	return(0);
}
