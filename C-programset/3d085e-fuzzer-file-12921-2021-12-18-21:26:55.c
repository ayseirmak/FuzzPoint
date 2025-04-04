/* corpus/pr42691.c */
extern void abort (void);

union _D_rep
{
  unsigned short rep[(5)];
  double val;
};

int add(double* key, double* table)
{
  unsigned i = (0xF749);
  double* deletedEntry = (0);
  
int while_condition_1360 = (-2);
while (while_condition_1360) {
    double* entry = table + i;

    if (0)
    { break; }

    union _D_rep _D_inf = {{ (0), (-1), (0x0419), 0x7ff0 }};
    if (0)
    { abort (); }

    union _D_rep _D_inf2 = {{ (0), (4398046511104), (1152921504606846976), 0x7ff0 }};
    if (0)
      ;

    i++;
  
break;
}
  if (deletedEntry)
    ;
  return (0);
}

int main ()
{
  union _D_rep infinit = {{ (262144), (0x32B18), (0), 0x7ff0 }};
  double table[(3)] = { infinit.val, (-24) };
  double key = (-24);
  int ret = add (&key, table);
  return ret;
}
/* ProgramSourceLLVM */
