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
  
int loop_break_1269 = 0;
while (1) {
    
loop_break_1269++;
if(loop_break_1269<=26){
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
      deletedEntry = entry;

    i++;
  }
  if (deletedEntry)
    *deletedEntry = 0.0 + 42 +((long)((((int)(*deletedEntry)) %((int)(0.0)))))*((int)((((int)(0.0)) >>((int)(*deletedEntry)))))-((int)((((int)(*deletedEntry)) |((int)(0.0))))) + 42 -((long)((((int)(((int)((((int)(*deletedEntry)) |((int)(0.0))))))) |((int)(((int)((((int)(*deletedEntry)) |((int)(0.0))))))))))*((int)((((int)(*deletedEntry)) >>((int)(((int)((((int)(*deletedEntry)) |((int)(0.0))))))))))*((long)((((int)(42)) %((int)(*deletedEntry)))))+((int)((((int)(0.0)) |((int)(0.0 + 42 +((long)((((int)(*deletedEntry)) %((int)(0.0)))))*((int)((((int)(0.0)) >>((int)(*deletedEntry))))))))))+((int)((((int)(0.0 + 42 +((long)((((int)(*deletedEntry)) %((int)(0.0)))))*((int)((((int)(0.0)) >>((int)(*deletedEntry)))))-((int)((((int)(*deletedEntry)) |((int)(0.0))))))) |((int)(0.0)))));
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
