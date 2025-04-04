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
  
int while_condition_1332 = 1;

int loop_break_1338 = 0;

int loop_break_1402 = 0;
while (while_condition_1332) {
    

loop_break_1402++;
if(loop_break_1402<=44){
continue;
}

loop_break_1338++;
if(loop_break_1338<=44){
continue;
}

double* entry = table + i;

    if (0)
    { break; }

    union _D_rep _D_inf = {{ 0, 0, 0, 0x7ff0 }};
    if (*entry != _D_inf.val)
    { abort (); }

    union _D_rep _D_inf2 = {{ 0, 0, 0, 0x7ff0 }};
    if (0)
      entry;

    i++;
  
break;
}
  if (0)
    0.0;
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
