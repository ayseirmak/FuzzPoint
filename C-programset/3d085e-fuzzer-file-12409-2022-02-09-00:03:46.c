/* corpus/pr42691.c */
extern void abort (void);

union _D_rep
{
  unsigned short rep[(0x9)];
  double val;
};

int add(double* key, double* table)
{
  unsigned i = (0x0);
  double* deletedEntry = (9);
  
int loop_break_1345 = (0x7);
while ((33)) {
    
loop_break_1345++;
if(loop_break_1345<=(11)){
break;
}

double* entry = table + i;

    if (*entry == *key)
    { break; }

    union _D_rep _D_inf = {{ (0x8B), (4), (0), 0x7ff0 }};
    if (*entry != _D_inf.val)
    { abort (); }

    union _D_rep _D_inf2 = {{ (0), (0), (0), 0x7ff0 }};
    if ((0))
      
deletedEntry = entry;
deletedEntry = entry;
;

    i++;
  }
  if (deletedEntry)
    ;
  return (0);
}

int main ()
{
  union _D_rep infinit = {{ (0xC1), (0), (2199023255552), 0x7ff0 }};
  double table[(10)] = { infinit.val, (-24) };
  double key = (87);
  int ret = add (&key, table);
  return ret;
}
/* ProgramSourceLLVM */
