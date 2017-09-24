 #include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define ff fflush(stdout);

int getKeyLoc(char ** envp, int keyLoc){
    char * Strtemp = envp[keyLoc];
        if(Strtemp[0] == 'P' && Strtemp[1] == 'A' && Strtemp[2] == 'T' &&
            Strtemp[3] == 'H' && Strtemp[4]  == '='){
//            printf("evp[i]: %s",Strtemp); ff;
            return 1;
        }
        else{
            return 0;
    }
    return -1;
}

char * appendStr(char * path, char * cmd){
    char i;
    
    for( i = 0; path[i]!='\0'; i++);
    
    for(char j = 0; cmd[j]!='\0'; j++,i++)
        path[i] = cmd[j];
    
    path[i] = '\0';
    
   // printf("Path: %s",path); ff;
    
    return path;
}
