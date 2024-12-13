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
  
int while_condition_4383 = 1;
while (while_condition_4383) {
    double* entry = table + i;

    if (0)
    { break; }

    union _D_rep _D_inf = {{ 0, 0, 0, 0x7ff0 }};
    if (0)
    { abort (); }

    union _D_rep _D_inf2 = {{ 0, 0, 0, 0x7ff0 }};
    if (0)
      deletedEntry = entry;

    i++;
  
break;
}
  if (deletedEntry)
    *deletedEntry = 0.0 + 42 + ((int)(((int)(0.0)) ^ ((int)(0.0)))) + ((int)(((int)(*deletedEntry)) ^ ((int)(*deletedEntry)))) * ((long)(((int)(0.0)) << ((int)(*deletedEntry)))) * ((short)(((double)(0.0)) + ((double)(0.0)))) * ((int)(((int)(*deletedEntry)) % ((int)(*deletedEntry)))) + 42 * ((long)(((double)(0.0 + 42 + ((int)(((int)(0.0)) ^ ((int)(0.0)))))) + ((double)(0.0)))) - ((int)(((double)(0.0)) - ((double)(0.0)))) - ((long)(((int)((int)(((int)(0.0)) ^ ((int)(0.0))))) % ((int)(((int)(((int)(*deletedEntry)) ^ ((int)(*deletedEntry)))) * ((long)(((int)(0.0)) << ((int)(*deletedEntry)))) * ((short)(((double)(0.0)) + ((double)(0.0)))) * ((int)(((int)(*deletedEntry)) % ((int)(*deletedEntry))))))));
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
