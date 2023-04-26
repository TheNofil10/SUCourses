#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
    
    printf("Im SHELL process, with PID:%d - Main command is: <man touch  | grep -e '-a' -m 1>\n", (int) getpid());

    int fd[2];
   
    //--------Pipe Error------------
    if (pipe(fd)<0 ){
        perror("Pipe Error");
        exit(1);
    }
    //--------Child Process 1----------
    pid_t cpid1;
    cpid1 = fork();
    if ( cpid1 < 0 ){
        perror("Fork Error");
        exit(1);
    }

    else if (cpid1==0)
    {
        printf("Im MAN process, with PID:%d - Main command is: <touch> \n", (int) getpid());

        dup2(fd[1],STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);

        char * args[3];
        args[0]="man";
        args[1]="touch";
        args[2]=NULL;
        
        execvp(args[0],args);
    }
    
    //--------Child Process 2---------
    pid_t cpid2;
    cpid2 = fork();
    
    if (cpid2 < 0){
        perror("Fork Erorr");
        exit(1);
    }
    else if (cpid2==0)
    {
        printf("Im GREP process, with PID:%d - Main command is: <'-a'> \n", (int) getpid());

        dup2(fd[0],STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);

        int file = open("output.txt",O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
        if (file<0)
            return 2;
        
        int final = dup2(file,STDOUT_FILENO);
        close(file);
        
        char * args[6];
        args[0]="grep";
        args[1]="-e";
        args[2]="-a";
        args[3]="-m";
        args[4]="1";
        args[5]=NULL;

        execvp(args[0],args);
    }
    close(fd[0]);
    close(fd[1]);
    
    waitpid(cpid1,NULL,0);
    waitpid(cpid2,NULL,0);
    printf("Im SHELL process, with PID:%d - execution is completed, you can find the results in output.txt \n", (int) getpid());

    return 0;
}
