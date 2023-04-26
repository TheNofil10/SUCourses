#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    int fd[2];
    pipe(fd);
	

    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
		// child: redirect standard output to a file
        close(fd[1]);
	    dup2(fd[0], "a.txt");

		// now exec "wc"...
        char *myargs[3];
        myargs[0] = strdup("grep");	
        myargs[1] = strdup("it"); 	
	    myargs[2] = strdup("-a");
        myargs[3] = NULL;           	
        execvp(myargs[0], myargs);  	
    } else {
        // parent goes down this path (original process)
        close(fd[0]);
	
        char myStr[] = "Here it is! \n";
        write(fd[1], myStr, strlen(myStr)+1);
        close(fd[1]);
        wait(NULL);
    }
    return 0;
}