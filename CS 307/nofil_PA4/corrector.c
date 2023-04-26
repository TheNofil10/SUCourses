#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include<sys/stat.h>
#include<dirent.h>

int isequalsto(char token,char *str){
    if(token == 'r' && str[0] == 'f'){
      return 1;
    }
    else if(token == 's' && str[0] == 'm'){
      return 1;
    }
  return 0;
}

int isequalsto2(char token[50],char *str){
  int i = 0;
  while (i<strlen(token))
  {
    if(token[i] != str[i]){
      return 1;
    }
    i++;
  }
  return 0;
}

int main(int argc, char *argv[]){
    DIR *directory;
    struct dirent* file;
    FILE *a;
    FILE *fp,*fd;
    char ch;
    fp = fopen("database.txt", "r");
    directory = opendir("./");
    if (directory == NULL) {
      printf("Error\n");
      exit(2);
    }

    while ((file=readdir(directory)) != NULL) {
      if(strrchr(file->d_name,'.')){
        char *ext = strrchr(file->d_name,'.');
        if(strcmp(ext, ".txt") == 0){
            if(strcmp(file->d_name,"database.txt") != 0){
              
      char str[50];
      char last[50];
      char y;
      fp = fopen("database.txt", "r");
      fd = fopen(file->d_name, "r+");
      if(fp == NULL || fd == NULL){
          printf("unsuccesful");
          return 1;
          
      }
      int counter = 0;
      char line[500];
      while (fgets(line, sizeof(line), fp)) {
        const char s[2] = " ";
        char *token;
        char *gender;
        char *fname;
        char *lname;
 
        counter = 0;

        token = strtok(line, s);
        while(token != NULL){
          counter++;
          if(counter == 3){
            token[strlen(token)-1] = '\0';
            lname = token;
          }
          if(counter == 2){
            fname = token;
          }
          if(counter == 1){
            gender = token;
          }
          token = strtok(NULL, " ");
        }
        fseek(fd, 0, SEEK_END);
        int size = ftell(fd);
        int counter1 = 0;
        char line1[500];
        fseek(fd, 0, SEEK_SET);
        int word=0;
        y= fgetc(fd);
        while(y != EOF){
      
          if(y != ' ' && y != '\n'){
            str[word] = y;
            word++;
          }
          else{
            word = 0;
            
            if(isequalsto2(str,fname) == 0){
              int cu = ftell(fd);
              char first[50];
              int curr = (cu-(strlen(fname)+4));
              fseek(fd,curr, SEEK_SET);
              char k = fgetc(fd);
              if(isequalsto(k,gender) == 1){
                fseek(fd, ftell(fd)-1, SEEK_SET);
                if(k == 'r'){
                  fputs("s",fd);
                }
                else if(k == 's'){
                  fputs("r",fd);
                }
              }
              fseek(fd,cu, SEEK_SET);
              int next = ftell(fd)+3+strlen(fname);
              int i = 0;
              while (i<strlen(lname))
              {
                char b = fgetc(fd);
                last[i] = b;
                i++;
              }
              fseek(fd,cu, SEEK_SET);
              if(isequalsto2(last,lname) == 1){
                fputs(lname,fd);
              }
              fseek(fd,cu, SEEK_SET);
            }
            
            memset(str, 0, 50);
            memset(last, 0, 50);
          }
          y = fgetc(fd);     
        }
      }
    }
  }
}
}     
closedir(directory);
return 0;

}