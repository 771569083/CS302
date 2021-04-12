#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>	
#include <sys/types.h>//这里提供类型pid_t和size_t的定义
#include <sys/stat.h>
#include <fcntl.h>
#include "stdio.h"
#include "unistd.h"
#include "sys/wait.h"
int main() {
    printf("Starting main\n");
    int file_fd = open("test.txt", O_WRONLY | O_TRUNC | O_CREAT, 0666);
    dup2(file_fd, STDOUT_FILENO);
    pid_t child_pid = fork();
    if (child_pid != 0) {
        wait(NULL);
        printf("CS302 SUSTech, in parent\n");
    } else {
        printf("CS302 SUSTech, in child\n");
    } 
    printf("Ending main: %d\n", child_pid);
} 
