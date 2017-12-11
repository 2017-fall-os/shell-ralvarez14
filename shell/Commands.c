#include "Methods.h"
#include "Commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 

#include <time.h>
#include <sys/wait.h> 

#define ff fflush(stdout);
 
 //time_t t = time(NULL);
 //struct tm tm = *localtime(&t);
 
void displayInterface(){
    printf("Hello Ricardo!\n");ff;
   // printf("the date is: %d/%d/%d       and the time is: %d:%d:%d\n",tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    sleep(3);
    printf("What do you want to do?\n");ff;
//    printf("a) runWinISO        b) instGCC\n");ff;
//    printf("c) instJava         d) commingSoon\n");ff;
    printf("---------------------------------\n");ff;
}
