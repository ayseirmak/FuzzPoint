/* corpus/pr42691.c */
extern void abort (void);

union _D_rep
{
  unsigned short rep[4];
  double val;
};

int add(double* key, double* table)
{
  unsigned i = 0;
  double* deletedEntry = 0;
  
int while_condition_1360 = 1;

int loop_break_1329 = 0;

int loop_break_1393 = 0;

int while_condition_1461 = while_condition_1360;

int loop_break_1492 = 0;
while (while_condition_1461) {
    


loop_break_1492++;
if(loop_break_1492<=28){
continue;
}

loop_break_1393++;
if(loop_break_1393<=29){
continue;
}

loop_break_1329++;
if(loop_break_1329<=29){
continue;
}

double* entry = table + i;

    if (0)
    { break; }

    union _D_rep _D_inf = {{ 0, 0, 0, 0x7ff0 }};
    if (0)
    { abort (); }

    union _D_rep _D_inf2 = {{ 0, 0, 0, 0x7ff0 }};
    if (!_D_inf2.val)
      deletedEntry = entry;

    i++;
  
break;

break;
}
  if (0)
    *deletedEntry = 0.0;
  return 0;
}

int main ()
{
  union _D_rep infinit = {{ 0, 0, 0, 0x7ff0 }};
  double table[2] = { infinit.val, 23 };
  double key = 23;
  int ret = add (&key, table);
  return ret;
}
/* ProgramSourceLLVM */
