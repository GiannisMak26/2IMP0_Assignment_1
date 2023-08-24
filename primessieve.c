#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

bool isPrime(int num)
{
     if (num <= 1) return false;
     if (num <= 2) return true;
     for(int i = 2; i < num; i++)
     {
         if (num % i == 0)
             return false;
     }
     return true;
}

void getPrimes(int limit, bool *primes) {
    int i,j;

    for (i=2;i<=limit;i++)
        primes[i]=true;

    for (i=2; i*i<=limit;i++)
        if (primes[i])
            for (j=i;i*j<=limit;j++)
                primes[i*j]=false; 
}

int main(){
  bool * primes = malloc(sizeof(bool)*101);
  getPrimes(100, primes);

  int z = 1;
  for (int i=2;i<100;i++)
    if (primes[i]){
        printf("%dth prime = %d\n",z++,i);
	assert(isPrime(i));
    } else {
	assert(!isPrime(i));
    }
  free(primes);
}
