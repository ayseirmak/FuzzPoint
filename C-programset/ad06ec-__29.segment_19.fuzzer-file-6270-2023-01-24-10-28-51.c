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

int loop_break_1641 = 0;

int loop_break_2018 = 0;

int while_condition_7854 = while_condition_1360;
while (while_condition_7854) {
    

loop_break_2018++;
if(0){
break;
}

loop_break_1641++;
if(0){
break;
}

double* entry = table + i;

    if (0)
    { break; }

    union _D_rep _D_inf = {{ 0, 0, 0, 0x7ff0 }};
    if (0)
    { abort (); }

    union _D_rep _D_inf2 = {{ 0, 0, 0, 0x7ff0 }};
    if (0)
      entry;

    i++;
  
break;

break;
}
  if (0)
    0.0 + 42 + ((long)((((int)(0.0)) % ((int)(*deletedEntry))))) + ((short)((((int)(0.0)) & ((int)(0.0))))) + 42 - ((long)((((int)(0.0 + 42 + ((long)((((int)(0.0)) % ((int)(*deletedEntry))))))) | ((int)(0.0 + 42 + ((long)((((int)(0.0)) % ((int)(*deletedEntry)))))))))) * ((long)((((int)(0.0 + 42 + ((long)((((int)(0.0)) % ((int)(*deletedEntry))))) + ((short)((((int)(0.0)) & ((int)(0.0))))))) | ((int)(0.0))))) - ((long)((((int)(0.0 + 42 + ((long)((((int)(0.0)) % ((int)(*deletedEntry))))) + ((short)((((int)(0.0)) & ((int)(0.0))))))) % ((int)(0.0 + 42)))));
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
