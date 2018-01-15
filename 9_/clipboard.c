//Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clipboard.h"

int set(const char* text);
void printToStdout(void);
int append(const char* text);
void clean(void);
int count(void);
int capacity(void);
void initialise(void);

struct TextChunk
{
  char text[5];
  int size;
  struct TextChunk *previousChunk, *nextChunk;
  int readCounter;
};
static struct TextChunk Chunks[10];

int chunkCount;
int chunkSize;

void initialise(void)
{
  chunkCount = 10;
  chunkSize = 5;
  for(int i=0;i<chunkCount;++i)
  {
    Chunks[i].text[0] = '\0';
    Chunks[i].size = 0;
    Chunks[i].readCounter = 0;
    if(i==0)
    {
      Chunks[i].previousChunk = NULL;
    }
    else
    {
      Chunks[i].previousChunk = &Chunks[i-1];
    }
    if(i==chunkCount-1)
    {
      Chunks[i].nextChunk = NULL;
    }
    else
    {
      Chunks[i].nextChunk = &Chunks[i+1];
    }
  }
}

int set(const char* text)
{
  for(int i=0;i<(int)(strlen(text));++i)
  {
    if(i>=capacity())
      break;
    Chunks[i/chunkSize].text[i%chunkSize] = text[i];
    ++Chunks[i/chunkSize].size;
  }
  return 1;
}

void printToStdout(void)
{
  struct TextChunk *currentChunk = &Chunks[0];
  while(currentChunk!=NULL&&(*currentChunk).size != 0)
  {
    ++(*currentChunk).readCounter;
    printf("%s",(*currentChunk).text);
    currentChunk = (*currentChunk).nextChunk;
  }
}

int append(const char* text)
{
  int current_size = count();
  for(int i=current_size;i<(int)(current_size+strlen(text));++i)
  {
    if(i>=capacity())
      break;
    Chunks[i/chunkSize].text[i%chunkSize] = text[i-current_size];
    ++Chunks[i/chunkSize].size;
  }
  return 1;
}

void clean(void)
{
  for(int i=0;i<chunkCount;++i)
  {
    Chunks[i].text[0] = '\0';
    Chunks[i].size = 0;
    Chunks[i].readCounter = 0;
  }
}

int count(void)
{
  int current_size = 0;
  struct TextChunk *currentChunk = &Chunks[0];
  while(currentChunk!=NULL&&(*currentChunk).size != 0)
  {
    current_size += (*currentChunk).size;
    currentChunk = (*currentChunk).nextChunk;
  }
  return current_size;
}

int capacity(void)
{
  return (chunkSize*chunkCount);
}
