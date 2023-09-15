#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <openssl/md5.h>

#define MAX_FILENAME_LENGTH 256
#define MD5_DIGEST_LENGTH 16

// Function to compute the MD5 hash of a file
int computeMD5Hash(const char *filename, unsigned char *digest)
{
    FILE *file;
    MD5_CTX md5Context;
    unsigned char data[1024];
    int bytesRead;

    file = fopen(filename, "rb");
    if (file == NULL)
    {
        perror("Error opening file");
        return 0;
    }

    MD5_Init(&md5Context);

    while ((bytesRead = fread(data, 1, sizeof(data), file)) != 0)
    {
        MD5_Update(&md5Context, data, bytesRead);
    }

    MD5_Final(digest, &md5Context);
    fclose(file);

    return 1;
}

// Function to delete a file
void deleteFile(const char *filename)
{
    if (remove(filename) == 0)
    {
        printf("Deleted: %s\n", filename);
    }
    else
    {
        perror("Error deleting file");
    }
}

int main()
{
    char directory[MAX_FILENAME_LENGTH];
    printf("Enter the directory path: ");
    scanf("%s", directory);

    DIR *dir;
    struct dirent *entry;

    // Open the directory
    dir = opendir(directory);
    if (dir == NULL)
    {
        perror("Error opening directory");
        return 1;
    }

    // Create a hash table to track unique MD5 hashes
    char seenHashes[10000][MD5_DIGEST_LENGTH];
    int numHashes = 0;

    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_REG)
        { // Regular file
            char filename[MAX_FILENAME_LENGTH];
            snprintf(filename, sizeof(filename), "%s/%s", directory, entry->d_name);

            unsigned char md5Hash[MD5_DIGEST_LENGTH];
            if (computeMD5Hash(filename, md5Hash))
            {
                int isDuplicate = 0;

                // Check if the MD5 hash is already in the hash table
                for (int i = 0; i < numHashes; i++)
                {
                    if (memcmp(md5Hash, seenHashes[i], MD5_DIGEST_LENGTH) == 0)
                    {
                        isDuplicate = 1;
                        break;
                    }
                }

                if (isDuplicate)
                {
                    deleteFile(filename); // Delete the duplicate file
                }
                else
                {
                    // Add the MD5 hash to the hash table
                    memcpy(seenHashes[numHashes], md5Hash, MD5_DIGEST_LENGTH);
                    numHashes++;
                }
            }
        }
    }

    closedir(dir);
    return 0;
}
