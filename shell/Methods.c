 #include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define ff fflush(stdout);


int getSize(char str []){ // returns size of string
    char *tempPtr;
    int strSize = 0;
    for (tempPtr = str; *tempPtr != '\0'; tempPtr++){
    strSize++;
    }
    return strSize;
}

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

void printStr(char tokenVec []){    
    printf("\nFinal path: %s",tokenVec); ff;
}

int getPath(char ** envp){
    int keyLoc = 0;
    while(!getKeyLoc(envp, keyLoc)){
        keyLoc++;
    }

    return keyLoc;
}

char * appendStr(char * s1, char * s2){
  int s1num = getSize(s1);
  int s2num = getSize(s2);
  int len = s1num + s2num;
  int i;
  int j;
  
  char * curr = (char *) malloc(len+1);
  
  for(i = 0; i < s1num; i ++){
      curr[i] = s1[i];
  }
  curr[i] = '/'; i++;
  
  for(j = 0; j < s2num -1; j++){
      curr[i] = s2[j];
      i++;
  }
  curr[len] = '\0';
    return curr;
}

void read_from_pipe (int file){
  FILE *stream;
  int c;
  stream = fdopen (file, "r");
  while ((c = fgetc (stream)) != EOF)
    putchar (c);
  fclose (stream);
}

void write_to_pipe (int file){
  FILE *stream;
  stream = fdopen (file, "w");
  fprintf (stream, "hello, world!\n");
  fprintf (stream, "goodbye, world!\n");
  fclose (stream);
}
