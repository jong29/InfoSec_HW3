// support two modes enc, dec
// read input file and encrypt/decrypt file content
// needs to perform authenticated encryption using HMAC-SHA256
// --> this should produce a HMAC-SHA256 tag(message authentication code)
// --> for decryption, need to verify authenticity with HMAC tag
// also needs a shared.key file with the key
// plus some error handling

#include<stdio.h>
#include<string.h>
#include<openssl/ssl.h>


int main(int argc, char*argv[]){
    //initialize variables
    char *tags[4] = {"-key", "-in", "-out", "-tag"};
    char *mode = argv[1];
    int idx[4] = {0};

    for(int i=2; i<argc; i+=2){
        if (strcmp(argv[i], tags[0])==0){
            idx[0] = i+1;
        } else if (strcmp(argv[i], tags[1])==0){
            idx[1] = i+1;
        } else if (strcmp(argv[i], tags[2])==0){
            idx[2] = i+1;
        } else if (strcmp(argv[i], tags[3])==0){
            idx[3] = i+1;
        } else {
            printf("ERROR\n");
            return 2;
        }
    }

    //for each action
    if(!strcmp(mode, "enc")){
        printf("encrypt\n");


    } else if(!strcmp(mode, "dec")){
        printf("decrypt\n");
    } else {
        printf("ERROR\n");
        return 2;
    }
    return 0;
}