#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char * argv[])
{
    if(argc != 2)
    {
        printf("Error!\n");
        exit(1);
    }
    int sleeptime = atoi(argv[1]);
    if(sleep(sleeptime) != 0)
    {
        printf("Error!\n");
        exit(1);
    }
    exit(0);
}