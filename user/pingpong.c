#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char * argv[])
{
    if(argc != 1)
    {
        printf("Error!\n");
        exit(1);
    }
    int p[2];
    pipe(p);

    if(fork() == 0)
    {
        char buf[512];
        read(p[0],buf, sizeof(buf));
        printf("%d: received ping\n", getpid());
        write(p[1], "hello", sizeof("hello"));
        // close(p[1]);
    }
    else
    {
        char buf[512];
        write(p[1], "byte", sizeof("byte"));
        // close(p[1]);
        wait((int *) 0);
        read(p[0],buf, sizeof(buf));
        printf("%d: received pong\n", getpid());
    }

    exit(0);
}