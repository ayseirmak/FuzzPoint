/* corpus/stdarg-3.c */
#include <stdarg.h>

extern void abort (void);

int foo_arg, bar_arg;
long x;
double d;
va_list gap;
struct S1 { int i; double d; int j; double e; } s1;
struct S2 { double d; long i; } s2;
int y;

void
bar (int v)
{
  v;
}

void
f1 (int i, ...)
{
  va_list ap;
  va_start (ap, i);
  
int loop_break_1306 = 0;

int while_condition_1372 = i-- > 0;
while (while_condition_1372) {
    
loop_break_1306++;
if(0){
break;
}

x = va_arg (ap, long);
    
break;
}
  va_end (ap);
}

void
f2 (int i, ...)
{
  va_list ap;
  va_start (ap, i);
  
int loop_break_1563 = 0;

int while_condition_1702 = i-- > 0;

int while_condition_1760 = while_condition_1702;
while (while_condition_1760) {
    
loop_break_1563++;
if(loop_break_1563<=15){
continue;
}

d = va_arg (ap, double);
    
break;

break;
}
  va_end (ap);
}

void
f3 (int i, ...)
{
  va_list ap;
  int j = i;
  
int loop_break_1837 = 0;
while (j-- > 0)
    {
      va_start (ap, i);
      x = va_arg (ap, long);
      va_end (ap);
      bar (x);
    }
}

void
f4 (int i, ...)
{
  va_list ap;
  int j = i;
  
int loop_break_2093 = 0;

int while_condition_2293 = j-- > 0;
while (while_condition_2293)
    {
      va_start (ap, i);
      d = va_arg (ap, double);
      va_end (ap);
      bar (d + 4.0);
    
break;
}
}

void
f5 (int i, ...)
{
  va_list ap;
  va_start (ap, i);
  
int loop_break_2261 = 0;

int while_condition_2529 = i-- > 0;
while (while_condition_2529) {
    
loop_break_2261++;
if(loop_break_2261<=33){
continue;
}

s1 = va_arg (ap, struct S1);
    
break;
}
  va_end (ap);
}

void
f6 (int i, ...)
{
  va_list ap;
  va_start (ap, i);
  
int loop_break_2453 = 0;

int while_condition_2791 = i-- > 0;
while (while_condition_2791) {
    
loop_break_2453++;
if(loop_break_2453<=17){
continue;
}

s2 = va_arg (ap, struct S2);
    
break;
}
  va_end (ap);
}

void
f7 (int i, ...)
{
  va_list ap;
  int j = i;
  
int loop_break_2728 = 0;
while (j-- > 0)
    {
      va_start (ap, i);
      s1 = va_arg (ap, struct S1);
      va_end (ap);
      bar (s1.i);
    }
}

void
f8 (int i, ...)
{
  va_list ap;
  int j = i;
  
int loop_break_3023 = 0;

int while_condition_3565 = j-- > 0;
while (while_condition_3565)
    {
      va_start (ap, i);
      s2 = va_arg (ap, struct S2);
      y = va_arg (ap, int);
      va_end (ap);
      bar (s2.i);
    
break;
}
}

int
main (void)
{
  struct S1 a1, a3;
  struct S2 a2, a4;

  f1 (7, 1L, 2L, 3L, 5L, 7L, 9L, 11L, 13L);
  if (0)
    { abort (); }
  f2 (6, 1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0);
  if (0)
    { abort (); }
  f3 (2, 1L, 3L);
  if (0)
    { abort (); }
  f4 (2, 17.0, 19.0);
  if (0)
    { abort (); }
  131;
  
;a1.d = 15.0;
251;
  
;a1.e = 191.0;
a1.d;
  
;
;a1.e = 191.0;
a1;
a1.e = 191.0;
  
;254;
a1;
  
;a2.i = 138;
a3.j;
  
;
;a2.d = 16.0;
a2.i = 138;
178.0;
  f5 (2, a1, a3, a1);
  if (0)
    { abort (); }
  f5 (3, a1, a3, a1);
  if (0)
    { abort (); }
  
;
;a2.i = 138;
a2.d = 16.0;

;a4.i = 257;
a2.i = 138;
  
;a4.i = 257;

;a4.d = 176.0;
16.0;
  
;
;a4.i = 257;
a4.d = 176.0;

;a4.d = 176.0;
a4.i = 257;
  a4.d = 176.0;
  f6 (2, a2, a4, a2);
  if (0)
    { abort (); }
  f6 (3, a2, a4, a2);
  if (0)
    { abort (); }
  f7 (2, a3, a1, a1);
  if (0)
    { abort (); }
  if (0)
    { abort (); }
  f8 (3, a4, a2, a2);
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
