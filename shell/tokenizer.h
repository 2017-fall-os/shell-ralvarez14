 
#define del1 ' '
#define del2 :
#define del3 /
#define delimis (' ' || ':'  || '/')

char ** myTock(char str [],char delim);

char ** myTock2(char str [],char delim);

void freeMem(char ** tokenVec);

int cmpExt(char str []);


int getNumWords(char str [], char delim);

void printVec(char ** tokenVec);
