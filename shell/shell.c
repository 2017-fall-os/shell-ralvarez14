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
    
    while(!exitShell){
        write(1,"$ ",2);               // read user imput
        read(0,str,sizeof str);
        exitShell = cmpExt(str);             // check if imput is "exit" command
        
        if(exitShell == 0){            
            char ** cmdVec = myTock(str,' ');                    //tokenize
            argv = myTock(str,' '); 
            rc = fork();
            if (rc < 0) { // fork failed; exit
                fprintf(stderr, "fork failed\n");
                exit(1);
            }else if(rc == 0){
                if(argc > 1){
                    char * path = argv[1];
                    char ** thePath;
                    int wc = wait(NULL);
                    printf("hello, I am parent of %d (wc:%d) (pid:%d)\n", rc, wc, (int)getpid()); 
                    }
            }else{
     //           printf("I am child (pid: %d)\n\n",(int)getpid()); ff;
                int keyLoc = getPath(envp);
                char ** thePath = myTock2(envp[keyLoc],':');
                char ** temp = thePath;
        //        for(int i = 0; i < numTocks; i ++){
                for(;temp; temp++){
                    char * finalPath = appendStr(*temp, argv[0]);
                    execve(finalPath, argv, envp);     // runs word count 
        //        execve("/usr/bin/ls", argv, envp);
                }
                printf("this shouldn’t print out");  
                } // end of else 
        }// end of if statement
        return 0;  
    }
//    write(1,"End Of loop",11);
//    write(1,"\n",1);
}
