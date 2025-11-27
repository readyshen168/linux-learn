#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void){
    // 以写入模式打开文件
    FILE *fp = fopen("./ppidloop.log","w");
    if(fp == NULL){
        perror("Error opening file");
        return 1;
    }
    // 无限循环输出父进程的pid到文件里
    for(;;){
        if(fprintf(fp, "the ppid is: %d\n", (int)getppid()) < 0){
            perror("Error: Failed to write to file");
            // 出错时关闭文件
            if(fclose(fp) == EOF){ // 另外一种判断错误的方式
                perror("Error: failed to close file");
                return 1;
            }
        }
        // 每次写入后立即刷新缓冲区到磁盘
        fflush(fp);
        sleep(1);
    } 
    // 关闭文件
    // 无限循环永远都不会执行到这里了
    if(fclose(fp) != 0){
        perror("Error: Failed to close file");
        return 1;
    }
    return 0;
}