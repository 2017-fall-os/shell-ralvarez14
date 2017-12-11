//#include "tokenizer.h"
#include "Methods.h"
#include "Commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <sys/wait.h> 

#define ff fflush(stdout);
char ** argv;
int argc;
int main(int argc, char **argv, char ** envp){
   // setenv("PS1","Input Command :",0);
    char * PS1 = getenv("PS1");
    int exitShell = 0;
    char userImput [1024];
    char ** piping;
    struct stat;
    int amountRead;
    int status;
    int rc;
    pid_t childpid;                         //pid
    int myPipe[2];                          //pipe array
    
       
    while(!exitShell){
         if(getenv("PS1")){
            char * PS1 = getenv("PS1");
            int PS1Length = getStrSize(PS1);
            write(1,getenv("PS1"),PS1Length);
        }else{
            //setenv("PS1","$ ",0);
            //write(1,getenv("PS1"),2);
            write(1,"$ ",2);
        }
        amountRead = read(0,userImput,sizeof userImput); //read user imput
        if(amountRead == 0){
            printf("\n");ff;
            exitShell = 1;
            continue;
        }
        userImput[amountRead] = '\0';      
        argv = myTock(userImput,' ');      // tokenize, so we can look for exit cmd
        
        piping = myTock(userImput,'|');    //Tokenize pipes
        exitShell = strCmp(argv[0],"exit");//check if imput is "exit" command
        
        if(exitShell == 0){ 
            if(piping[0] && piping[1]){      // is piping!
                int rc = fork();
                if(rc == 0){
                    int retVal = doPipes(piping,envp,myPipe);
                }
                else{
                    wait(NULL);
                }
            }else{                            //iF NOT PIPING
            piping = myTock(userImput,' '); //Tokenize commands parameters
            argv = myTock(userImput,' ');   //Tokenize commands parameters
            if(strCmp(argv[0], "cd")){      //If command is cd
                int ret = chdir(argv[1]);   //int ret = cd(argv);
                if(ret<0){
                    perror("ERROR");ff;
                }
            continue;
            }
            
            rc = fork();
            if(rc == -1){
                perror("FORK");ff;
                exit(1);
            }
            else if(rc == 0){/*******************If     child****************/
                execute(argv, envp);   
            }else{/******************************if parent***************/
                if(argc > 0){
                    char * path = argv[1];
                    char ** thePath;;
                    for(int i = 0; i < 1024; i ++)
                        userImput[i] = '\0';
                   // int wc = wait(NULL);
                }
            }// end of else
          }// if no piping
        }// end of if exit 0
    }
    return 0;
}
