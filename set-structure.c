extern void abort(void);

void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {abort();} } }
extern int __VERIFIER_nondet_int();
extern void __VERIFIER_assume(int);

#define SIZE 3

// implements a set with a function to check if an element already exists in the set

int elem_exists( int set [ ] , int size , int value ) {
  int i;
  for ( i = 0 ; i < size ; i++ ) {
    if ( set[ i ] == value ) return 1;
  }
  return 0;
}

int main( ) {
  int n = 0;
  int set[ SIZE ];
  int setSize = 0; //only incremented when an element is inserted
  int x;
  int y;
  // insert elements in the array
  int v;
  for ( v = 0 ; v < SIZE ; v++ ) {
    // check if the next element to insert exists, if not insert it.
    int element = __VERIFIER_nondet_int();
    if ( !elem_exists( set , n , element ) ) {
      // parametes are passed by reference
      set[n] = element;
      n++;
      setSize++; //amount of inserted items + 1, so size increases by 1
    }
  }

  //code to verify correctness
  for(x = 0; x < setSize; x++){
  	for(y = 0; y < x; y++){
  		__VERIFIER_assert(set[x] != set[y]);
  	}
  }

  return 0;
}

