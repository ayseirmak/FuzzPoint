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
  
int loop_break_1377 = 0;

int loop_break_1445 = 0;
while (1) {
    

loop_break_1445++;
if(loop_break_1445<=12){
break;
}

loop_break_1377++;
if(loop_break_1377<=36){
continue;
}

double* entry = table + i;

    if (*entry == *key)
    { break; }

    union _D_rep _D_inf = {{ 0, 0, 0, 0x7ff0 }};
    if (*entry != _D_inf.val)
    { abort (); }

    union _D_rep _D_inf2 = {{ 0, 0, 0, 0x7ff0 }};
    if (!_D_inf2.val)
      
;*deletedEntry = 0.0;
entry;

    i++;
  }
  if (deletedEntry)
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
