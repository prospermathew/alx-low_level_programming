#include "main.h"
#include <stdio>


  /** 
   * swap_int - swapping variables 
   * @a: pointer 1
   * @b: pointer 2
   */
   void swap_int(int *a, int *b) 
  {
     int swap;

   swap = *a;
   *a = *b;
    *b = swap;

  } 
