/*

Compile with:
aarch64-linux-gnu-gcc -fno-stack-protector -z execstack vuln.c -o vuln64
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[] )
{
    char id[32];
    char passwd[32];
    FILE* stream;

    if (argc != 2)
    {
        printf("Wrong number of arguments = %d - should be 1!\n", argc-1);
        return -1;
    }

    stream = fopen(argv[1], "r");

    fscanf(stream, "%s", id);
    printf("Login ID : %s\n", id);
    fscanf(stream, "%s", passwd); 
    printf("Password : %s\n", passwd);

    if(strcmp(id, "root") ==0)
    {
        if(strcmp(passwd, "1qazxsw2") == 0)
        {
            printf("Access Granted.\n");
            return 0;
        }
    }

    printf("Access Denied.\n");
    return 1;
}
