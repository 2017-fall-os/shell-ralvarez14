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
    struct stat buffer;
    int status;
    int rc;
    
    pid_t pid;                         // pid
    int myPipe[2];                     // pipe array
    
    while(!exitShell){
        
        write(1,"$ ",2);               // read user imput
        read(0,str,sizeof str);
        exitShell = cmpExt(str);       // check if imput is "exit" command
        if(exitShell == 0){ 
            
            if(pipe (myPipe)){                          // piping?
                printf("Pipe failed!\n");
                return EXIT_FAILURE;
            }
            
            argv = myTock(str,' '); 
            rc = fork();
            if (rc < 0) { // fork failed; exit
                fprintf(stderr, "fork failed\n");
                exit(2);
            }else if(rc == 0){
                close(myPipe[1]);                       // added this for piping
                read_from_pipe(myPipe[0]);
                
                int keyLoc = getPath(envp);
                char ** thePath = myTock2(envp[keyLoc],':');
                char ** temp = thePath;
                for(;temp; temp++){
                    char * finalPath = appendStr(*temp, argv[0]);
                    execve(finalPath, argv, envp); // runs word count 
                }
                printf("this shouldn’t print out");  
            }else{
                if(argc > 0){
                    close(myPipe[0]);                   // Added this for piping
                    write_to_pipe(myPipe[0]);
                    
                    char * path = argv[1];
                    char ** thePath;
//                    freeMem(argv);
                    for(int i = 0; i < 1024; i ++)
                        str[i] = '\0';
                    int wc = wait(NULL);
                }
            } // end of else 
        }// end of if statement
    }
    return 0;
}
