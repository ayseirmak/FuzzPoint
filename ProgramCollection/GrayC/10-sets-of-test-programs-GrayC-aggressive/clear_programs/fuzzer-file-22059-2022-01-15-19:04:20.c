/* corpus/pr42691.c */
extern void abort (void);

union _D_rep
{
  unsigned short rep[(4)];
  double val;
};

int add(double* key, double* table)
{
  unsigned i = (-1);
  double* deletedEntry = (8);
  
int loop_break_1360 = (-1);

int while_condition_1399 = (3);

int loop_break_1421 = 0;

int loop_break_1487 = 0;

int loop_break_1553 = 0;
while (while_condition_1399) {
    



loop_break_1553++;
if(loop_break_1553<=39){
break;
}

loop_break_1487++;
if(loop_break_1487<=46){
continue;
}

loop_break_1421++;
if(loop_break_1421<=49){
continue;
}

loop_break_1360++;
if(0){
continue;
}

double* entry = table + i;

    if (0)
    { break; }

    union _D_rep _D_inf = {{ (0), (0xE53C5), (0xBB2F), 0x7ff0 }};
    if ((0x2AAA5))
    { abort (); }

    union _D_rep _D_inf2 = {{ (0), (134217728), (1), 0x7ff0 }};
    if (0)
      deletedEntry = entry;

    i++;
  
break;
}
  if (0)
    *deletedEntry = (5.9) + 42 +((short)((((int)(*deletedEntry)) <<((int)((5.9))))))-((int)((((int)(*deletedEntry)) >>((int)(*deletedEntry)))))*((long)((((int)(*deletedEntry)) &((int)(*deletedEntry)))));
  return (0);
}

int main ()
{
  union _D_rep infinit = {{ (4), (0), (-1), 0x7ff0 }};
  double table[(34)] = { infinit.val, (73) };
  double key = (23);
  int ret = add (&key, table);
  return ret;
}
/* ProgramSourceLLVM */
