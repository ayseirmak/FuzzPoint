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

int loop_break_1363 = 0;

int loop_break_1364 = 0;

int loop_break_3572 = 0;
while (while_condition_1360) {
    


loop_break_3572++;
if(loop_break_3572<=2){
continue;
}

loop_break_1364++;
if(((int)((int)loop_break_1364<=31 + 42 +((short)((((double)(loop_break_1364)) *((double)(loop_break_1364)))))*((short)((((double)(loop_break_1364)) +((double)(loop_break_1364)))))-((int)((((double)(loop_break_1364)) *((double)(31)))))) + 42 -((short)((((int)(((int)((((double)(loop_break_1364)) *((double)(31))))))) ^((int)(42)))))*((int)((((int)(((short)((((double)(loop_break_1364)) +((double)(loop_break_1364))))))) &((int)(31 + 42 +((short)((((double)(loop_break_1364)) *((double)(loop_break_1364)))))*((short)((((double)(loop_break_1364)) +((double)(loop_break_1364)))))-((int)((((double)(loop_break_1364)) *((double)(31))))))))))-((long)((((int)((int)loop_break_1364)) ^((int)((int)loop_break_1364)))))+((short)((((int)((int)loop_break_1364)) ^((int)(31 + 42 +((short)((((double)(loop_break_1364)) *((double)(loop_break_1364)))))*((short)((((double)(loop_break_1364)) +((double)(loop_break_1364))))))))))*((long)((((double)(((short)((((double)(loop_break_1364)) +((double)(loop_break_1364))))))) +((double)(42)))))-((short)((((int)(((short)((((double)(loop_break_1364)) *((double)(loop_break_1364)))))*((short)((((double)(loop_break_1364)) +((double)(loop_break_1364))))))) |((int)(((short)((((double)(loop_break_1364)) *((double)(loop_break_1364)))))))))))){
break;
}

loop_break_1363++;
if(0){
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
  
break;
}
  if (0)
    *deletedEntry = 0.0 + 42 +((int)((((int)(0.0)) <<((int)(0.0))))) + 42 *((int)((((int)(0.0)) |((int)(*deletedEntry)))))+((int)((((double)(0.0 + 42)) -((double)(0.0 + 42 +((int)((((int)(0.0)) <<((int)(0.0))))))))))-((short)((((int)(*deletedEntry)) ^((int)(0.0 + 42)))))*((short)((((int)(*deletedEntry)) >>((int)(0.0 + 42 +((int)((((int)(0.0)) <<((int)(0.0))))))))))*((long)((((int)(0.0 + 42 +((int)((((int)(0.0)) <<((int)(0.0))))))) <<((int)(0.0 + 42)))));
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
