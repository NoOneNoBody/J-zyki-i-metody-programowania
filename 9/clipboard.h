//Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b
#ifndef _CLIPBOARD_H_
#define _CLIPBOARD_H_

int set(const char* text);
void printToStdout(void);
int append(const char* text);
void clean(void);
int count(void);
int capacity(void);
void initialise(void);

#endif
