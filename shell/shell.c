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
            //}else if (rc == 0) { // child (new process)
            //    printf("hello, I am child (pid:%d)\n", (int) getpid()); //debuging
                int keyLoc = 0;
                char *myargs[argc];
                
                char ** cmdVec = myTock(str,' ');                    //tokenize
                
                while(!getKeyLoc(envp, keyLoc)){
                    keyLoc++;
                   // printf("KeyLoc val %d",keyLoc); ff;
                }
//                printf("KeyLoc val %d",keyLoc); ff;
                char ** thePath = myTock2(envp[keyLoc],':');
                int numTocks = getNumWords(envp[keyLoc],':');
//                printVec(thePath); //.................................debugging
                char * finalPath;
                
                for(int i = 0; i < numTocks; i ++){
                    char * temp = appendStr(thePath[i], "/\0");
                    finalPath = appendStr(temp, cmdVec[0]);
                    
//                    printVec(cmdVec);
                    status = stat(finalPath, &buffer);
                    printf("Status: %d",status); ff;
//                    if(stat(finalPath, &buffer) == 0 && buffer.st_mode & S_IXOTH){
                        rc = fork();
                            if (rc < 0) { // fork failed; exit
                                fprintf(stderr, "fork failed\n");
                                exit(1);
                            }
                            cmdVec[0] = finalPath;
                        execve(finalPath, cmdVec, envp);     // runs word count 
                         printf("after executing");  ff;
//                    }
                }
                
                printf("this shouldn’t print out");  
            } 
            else {         // parent goes down this path (main)
                int wc = wait(NULL);
                printf("hello, I am parent of %d (wc:%d) (pid:%d)\n", rc, wc, (int)getpid()); 
            }
            return 0;  
            //freeMem(tokenVec,str);
        //}
    }
    write(1,"End Of loop",11);
    write(1,"\n",1);
}

 
/*
  #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h> 
  #include <string.h> 
  #include <sys/wait.h> 
   int main(int argc, char *argv[]) { 
       printf("hello world (pid:%d)\n", (int) getpid());
       int rc = fork();
       if (rc < 0) { // fork failed; exit
           fprintf(stderr, "fork failed\n");
           exit(1);
    } else if (rc == 0) { // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        char *myargs[3];
        myargs[0] = strdup("wc"); // program: "wc" (word count) 
        myargs[1] = strdup("p3.c"); // argument: file to count
        myargs[2] = NULL; // marks end of array
        execvp(myargs[0], myargs); // runs word count 
        printf("this shouldn’t print out"); 23 } else { // parent goes down this path (main)
            int wc = wait(NULL);
            printf("hello, I am parent of %d (wc:%d) (pid:%d)\n", 26 rc, wc, (int) getpid()); 27 }
            return 0; 
} 
*/
