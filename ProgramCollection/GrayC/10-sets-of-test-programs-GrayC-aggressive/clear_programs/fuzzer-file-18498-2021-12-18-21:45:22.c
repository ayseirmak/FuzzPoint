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
  
int loop_break_12032 = 0;
while (1) {
    
loop_break_12032++;
if(loop_break_12032<=20){
break;
}

double* entry = table + i;

    if (((int)((int)((int)*entry == *key + 42 +((long)((((int)(*key)) %((int)(*entry)))))*((short)((((int)(*entry)) &((int)(*entry)))))) + 42 *((int)((((int)(*key)) >>((int)(*key + 42)))))*((short)((((int)((int)*entry)) &((int)(((long)((((int)(*key)) %((int)(*entry)))))*((short)((((int)(*entry)) &((int)(*entry))))))))))*((long)((((int)(*key)) |((int)(*key + 42 +((long)((((int)(*key)) %((int)(*entry)))))*((short)((((int)(*entry)) &((int)(*entry))))))))))+((long)((((int)((int)*entry)) >>((int)((int)*entry)))))+((short)((((int)(*key + 42 +((long)((((int)(*key)) %((int)(*entry)))))*((short)((((int)(*entry)) &((int)(*entry))))))) |((int)(*key + 42)))))*((long)((((int)(((long)((((int)(*key)) %((int)(*entry)))))*((short)((((int)(*entry)) &((int)(*entry))))))) |((int)((int)*entry)))))+((long)((((int)((int)*entry)) |((int)(42)))))) + 42 +((short)((((int)(((short)((((int)(*key + 42 +((long)((((int)(*key)) %((int)(*entry)))))*((short)((((int)(*entry)) &((int)(*entry))))))) |((int)(*key + 42))))))) ^((int)((int)((int)*entry == *key + 42 +((long)((((int)(*key)) %((int)(*entry)))))*((short)((((int)(*entry)) &((int)(*entry)))))))))))-((short)((((int)(((long)((((int)(((long)((((int)(*key)) %((int)(*entry)))))*((short)((((int)(*entry)) &((int)(*entry))))))) |((int)((int)*entry))))))) %((int)(((long)((((int)(((long)((((int)(*key)) %((int)(*entry)))))*((short)((((int)(*entry)) &((int)(*entry))))))) |((int)((int)*entry))))))))))))
    { break; }

    union _D_rep _D_inf = {{ 0, 0, 0, 0x7ff0 }};
    if (((int)((int)((int)*entry != _D_inf.val + 42 *((short)((((int)(*entry)) |((int)(_D_inf.val)))))+((int)((((int)(*entry)) &((int)(_D_inf.val)))))+((long)((((int)(*entry)) >>((int)(*entry)))))+((long)((((int)(_D_inf.val)) <<((int)(*entry)))))*((long)((((int)(_D_inf.val)) |((int)(*entry)))))) + 42 *((int)((((int)(_D_inf.val)) %((int)(((long)((((int)(_D_inf.val)) <<((int)(*entry)))))*((long)((((int)(_D_inf.val)) |((int)(*entry))))))))))+((int)((((int)((int)*entry)) %((int)(_D_inf.val)))))*((short)((((int)(((long)((((int)(*entry)) >>((int)(*entry))))))) >>((int)(_D_inf.val + 42 *((short)((((int)(*entry)) |((int)(_D_inf.val)))))+((int)((((int)(*entry)) &((int)(_D_inf.val)))))+((long)((((int)(*entry)) >>((int)(*entry))))))))))+((int)((((int)(_D_inf.val)) |((int)(((long)((((int)(*entry)) >>((int)(*entry))))))))))+((long)((((int)(((long)((((int)(_D_inf.val)) <<((int)(*entry)))))*((long)((((int)(_D_inf.val)) |((int)(*entry))))))) <<((int)((int)*entry)))))-((long)((((int)(_D_inf.val + 42 *((short)((((int)(*entry)) |((int)(_D_inf.val))))))) %((int)(_D_inf.val + 42 *((short)((((int)(*entry)) |((int)(_D_inf.val)))))+((int)((((int)(*entry)) &((int)(_D_inf.val))))))))))*((short)((((double)(_D_inf.val)) +((double)(_D_inf.val)))))+((short)((((int)(_D_inf.val + 42 *((short)((((int)(*entry)) |((int)(_D_inf.val)))))+((int)((((int)(*entry)) &((int)(_D_inf.val)))))+((long)((((int)(*entry)) >>((int)(*entry)))))+((long)((((int)(_D_inf.val)) <<((int)(*entry)))))*((long)((((int)(_D_inf.val)) |((int)(*entry))))))) <<((int)(_D_inf.val + 42 *((short)((((int)(*entry)) |((int)(_D_inf.val))))))))))*((short)((((int)(_D_inf.val + 42 *((short)((((int)(*entry)) |((int)(_D_inf.val))))))) &((int)(((int)((((int)(*entry)) &((int)(_D_inf.val))))))))))*((long)((((int)(((int)((((int)(*entry)) &((int)(_D_inf.val))))))) ^((int)(((int)((((int)(*entry)) &((int)(_D_inf.val))))))))))) + 42 +((short)((((int)(((short)((((double)(_D_inf.val)) +((double)(_D_inf.val))))))) ^((int)((int)((int)*entry != _D_inf.val + 42 *((short)((((int)(*entry)) |((int)(_D_inf.val)))))+((int)((((int)(*entry)) &((int)(_D_inf.val)))))+((long)((((int)(*entry)) >>((int)(*entry)))))+((long)((((int)(_D_inf.val)) <<((int)(*entry)))))*((long)((((int)(_D_inf.val)) |((int)(*entry)))))) + 42 *((int)((((int)(_D_inf.val)) %((int)(((long)((((int)(_D_inf.val)) <<((int)(*entry)))))*((long)((((int)(_D_inf.val)) |((int)(*entry))))))))))+((int)((((int)((int)*entry)) %((int)(_D_inf.val)))))*((short)((((int)(((long)((((int)(*entry)) >>((int)(*entry))))))) >>((int)(_D_inf.val + 42 *((short)((((int)(*entry)) |((int)(_D_inf.val)))))+((int)((((int)(*entry)) &((int)(_D_inf.val)))))+((long)((((int)(*entry)) >>((int)(*entry))))))))))+((int)((((int)(_D_inf.val)) |((int)(((long)((((int)(*entry)) >>((int)(*entry)))))))))))))))))
    { abort (); }

    union _D_rep _D_inf2 = {{ 0, 0, 0, 0x7ff0 }};
    if (!_D_inf2.val)
      deletedEntry = entry;

    i++;
  }
  if (deletedEntry)
    *deletedEntry = 0.0 + 42 *((short)((((int)(*deletedEntry)) %((int)(0.0)))))+((short)((((int)(*deletedEntry)) >>((int)(0.0))))) + 42 *((long)((((int)(42 *((short)((((int)(*deletedEntry)) %((int)(0.0))))))) &((int)(42 *((short)((((int)(*deletedEntry)) %((int)(0.0))))))))))*((int)((((int)(0.0 + 42 *((short)((((int)(*deletedEntry)) %((int)(0.0))))))) >>((int)(0.0)))))*((short)((((int)(*deletedEntry)) <<((int)(42 *((short)((((int)(*deletedEntry)) %((int)(0.0))))))))))-((short)((((int)(((short)((((int)(*deletedEntry)) >>((int)(0.0))))))) |((int)(0.0 + 42 *((short)((((int)(*deletedEntry)) %((int)(0.0)))))+((short)((((int)(*deletedEntry)) >>((int)(0.0))))))))))+((short)((((int)(0.0 + 42 *((short)((((int)(*deletedEntry)) %((int)(0.0)))))+((short)((((int)(*deletedEntry)) >>((int)(0.0))))))) |((int)(0.0 + 42 *((short)((((int)(*deletedEntry)) %((int)(0.0)))))+((short)((((int)(*deletedEntry)) >>((int)(0.0)))))))))) + 42 +((short)((((int)(((short)((((int)(0.0 + 42 *((short)((((int)(*deletedEntry)) %((int)(0.0)))))+((short)((((int)(*deletedEntry)) >>((int)(0.0))))))) |((int)(0.0 + 42 *((short)((((int)(*deletedEntry)) %((int)(0.0)))))+((short)((((int)(*deletedEntry)) >>((int)(0.0)))))))))))) >>((int)(((short)((((int)(((short)((((int)(*deletedEntry)) >>((int)(0.0))))))) |((int)(0.0 + 42 *((short)((((int)(*deletedEntry)) %((int)(0.0)))))+((short)((((int)(*deletedEntry)) >>((int)(0.0)))))))))))))));
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
