/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include "lr.h"
int main()

{
   int variant;
   int add;
   printf("основное задание или дополнительное задание\n");
   printf("1 - основное\n2 - дополнительное\n");
   scanf("%d", &add);
   if (add == 2)
   {
   printf("введите число");
   scanf("%d", &variant);
   if(variant == 1){
       laba1();
   }
   if(variant == 2){
       laba2();
   }
   if(variant == 3){
       laba3();
   }
   if(variant == 4){
       laba4();
   }
   if(variant == 5){
       laba5();
   }
   if(variant == 6){
       laba6();
   }
   if(variant == 7){
       laba7();
   }
    }
    else{
        printf("введите число");
        scanf("%d", &add);
        if (add == 1){
            labadop1();
        }
        if (add == 2){
            labadop2();
        }
        if (add == 4){
            labadop4();
        }
        if (add == 5){
            labadop5();
        }
        
    }
}   
    


