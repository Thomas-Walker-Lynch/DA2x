/*

  do functions respect static scoping?

  Yes they do, but redefinition at the same scope level is not allowed.

  2020-07-10T11:51:00Z
  > gcc -g -o example_nested_functions example_nested_functions.c
  > ./example_nested_functions
  1 outer a:;
  2 outer a:;
  3 first a:;
  4 outer a:;
  5 second a:;
  6 outer a:;

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define memory_byte_n UINT64_MAX
#define address_t uint64_t
#define continue_from return
typedef void **continuation;

int main(){

  void a(uint i){
    fprintf(stderr, "%u outer a:;\n" ,i);
  }
  a(1);

  {//first
    a(2);
    void a(uint i){
      fprintf(stderr, "%u first a:;\n" ,i);
    }
    a(3);
  }

  {//second
    a(4);
    void a(uint i){
      fprintf(stderr, "%u second a:;\n" ,i);
    }
    a(5);
  }

  /* redefinition not allowed:

       example_nested_functions.c: In function ‘main’:
       example_nested_functions.c:61:8: error: redefinition of ‘a’
          61 |   void a(uint i){
             |        ^
       example_nested_functions.c:30:8: note: previous definition of ‘a’ was here
          30 |   void a(uint i){
             |        ^

  void a(uint i){
    fprintf(stderr, "%u redef a:;\n" ,i);
  }
  */

  a(6);

 end:;

}
