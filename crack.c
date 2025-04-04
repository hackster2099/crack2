#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

const int PASS_LEN = 20;        // Maximum any password will be
const int HASH_LEN = 33;        // Length of MD5 hash strings
int counter;
char hashAlz [33];
int stats = 1;

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

                printf("%s  %s", hashAlz, textHash);
                break;

            }


        }


    }
    // Attempt to match the hash from the file to the
    // hash of the plaintext.

    // If there is a match, you'll return the hash.
    // If not, return NULL.

    free(textHash);
    fclose(hashFile);

    return NULL;

}


int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        fprintf(stderr, "Usage: %s hash_file dict_file\n", argv[0]);
        exit(1);
    }

    // These two lines exist for testing. When you have
    // tryWord working, it should display the hash for "hello",
    // which is 5d41402abc4b2a76b9719d911017c592.
    // Then you can remove these two lines and complete the rest
    // of the main function below.
    char *found = tryWord("hello", "hashes00.txt");
    printf("%s %s\n", found, "hello");


    // Open the dictionary file for reading.
    

    // For each dictionary word, pass it to tryWord, which
    // will attempt to match it against the hashes in the hash_file.
    
    // If we got a match, display the hash and the word. For example:
    //   5d41402abc4b2a76b9719d911017c592 hello
    
    // Close the dictionary file.

    // Display the number of hashes that were cracked.
    
    // Free up any malloc'd memory?
}

