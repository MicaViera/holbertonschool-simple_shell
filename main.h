#ifndef _MAIN_H_
#define _MAIN_H_
/* Libraries for the Shell*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
/* Prototypes */
extern char **environ;

int main(void);
char **tokeneitor(char *input);
int execveitor(char *comand, char **argv);
char *patheitor(const char *fpath);
char *findex_path(const char *command, const char *path);
void enveneitor(void);
#endif
