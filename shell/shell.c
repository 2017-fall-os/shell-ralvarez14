#include "tokenizer.h"
#include "Methods.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <string.h> 
#include <sys/wait.h> 

#define ff fflush(stdout);
int main(int argc, char **argv, char ** envp){
    int exitShell = 0;
    char str [1024];
    struct stat;
    int amuRead;
    int status;
    int rc;
    
//    pid_t childpid;                         // pid
//    int myPipe[2];                     // pipe array
    
    while(!exitShell){
        
        write(1,"$ ",2);           // read user imput
        amuRead = read(0,str,sizeof str);
        str[amuRead] = '\0';
        
        exitShell = cmpExt(str);   // check if imput is "exit" command
        if(exitShell == 0){ 
            argv = myTock(str,' '); 
         //   pipe(myPipe);          // piping?
            
            if(compare_info(argv[0], "cd")){
                int deleter= getSize(argv[1]);
                argv[1][deleter-1] = '\0';
                printf("Inside if cd\n argv[1]: %s",argv[1]);
                int ret = chdir(argv[1]);
                continue;
            }
            rc = fork();
            
            if(rc == -1){
                perror("fork");
                exit(1);
            }
            else if(rc == 0){
  //              close(myPipe[0]);         // added this for piping

                int keyLoc = getPath(envp);
                char ** thePath = myTock2(envp[keyLoc],':');
                char ** temp = thePath;
                for(;temp; temp++){
                    char * finalPath = appendStr(*temp, argv[0]);
                    execve(finalPath, argv, envp); // runs word count 
                }
                printf("this shouldn’t print out");  
                
            }else{  // if parent
                if(argc > 0){
              //      close(myPipe[1]);        // Added this for piping
                    char * path = argv[1];
                    char ** thePath;;
                    for(int i = 0; i < 1024; i ++)
                        str[i] = '\0';
                    int wc = wait(NULL);
                }
            } // end of else 
        }// end of if statement
    }
    return 0;
}
