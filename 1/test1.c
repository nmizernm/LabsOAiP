#include<stdio.h>

int main()
{
int S, a, b;
printf("enter S=\n");
scanf("%i", &S);
if (S<8) {
    printf("warning");
}

else 
  {
  int a=0, b=0;
  for ( ; ;a++)
  {
    for ( ; ;b++)
     {
         if (S < 3*a + 5*b) break;
         if (S == 3*a + 5*b){printf("(%i,%i)", a, b);}
         if (S > 3*a + 5*b) continue;
     }
       }
   for (a=0; ; b++)
       {
       for (b=0; ; a++)
           {
           if ( S < 3*a + 5*b) break;
           if (S == 3*a + 5*b){printf("(%i,%i)", a, b);}
           if (S > 3*a + 5*b) continue;
           }
       }    
  }
 return 0;
}

       
    
