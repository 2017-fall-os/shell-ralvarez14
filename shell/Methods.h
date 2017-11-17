
int strCmp(char * string1, char * string2);

void execute(char ** argv, char ** envp);

int getPS1(char ** envp);

int getKeyLoc(char ** envp, int keyLoc);

char * appendStr(char * path, char * cmd, char delim);

void printStr(char * tokenVec);

int getPath(char ** envp);

int getSize(char str []);

int isPiping(char str []);

int isDelim(char str [], char delim);

int doPipes(char ** argv,char ** envp, int myPipe []);

/***********Tokenizer Commands********************/

int getStrSize(char str []);

int getTokenSize(char str [], char delim);

char * trim(char * str, char delim);

int getNumWords(char str [],char delim);

char * cpyToken(char * str2, int tkSize);

void printVec(char ** tokenVec,char * msg);

void freeMem(char ** tokenVec);

char * trimEq(char str []);

char ** myTock2(char str0 [], char delim);

char ** myTock(char str [], char delim);
