#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define PRIME (1<<0);
#define SQUARE (1<<1);
#define PERFECT (1<<2);
#define MERSENNE (1<<3);
#define FIBONACCI (1<<4);

bool isPrime(int num)
{
    if (num == 2) return true;
    if (num == 1 || num % 2 == 0) return false;
    for(int i = 3; i*i <= num; i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

bool isSquare(int n){
  int res = 0;

  int i = 1;
  while(i*i < n)
    i++;

  return i*i <= n;
  
}

//https://en.wikipedia.org/wiki/Perfect_number
bool isPerfect(int n){
  if(n == 1) return false;
  int res = 0;
  int i;
  for(i = 2; i*i<n; i++){
    if(n % i == 0){
      res += i;
      res += n/i;
    }
  }
  if(i*i == n)
    res += i;

  return res == n;
}

//https://en.wikipedia.org/wiki/Mersenne_prime
//We're actually interested in Mersenne numbers, they do not necessarily
//need to be prime.
bool isMersenne(int n){
  int i = 0;
  int res = (1 << i) -1;
  while(res < n){
    i++;
    res = (1 << i) - 1;
  }

  return n == res;
}

//https://en.wikipedia.org/wiki/Fibonacci_number
bool isFibonacci(int n){
  int a = 0;
  int b = 1;
  while(b < n){
    b = a + b;
    a = b - a;
  }

  return b <= n;
}

//Returns a flag indicating the properties of a number
int number_test(int n){
	__CPROVER_assume(n> 99 && n <= 1000);
  if(n < 100){
    printf("The argument should be a positive and big (99+) integer\n");
    return -1;
  }
  

  int result = 0;

  bool prime = isPrime(n);
  bool square = isSquare(n);
  bool perfect = isPerfect(n);
  bool mersenne = isMersenne(n);
  bool fibonacci = isFibonacci(n);
  printf("%i is%s perfect\n", n, perfect ?"":" not");
  printf("%i is%s square\n", n, square ?"":" not");
  printf("%i is%s prime\n", n, prime ?"":" not");
  printf("%i is%s mersenne\n", n, mersenne ?"":" not");
  printf("%i is%s Fibonacci\n", n, fibonacci ?"":" not");

  if(prime)
    result |= PRIME;
  if(square)
    result |= SQUARE;
  if(perfect)
    result |= PERFECT;
  if(mersenne)
    result |= MERSENNE;
  if(fibonacci)
    result |= FIBONACCI;

  if(fibonacci && (prime || square || perfect || mersenne)){
    printf("An interesting fibonacci number!\n");
  }

  if(prime && (fibonacci || mersenne)){
    printf("An interesting prime number!\n");
  }

  if(prime && (square || perfect)){
    printf("This shouldn't happen...\n");
    assert(false);
  }

  return result;
}

int main(int argc, char *argv[]){
  if(argc < 2){
    printf("Need an argument\n");
    return 1;
  }
  int n = atoi(argv[1]);
  number_test(n);		
  assert(number_test(-200654992) == -1);
	assert(number_test(1607458931) == 0);
	assert(number_test(936) == 0);
	assert(number_test(937) == 1);
	assert(number_test(939) == 0);
	assert(number_test(511) == 8);
	assert(number_test(225) == 2);
	assert(number_test(233) == 17);
	assert(number_test(127) == 9);
	assert(number_test(144) == 19);
	assert(number_test(610) == 16);
	assert(number_test(496) == 4);

}
