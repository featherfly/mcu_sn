
#include "arrays.h"

int array_copy(const char source[], char target[], unsigned int size)
{
  return array_copy((byte*) source, (byte*) target, size);
}

int array_copy(const byte source[], byte target[], unsigned int size)
{  
  int index;
  for(index = 0; index < size; index++) 
  {
    target[index] = source[index];
  } 
  return index;
}

int array_copy(const byte source[], byte target[], unsigned int start, unsigned int size)
{
  int index;
  for(index = start; index < size + start; index++) 
  {
    target[index - start] = source[index];
  } 
  return index;
}

bool array_equals(const byte source[], const char target[], unsigned int size)
{
  bool eq = true;
  for (int i = 0; i < size; i++)
  {
    if (source[i] != target[i]) {
      return false;
    }
  }
  return true;
}
bool array_equals(const char source[], const char target[], unsigned int size)
{
  bool eq = true;
  for (int i = 0; i < size; i++)
  {
    if (source[i] != target[i]) {
      return false;
    }
  }
  return true;
}

int array_set(char target[], const char source[], unsigned int start, unsigned int len)
{
  int index;
  for(index = 0; index < len; index++) 
  {
    target[start + index] = source[index];
  }
  return index;
}