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

int getPS1Loc(char ** envp, int keyLoc){ // **** NEEDS MODIFICATION
    char * Strtemp = envp[keyLoc];
        if(Strtemp[0] == 'P' && Strtemp[1] == 'S' && Strtemp[2] == '1' && Strtemp[4]  == '='){
//            printf("evp[i]: %s",Strtemp); ff;
            return 1;
        }
        else{
            return 0;
    }
    return -1;
}


int getKeyLoc(char ** envp, int keyLoc){ // **** NEEDS MODIFICATION
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

int getPath(char ** envp){// **** NEEDS MODIFICATION
    int keyLoc = 0;
    while(!getKeyLoc(envp, keyLoc)){
        keyLoc++;
    }

    return keyLoc;
}

char * appendStr(char * s1, char * s2, char delim){
  int s1num = getSize(s1);
  int s2num = getSize(s2);
  int len = s1num + s2num;
  int i;
  int j;
  
  char * curr = (char *) malloc(len+2);
  
  for(i = 0; i < s1num; i++){
      curr[i] = s1[i];
  }
  curr[i] = delim; i++;
  
  for(j = 0; j < s2num ; j++){
      curr[i] = s2[j];
      i++;
  }
  curr[i] = '\0';
    return curr;
    
/*
  int i = 0;
  int len = getSize(s1);
  int len2 = getSize(s2);
  int mxLen = len + len2;
  
  char * s3 = (char *) malloc(mxLen+1);
  while(s1[i] != '\0'){
        s3[i] = s1[i];
        i++;
    }
    i = 0;
  while(s2[i] != '\0'){
        s3[len+i] = s2[i];
        i++;
    }
    s3[len+i+1] = '\0';
    return s3; */

}

int strCmp(char * string1, char * string2){
    if(string1 == NULL || string2 == NULL){
        return 0;
    }
    
    int i = 0;
    char * s1 = string1;
    char * s2 = string2;
    
    while(s1[i] != '\0' || s2[i] != '\0'){
        if(s1[i] != s2[i]){
            return 0;
        }
        s1++;
        s2++;
        i++;
    }
    return 1;
}

int getPS1(char ** envp){
    int keyLoc = 0;
   // char ** temp = envp;
    for(char ** temp = envp; *temp != 0;temp++){
       // if(strCmp(*temp,"PS1="))
        char * temp2 = *temp;
           printf("%s\n",*temp2);
     //  keyLoc++;
    }
  //  return keyLoc;
}

/************ Tokenizer Commands *********************/

int getStrSize(char str []){ // returns size of string
    char *tempPtr;
    int strSize = 0;
    for (tempPtr = str; *tempPtr != '\0'; tempPtr++){
    strSize++;
    }
    return strSize;
}

int getTokenSize(char str [], char delim){ // returns size of token
    char *tempPtr;
    int strSize = 0;
    for (tempPtr = str; *tempPtr != delim && *tempPtr != 0 && *tempPtr != 10; tempPtr++){
    strSize++;
    }
    return strSize;
}

char * trim(char * str, char delim){// Ignores space before first letter
        while(*str == delim){       // Retruns a pointer to it.
            str++;
        }
    return str;
}

int getNumWords(char str [],char delim){ // Return the number of tokens
    int flag = 1;            // the string has  
    int size = 0;
    int i = 0;                // Checks the delimiter
    
    while(str[i] != '\0'){
        if(str[i] != delim && flag == 1 && str[i] != 10){
            size++;
        }
        if(str[i] == delim && str[i-1] == delim)
            flag = 0;
        if(str[i] == delim && str[i+1] == delim)
            flag = 0;
        if(str[i] == delim)
            flag = 1;
        else{
            flag = 0;
        }
        i++;
    }
return size;
}

char * cpyToken(char * str2, int tkSize){  //returns the token
    int i = 0;
    char * token = (char *) malloc (sizeof(char)*tkSize);
    for ( i = 0; i < tkSize; i++){
            token[i] = str2[i];
    }
    token[i] = '\0'; 
    return token;
}

void printVec(char ** tokenVec, char * msg){
    for (; *tokenVec; tokenVec++){
     //   write(1,"Token: ",7);
        printf("%s: '%s'\n",msg,*tokenVec); ff;
       // printf("'"); ff;
        //write(1,*tokenVec,sizeof(char *)*2);
       // write(1,"\n",1);
    }
}

void freeMem(char ** tokenVec){ //frees tkvec more on Readme
    char ** temp = tokenVec;
    for(;*tokenVec; tokenVec++){
        write(1,"1\n",2);
        free(*tokenVec);
    }
    free(temp);
}

char * trimEq(char str []){
                               // Retruns a pointer to it.
        while(*str != '='){
            str++;
        }str++;
    return str;
}

char ** myTock2(char str0 [], char delim){
    int i;
    char * str = trimEq(str0);
    
    int numWords = getNumWords(str,delim);
    
    char ** tokenVec = (char **)calloc(numWords+1, sizeof(char *));
    
    for(i = 0; i < numWords; i++){
        char * str2 = trim(str, delim);
        int tkSize = getTokenSize(str2, delim);
        tokenVec[i] = cpyToken(str2,tkSize);
        str = str2+tkSize;
    }
    tokenVec[i] = '\0';
//    printVec(tokenVec);
//    printf("Inside myTock2");
    return tokenVec;
}

char ** myTock(char str [], char delim){
    int i;
    int numWords = getNumWords(str,delim);
    
    char ** tokenVec = (char **)calloc(numWords+1, sizeof(char *));
    for(i = 0; i < numWords; i++){
        char * str2 = trim(str, delim);
        int tkSize = getTokenSize(str2, delim);
        if(str2[tkSize-1] != 10)
            tokenVec[i] = cpyToken(str2,tkSize);
        str = str2+tkSize;
    }
    tokenVec[i] = 0;
   // printVec(tokenVec);
//    printf("Inside myTock");
    return tokenVec;
}

void execute(char ** argv, char ** envp){
    int retVal;
    int i = 0;
    int keyLoc = getPath(envp);
    char ** thePath = myTock2(envp[keyLoc],':');
    char ** temp = thePath;
    execve(argv[0], argv, envp); //** MAY NEED TO CHANGE****
    for(;thePath; thePath++){
        char * finalPath = appendStr(*thePath, argv[0],'/');
        retVal = execve(finalPath, argv, envp); // runs word count
        i++;
        if(i == 8){
            printf("ERORR: Command not found");ff;
        }
    }
}


int doPipes(char ** piping, char ** envp, int myPipe [] ){
//    printf("We piping guys!\n");ff;
    char ** argv1 = myTock(piping[0],' ');
//    printVec(argv1,"argv1");

    char ** argv2 = myTock(piping[1],' ');
//    printVec(argv2,"argv2");    
    pipe(myPipe);                  // piping?
    int rc = fork();

    if(rc == -1){
        perror("fork");ff;
        exit(1);
    }
    else if(rc == 0){              // if child
        close(1);                  // added this for piping
        close(myPipe[0]);
        dup(myPipe[1]);
        execute(argv1,envp);
    }else{
        close(0);
        close(myPipe[1]);
        dup(myPipe[0]);
        execute(argv2,envp);
    }
}
