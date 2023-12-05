#include<stdio.h>
#include<math.h>
#include<locale.h>
void main()
{
   float a, s=0;
   int i = 1;
   printf("Введите число больше 1 и меньше 3\n");
   scanf_s("%f", &a);
   if (a > 3 && a < 1) {
       printf("Ошибка!");
   }
   else {
       while (s <= a)
       {

           s = s + (1 / i);
           i++;
       }
       printf("%f\n", s);
   }
   
}