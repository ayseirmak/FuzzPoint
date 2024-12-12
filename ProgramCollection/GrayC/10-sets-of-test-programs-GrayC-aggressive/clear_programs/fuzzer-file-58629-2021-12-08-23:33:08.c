/* corpus/pr42691.c */
extern void abort (void);

union _D_rep
{
  unsigned short rep[(0xC54)];
  double val;
};

int add(double* key, double* table)
{
  unsigned i = (-1);
  double* deletedEntry = (0x4FF);
  
int while_condition_2901 = (1);
while (while_condition_2901) {
    double* entry = table + i;

    if (0)
    { break; }

    union _D_rep _D_inf = {{ (8), (0x31A6D), (32), 0x7ff0 }};
    if (0)
    { abort (); }

    union _D_rep _D_inf2 = {{ (16777216), (0xD7439), (0xF039), 0x7ff0 }};
    if (!_D_inf2.val)
      deletedEntry = entry;

    i++;
  
break;
}
  if (0)
    *deletedEntry = (3.3) + (0xFA6E) +((int)((((int)((5.7))) <<((int)(*deletedEntry)))))*((int)((((int)((7.8))) %((int)(*deletedEntry)))))-((int)((((double)((7.3))) +((double)((9.7))))));
  return (0);
}

int main ()
{
  union _D_rep infinit = {{ (8), (0x13835), (288230376151711744), 0x7ff0 }};
  double table[(66)] = { infinit.val, (0x0916) };
  double key = (22);
  int ret = add (&key, table);
  return ret;
}
/* ProgramSourceLLVM */
