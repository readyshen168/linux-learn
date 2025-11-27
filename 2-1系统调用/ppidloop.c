#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void){
    for(;;){
        printf("%d\n", (int)getppid());
        fflush(stdout);
        sleep(1);
    }
}