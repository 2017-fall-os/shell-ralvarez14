 
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define ff fflush(stdout);

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
    for (tempPtr = str; *tempPtr != delim; tempPtr++){
    strSize++;
    }
    return strSize;
}

char * trim(char * str, char delim){   // Ignores space before first letter
                           // Retruns a pointer to it.
        while(*str == delim){
            str++;
        }
    return str;
}

int getNumWords(char str [],char delim){ // Return the number of tokens
    int flag = 1;            // the string has  
    int size = 0;
    int i = 0;                // Checks the delimiter
    
    while(str[i] != '\0'){
        if(str[i] != delim && flag == 1){
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

//    for (; *tempPtr; tempPtr++){
//        char * str2 = trim(str);
//        int tknSize = getTokenSize(str2);
//        str = str2 + tknSize;
//        size ++;
//    }
//    return size;
}

int cmpExt(char str []){  // return 1 if token is "exit"
    if(str[0] == 'e' && str[1] == 'x' && 
        str[2] == 'i' && str[3] == 't')
        return 1;
    else{
        return 0;
    }
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

void printVec(char ** tokenVec){
    for (; *tokenVec; tokenVec++){
        write(1,"Token: ",7);
        printf(*tokenVec); ff;
        //write(1,*tokenVec,sizeof(char *)*2);
        write(1,"\n",1);
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
        tokenVec[i] = cpyToken(str2,tkSize);
        str = str2+tkSize;
    }
    tokenVec[i] = '\0';  
//    printf("Inside myTock");
    return tokenVec;
}
