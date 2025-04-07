#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

const int PASS_LEN = 20;        // Maximum any password will be
const int HASH_LEN = 33;        // Length of MD5 hash strings
int counter;
char hashAlz [33];
int stats = 1;


char word [20];

// Given a target plaintext word, use it to try to find
// a matching hash in the hashFile.
// Get this function working first!
char * tryWord(char * plaintext, char * hashFilename)
{
    // Hash the plaintext
    char *textHash = md5(plaintext, strlen(plaintext));

    // Open the hash file
    FILE *hashFile = fopen(hashFilename, "r");

    if(hashFile == NULL){

        printf("Could not open the File");
        exit(1);

    }

    // Loop through the hash file, one line at a time.
    while(!feof(hashFile) ){

        if(fgets(hashAlz, 33, hashFile) != NULL){

            char *nl = strchr(hashAlz, '\n'); 
            if (nl) {

                *nl = '\0';

            }

            stats = strcmp(textHash, hashAlz);

            if(stats == 0){

                printf("%s  %s\n", hashAlz, plaintext);

            }

            else{

                return 0;

            }

        }


    }

    free(textHash);
    fclose(hashFile);
    return 0;

}


int main(int argc, char *argv[]){

    if (argc < 3) 
    {
        fprintf(stderr, "Usage: %s hash_file dict_file\n", argv[0]);
        exit(1);
    }

    // Open the dictionary file for reading.
    FILE *dictionF = fopen(argv[2], "r");

    // For each dictionary word, pass it to tryWord, which
    // will attempt to match it against the hashes in the hash_file.
    while(!feof(dictionF)){

        if(fgets(word, 20, dictionF) != NULL){

            char *nl = strchr(word, '\n'); 
            if (nl) {

                *nl = '\0';

            }

            tryWord(word, argv[1]);

        }

    }

    fclose(dictionF);


}
