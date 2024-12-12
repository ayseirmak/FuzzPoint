/* corpus/pr42691.c */
extern void abort (void);

union _D_rep
{
  unsigned short rep[(0xB4)];
  double val;
};

int add(double* key, double* table)
{
  unsigned i = ((0));
  double* deletedEntry = ((0));
  
int loop_break_1343 = (40);

int loop_break_1428 = 0;
while ((-(-3))) {
    

loop_break_1428++;
if(loop_break_1428<=23){
break;
}

loop_break_1343++;
if(0){
break;
}

double* entry = table + i;

    if (0)
    { break; }

    union _D_rep _D_inf = {{ ((194217728)), ((0)), (0xE816), 0x7ff0 }};
    if ((0x72))
    { abort (); }

    union _D_rep _D_inf2 = {{ ((1024)), ((0)), ((-1)), 0x7ff0 }};
    if (0)
      ;

    i++;
  }
  if (deletedEntry)
    ;
  return ((8796093022208));
}

int main ()
{
  union _D_rep infinit = {{ ((0x5F)), (0xF57), (-(1)), 0x7ff0 }};
  double table[(0x29)] = { infinit.val, ((0xE6E9B)) };
  double key = (-(-25));
  int ret = add (&key, table);
  return ret;
}
/* ProgramSourceLLVM */
