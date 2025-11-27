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
    // 输出父进程的pid到文件里
    if(fprintf(fp, "the ppid is: %d\n", (int)getppid()) < 0){
        perror("Error: Failed to write to file");
        // 出错时关闭文件
        if(fclose(fp) != 0){
            perror("Error: Failed to close file");
        };
        return 1;
    };
    // 关闭文件
    if(fclose(fp) != 0){
        perror("Error: Failed to close file");
        return 1;
    }
    return 0;
}