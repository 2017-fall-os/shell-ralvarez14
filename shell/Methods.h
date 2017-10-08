 
int getKeyLoc(char ** envp, int keyLoc);

char * appendStr(char * path, char * cmd);
    
char * appendCmd(char tkn, char * path);

void printStr(char * tokenVec);

void appd(char* s, char c);

int getPath(char ** envp);

void executeShell(int argc, char **argv, char ** envp);

void read_from_pipe (int file);

void write_to_pipe (int file);


int compare_info(char *array1, char *array2);
