#include <stdio.h>

void charfunc(char a)
{
   printf("char: %c\n", a);
}

void intfunc(int a)
{
   printf("int: %d\n", a);
}

void floatfunc(float a)
{
   printf("float: %f\n", a);
}

int main() 
{
   // These are fixed values replacing the need for command-line arguments
   char char_a = 'A'; 
   int char_b_as_int = 66;
   float char_c_as_float = 67.0f;

   charfunc(char_a);
   charfunc(char_b_as_int);
   charfunc((char)char_c_as_float);

   int int_a = 68;
   int int_b = 69;
   float int_c_as_float = 70.0f;

   intfunc(int_a);
   intfunc(int_b);
   intfunc((int)int_c_as_float);

   float float_a = 71.0f;
   int float_b_as_int = 72;
   float float_c = 73.0f;

   floatfunc(float_a);
   floatfunc((float)float_b_as_int);
   floatfunc(float_c);

   // Combined printf outputs based on the defined variables
   char b = 97;
   char c = (char)97.0;
   
   printf("%d %d\n", b, c);
   
   int d = 'a';
   int e = (int)97.0;
   
   printf("%d %d\n", d, e);
   
   float f = 'a';
   float g = 97;
   
   printf("%f %f\n", f, g);

   return 0;
}