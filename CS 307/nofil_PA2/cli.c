#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include<sys/stat.h>

int main(void)
{
    char const* const fileName = "command.txt";
    int fd0;
    int fd1;
    int cou = 0;
    int tokenlen = 0;
    FILE *f;
    int count = 1;  // Line counter (result)
    char c;  // To store a character read from file
  
    // Get file name from user. The file should be
    // either in current folder or complete path should be provided
    // Open the file
    f = fopen(fileName, "r");
  
    // Check if file exists
    if (f == NULL)
    {
        return 0;
    }
  
    // Extract characters from file and store in character c
    for (c = getc(f); c != EOF; c = getc(f))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;
  
    // Close the file
    fclose(f);
    printf("The file has %d lines\n ", count);
  
    
    char *dest = "a";
    char desti[100]  ;
    char *command = "";
    char *input = "";
    char *redirections = "";
    char *fname = "";
    char *file = "";
    char *option = "";
    char *redirection = "-";
    char *background = "n";
    FILE * fp;
    
    fp = fopen(fileName , "r");
    if(!fp){
        printf("\n Unable to open : %s ", fileName);
        return -1;
    }

    char line[500];

    while (fgets(line, sizeof(line), fp)) {
        const char s[2] = " ";
        char *token;
   
        /* get the first token */
        token = strtok(line, s);
   
        /* walk through other tokens */
        while( token != NULL ) {
              
                const char ch = '\n';
                char *ret;

                ret = strrchr(token, ch);
                if(ret == NULL){
                    if(command == ""){
                        command = token;
                    }
                    else if(token[0] == '-'){
                       // printf( " %s", token );
                        option = token;
                    }
                    else if(token[0] != '-' ){
                        if(token[0] != '<' && token[0] != '>'){
                            if(redirection == "-" && token[0] != '&'){
                                input = token;
                             //   printf( " %s", input );
                            }
                            else if(redirection != "-" && token[0] != '&'){
                                fname = token;
                                file = token;
                             //   printf( " %s", input );
                            }
                            else if(token[0] == '&'){
                                background = "y";
                             //   printf( " %s", input );
                            }
                        }
                        else if(token[0] == '<' || token[0] == '>'){
                            redirection = token;
                           // printf( " %s", redirection );
                        }
                    }
                    
                    //printf( " %s", token );
                }
                else{
                    tokenlen = strlen(token);
                    token[tokenlen-1] = '\0';
                    if(command == ""){
                        command = token;
                    }
                    else if(token[0] == '-'){
                       // printf( " %s", token );
                        option = token;
                    }
                    else if(token[0] != '-' ){
                        if(token[0] != '<' && token[0] != '>'){
                            if(redirection == "-" && token[0] != '&'){
                                input = token;
                             //   printf( " %s", input );
                            }
                            else if(redirection != "-" && token[0] != '&'){
                                fname = token;
                                file = token;
                             //   printf( " %s", input );
                            }
                            else if(token[0] == '&'){
                                background = "y";
                             //   printf( " %s", input );
                            }
                        }
                        else if(token[0] == '<' || token[0] == '>'){
                            redirection = token;
                           // printf( " %s", redirection );
                        }
                    }

                    printf( "----------\n");
                    printf( " Command: %s \n", command );
                    printf( " Inputs: %s \n", input );
                    printf( " Option: %s \n", option );
                    printf( " Redirection: %s \n", redirection );
                    printf( " Background: %s \n", background );
                    
                    printf( "----------\n");
                    
                    if(command != "wait"){

                    int rc = fork();
                    if (rc < 0) { // fork failed; exit
                        fprintf(stderr, "fork failed\n");
                        exit(1);
                    } 
                    else if (rc == 0) { // child (new process)
                        //printf("hello, I am child (pid:%d)\n", (int) getpid());
                        if(redirection == "-" ){
                            if(input == "" && option != ""){
                                char *myargs[3];
                                myargs[0] = strdup(command); // program: "wc" (word count)
                                //myargs[1] = strdup(input); // argument: file to count
                                myargs[1] = strdup(option);
                                myargs[2] = NULL; // marks end of array
                                execvp(myargs[0], myargs); // runs word count
                                printf("this shouldnt print out");
                            }
                            else if(input != "" && option == ""){
                                char *myargs[3];
                                myargs[0] = strdup(command); // program: "wc" (word count)
                                myargs[1] = strdup(input); // argument: file to count
                                //myargs[1] = strdup(option);
                                myargs[2] = NULL; // marks end of array
                                execvp(myargs[0], myargs); // runs word count
                                printf("this shouldnt print out");
                            }
                            else if(input == "" && option == ""){
                                char *myargs[3];
                                myargs[0] = strdup(command); // program: "wc" (word count)
                                //myargs[1] = strdup(input); // argument: file to count
                                //myargs[1] = strdup(option);
                                myargs[1] = NULL; // marks end of array
                                execvp(myargs[0], myargs); // runs word count
                                printf("this shouldnt print out");
                            }
                            else if(input != "" && option != ""){
                                char *myargs[3];
                                myargs[0] = strdup(command); // program: "wc" (word count)
                                myargs[1] = strdup(input); // argument: file to count
                                myargs[2] = strdup(option);
                                myargs[3] = NULL; // marks end of array
                                execvp(myargs[0], myargs); // runs word count
                                printf("this shouldnt print out");
                            }
                        }
                        else if (redirection != "-" ){
                            
                            if(redirection[0] == '>'){
                                
                                close(STDOUT_FILENO);
                                open(file, O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
                                
                            }
                            else if(redirection[0] == '<'){
                                //char *de = "output1.txt";
                                //fd0 = open(de, O_RDONLY);
                                //dup2(fd0, STDIN_FILENO);
                                //close(fd0);
                                close(STDIN_FILENO);
                                open(file,O_RDONLY);
                            }
                            // now exec "wc"...
                            if(input == "" && option == ""){
                                char *myargs[3];
                                myargs[0] = strdup(command); // program: "wc" (word count)
                                //myargs[1] = strdup(input); // argument: file to count
                                //myargs[1] = strdup(option);
                                myargs[1] = NULL; // marks end of array
                                execvp(myargs[0], myargs); // runs word count
                                printf("this shouldnt print out");

                            }
                            else if(input == "" && option != ""){
                                char *myargs[3];
                                myargs[0] = strdup(command); // program: "wc" (word count)
                                //myargs[1] = strdup(input); // argument: file to count
                                myargs[1] = strdup(option);
                                myargs[2] = NULL; // marks end of array
                                execvp(myargs[0], myargs); // runs word count
                                printf("this shouldnt print out");
                            }
                            else if(input != "" && option == ""){
                                char *myargs[3];
                                myargs[0] = strdup(command); // program: "wc" (word count)
                                myargs[1] = strdup(input); // argument: file to count
                                //myargs[1] = strdup(option);
                                myargs[2] = NULL; // marks end of array
                                execvp(myargs[0], myargs); // runs word count
                                printf("this shouldnt print out");
                            }
                            else if(input != "" && option != ""){
                                char *myargs[3];
                                myargs[0] = strdup(command); // program: "wc" (word count)
                                myargs[1] = strdup(input); // argument: file to count
                                myargs[2] = strdup(option);
                                myargs[3] = NULL; // marks end of array
                                execvp(myargs[0], myargs); // runs word count
                                printf("this shouldnt print out");
                            }
                        
                        }
                    
                    } 
                    else { // parent goes down this path (main) 
                        if(background == "n"){
                            int rc_wait = wait(NULL);
                            rc, rc_wait, (int) getpid();
                        }    
                        
                    }
                }    
                else{
                    while(wait(NULL)>0){
                    }

                }
                command = "";
                input = "";
                option = "";
                redirection = "-";
                background = "n";
            }
            token = strtok(NULL, s);
        }
        
    cou++;
    if(cou == count){
        printf( "----------\n");
                    printf( " Command: %s \n", command );
                    printf( " Inputs: %s \n", input );
                    printf( " Option: %s \n", option );
                    printf( " Redirection: %s \n", redirection );
                    printf( " Background: %s \n", background );
                    
         printf( "----------\n");
                    
        if(command != "wait"){

            int rc = fork();
            if (rc < 0) { // fork failed; exit
                fprintf(stderr, "fork failed\n");
                exit(1);
            } 
            else if (rc == 0) { // child (new process)
                //printf("hello, I am child (pid:%d)\n", (int) getpid());
                if(redirection == "-"){
                    if(input == "" && option != ""){
                        char *myargs[3];
                        myargs[0] = strdup(command); // program: "wc" (word count)
                        //myargs[1] = strdup(input); // argument: file to count
                        myargs[1] = strdup(option);
                        myargs[2] = NULL; // marks end of array
                        execvp(myargs[0], myargs); // runs word count
                        printf("this shouldnt print out");
                    }
                    else if(input != "" && option == ""){
                        char *myargs[3];
                        myargs[0] = strdup(command); // program: "wc" (word count)
                        myargs[1] = strdup(input); // argument: file to count
                        //myargs[1] = strdup(option);
                        myargs[2] = NULL; // marks end of array
                        execvp(myargs[0], myargs); // runs word count
                        printf("this shouldnt print out");
                    }
                    else if(input == "" && option == ""){
                        char *myargs[3];
                        myargs[0] = strdup(command); // program: "wc" (word count)
                        //myargs[1] = strdup(input); // argument: file to count
                        //myargs[1] = strdup(option);
                        myargs[1] = NULL; // marks end of array
                        execvp(myargs[0], myargs); // runs word count
                        printf("this shouldnt print out");
                    }
                    else if(input != "" && option != ""){
                        char *myargs[3];
                        myargs[0] = strdup(command); // program: "wc" (word count)
                        myargs[1] = strdup(input); // argument: file to count
                        myargs[2] = strdup(option);
                        myargs[3] = NULL; // marks end of array
                        execvp(myargs[0], myargs); // runs word count
                        printf("this shouldnt print out");
                    }
                }
                else if (redirection != "-"){            
                    if(redirection[0] == '>'){
                        close(STDOUT_FILENO);
                        open(file, O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);     
                    }
                    else if(redirection[0] == '<'){
                        //char *de = "output1.txt";
                        //fd0 = open(de, O_RDONLY);
                        //dup2(fd0, STDIN_FILENO);
                        //close(fd0);
                        close(STDIN_FILENO);
                        open(file,O_RDONLY);
                    }
                    // now exec "wc"...
                    if(input == "" && option == ""){
                        char *myargs[3];
                        myargs[0] = strdup(command); // program: "wc" (word count)
                        //myargs[1] = strdup(input); // argument: file to count
                        //myargs[1] = strdup(option);
                        myargs[1] = NULL; // marks end of array
                        execvp(myargs[0], myargs); // runs word count
                        printf("this shouldnt print out");

                    }
                    else if(input == "" && option != ""){
                        char *myargs[3];
                        myargs[0] = strdup(command); // program: "wc" (word count)
                        //myargs[1] = strdup(input); // argument: file to count
                        myargs[1] = strdup(option);
                        myargs[2] = NULL; // marks end of array
                        execvp(myargs[0], myargs); // runs word count
                        printf("this shouldnt print out");
                    }
                    else if(input != "" && option == ""){
                        char *myargs[3];
                        myargs[0] = strdup(command); // program: "wc" (word count)
                        myargs[1] = strdup(input); // argument: file to count
                        //myargs[1] = strdup(option);
                         myargs[2] = NULL; // marks end of array
                        execvp(myargs[0], myargs); // runs word count
                        printf("this shouldnt print out");
                    }
                    else if(input != "" && option != ""){
                        char *myargs[3];
                        myargs[0] = strdup(command); // program: "wc" (word count)
                        myargs[1] = strdup(input); // argument: file to count
                        myargs[2] = strdup(option);
                        myargs[3] = NULL; // marks end of array
                        execvp(myargs[0], myargs); // runs word count
                        printf("this shouldnt print out");
                    }        
                }
                    
            } 
            else { // parent goes down this path (main) 
                if(background == "n"){
                    int rc_wait = wait(NULL);
                    rc, rc_wait, (int) getpid();
                }    
                
            }
        }
        else{
            while(wait(NULL)>0){
            }
        }
    }
    }
    fclose(fp);
    return 0;
}