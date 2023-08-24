#include <assert.h>

int add3(int y)
{
  int x = 3;
  
  int res = y;
  int i = x;
  while(i != 0){
    res++;
    i--;
  }
  assert(res == x+y);
  return res;
}

int add(int x, int y)
{ 
	__CPROVER_assume(0 <= x && x <= 30);
  int res = y;
  int i = x;
  while(i != 0){
    res ++;
    i--;
  }
  assert(res == x+y);
  return res;
}

