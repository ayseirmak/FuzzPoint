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
while (while_condition_1360) {
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
