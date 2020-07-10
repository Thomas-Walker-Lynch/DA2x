/*

   do labels respect static scoping?

   on top of speghetti .. all covered with cheese ...

   2020-07-10T11:38:28Z
   > gcc -g -o example_nested_labeling example_nested_labeling.c
   example_nested_labeling.c: In function ‘main’:
   example_nested_labeling.c:29:3: error: duplicate label ‘a’
      29 |   a:;
         |   ^
   example_nested_labeling.c:23:2: note: previous definition of ‘a’ was here
      23 |  a:;
         |  ^
   example_nested_labeling.c:36:3: error: duplicate label ‘a’
      36 |   a:;
         |   ^
   example_nested_labeling.c:23:2: note: previous definition of ‘a’ was here
      23 |  a:;
         |  ^

   .. Braces do not introduce a new context for labels, as they would for other
   declarations.  Hence, the manual namespacing you see in TM2xHd.h

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define memory_byte_n UINT64_MAX
#define address_t uint64_t
#define continue_from return
typedef void **continuation;

int main(){

 a:;
  fprintf(stderr, "outer a:;\n");

  {//first
    goto a;
      goto end;
  a:;
    fprintf(stderr, "first a:;\n");
  }

  {//second
    goto a;
      goto end;
  a:;
    fprintf(stderr, "second a:;\n");
    goto b;
  }
  goto end;

 b:;
  fprintf(stderr, "outer b:;\n");

 end:;

}