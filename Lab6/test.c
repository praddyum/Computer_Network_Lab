#include <stdio.h>
int main()
{
  int c,d,f;
  printf("I’m waiting for a character: ");
  c = getchar();
  d = getchar();
  f = getchar();
  printf("I waited for the '%c' %c %c character.n",c,d,f);
  return(0);
}