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
  
int loop_break_10534 = 0;
while (1) {
    
loop_break_10534++;
if(loop_break_10534<=47){
break;
}

double* entry = table + i;

    if (0)
    { break; }

    union _D_rep _D_inf = {{ 0, 0, 0, 0x7ff0 }};
    if (((int)((int)*entry != _D_inf.val + 42 *((short)((((int)(*entry)) |((int)(_D_inf.val)))))+((long)((((int)(_D_inf.val)) ^((int)(*entry)))))) + 42 -((short)((((int)(((long)((((int)(_D_inf.val)) ^((int)(*entry))))))) |((int)(_D_inf.val + 42 *((short)((((int)(*entry)) |((int)(_D_inf.val))))))))))-((int)((((int)(((long)((((int)(_D_inf.val)) ^((int)(*entry))))))) <<((int)(_D_inf.val + 42 *((short)((((int)(*entry)) |((int)(_D_inf.val)))))+((long)((((int)(_D_inf.val)) ^((int)(*entry))))))))))-((long)((((int)(42 *((short)((((int)(*entry)) |((int)(_D_inf.val))))))) &((int)(_D_inf.val + 42 *((short)((((int)(*entry)) |((int)(_D_inf.val))))))))))*((long)((((int)(_D_inf.val + 42 *((short)((((int)(*entry)) |((int)(_D_inf.val))))))) |((int)(_D_inf.val + 42 *((short)((((int)(*entry)) |((int)(_D_inf.val)))))+((long)((((int)(_D_inf.val)) ^((int)(*entry))))))))))))
    { abort (); }

    union _D_rep _D_inf2 = {{ 0, 0, 0, 0x7ff0 }};
    if (0)
      deletedEntry = entry;

    i++;
  }
  if (0)
    *deletedEntry = 0.0 + 42 +((long)((((int)(*deletedEntry)) %((int)(0.0)))))*((int)((((int)(0.0)) >>((int)(*deletedEntry)))))-((int)((((int)(*deletedEntry)) |((int)(0.0))))) + 42 *((int)((((int)(*deletedEntry)) >>((int)(*deletedEntry)))))+((int)((((int)(0.0 + 42 +((long)((((int)(*deletedEntry)) %((int)(0.0)))))*((int)((((int)(0.0)) >>((int)(*deletedEntry)))))-((int)((((int)(*deletedEntry)) |((int)(0.0))))))) ^((int)(42)))))*((short)((((int)(0.0 + 42 +((long)((((int)(*deletedEntry)) %((int)(0.0)))))*((int)((((int)(0.0)) >>((int)(*deletedEntry)))))-((int)((((int)(*deletedEntry)) |((int)(0.0))))))) <<((int)(0.0 + 42 +((long)((((int)(*deletedEntry)) %((int)(0.0)))))*((int)((((int)(0.0)) >>((int)(*deletedEntry))))))))))-((long)((((int)(0.0 + 42 +((long)((((int)(*deletedEntry)) %((int)(0.0)))))*((int)((((int)(0.0)) >>((int)(*deletedEntry)))))-((int)((((int)(*deletedEntry)) |((int)(0.0))))))) %((int)(0.0 + 42)))))+((int)((((int)(0.0 + 42 +((long)((((int)(*deletedEntry)) %((int)(0.0)))))*((int)((((int)(0.0)) >>((int)(*deletedEntry))))))) >>((int)(0.0 + 42 +((long)((((int)(*deletedEntry)) %((int)(0.0)))))*((int)((((int)(0.0)) >>((int)(*deletedEntry))))))))));
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
