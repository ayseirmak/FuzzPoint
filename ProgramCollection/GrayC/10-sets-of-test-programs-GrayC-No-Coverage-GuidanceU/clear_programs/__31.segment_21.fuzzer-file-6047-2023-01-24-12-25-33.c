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

int loop_break_1641 = 0;

int loop_break_2018 = 0;

int loop_break_7864 = 0;
while (while_condition_1360) {
    


loop_break_7864++;
if(loop_break_7864<=20){
continue;
}

loop_break_2018++;
if(((int)loop_break_2018<=23 + 41 + ((short)((((double)(loop_break_2018)) - ((double)(loop_break_2018))))) * ((long)((((int)(23)) >> ((int)(23))))) - ((long)((((int)(23)) >> ((int)(loop_break_2018))))) + ((short)((((int)(loop_break_2018)) & ((int)(loop_break_2018))))) - ((int)((((double)(loop_break_2018)) + ((double)(loop_break_2018))))))){
break;
}

loop_break_1641++;
if(((int)((int)loop_break_1641<=49 + 41 - ((long)((((int)(loop_break_1641)) % ((int)(49))))) - ((int)((((double)(loop_break_1641)) - ((double)(49))))) - ((int)((((double)(49)) * ((double)(loop_break_1641))))) * ((long)((((int)(loop_break_1641)) >> ((int)(49))))) + ((int)((((int)(loop_break_1641)) % ((int)(49))))) - ((int)((((double)(loop_break_1641)) + ((double)(49)))))) + 41 * ((long)((((double)(((long)((((int)(loop_break_1641)) % ((int)(49))))))) - ((double)(49 + 41 - ((long)((((int)(loop_break_1641)) % ((int)(49))))) - ((int)((((double)(loop_break_1641)) - ((double)(49)))))))))) + ((int)((((int)(((int)((((double)(49)) * ((double)(loop_break_1641))))))) | ((int)(49 + 41 - ((long)((((int)(loop_break_1641)) % ((int)(49))))) - ((int)((((double)(loop_break_1641)) - ((double)(49)))))))))) + ((long)((((int)(49 + 41 - ((long)((((int)(loop_break_1641)) % ((int)(49))))) - ((int)((((double)(loop_break_1641)) - ((double)(49))))) - ((int)((((double)(49)) * ((double)(loop_break_1641))))) * ((long)((((int)(loop_break_1641)) >> ((int)(49))))) + ((int)((((int)(loop_break_1641)) % ((int)(49))))))) >> ((int)((int)loop_break_1641))))) * ((short)((((int)(49 + 41 - ((long)((((int)(loop_break_1641)) % ((int)(49))))) - ((int)((((double)(loop_break_1641)) - ((double)(49))))) - ((int)((((double)(49)) * ((double)(loop_break_1641))))) * ((long)((((int)(loop_break_1641)) >> ((int)(49))))))) | ((int)(49 + 41 - ((long)((((int)(loop_break_1641)) % ((int)(49))))) - ((int)((((double)(loop_break_1641)) - ((double)(49))))) - ((int)((((double)(49)) * ((double)(loop_break_1641))))) * ((long)((((int)(loop_break_1641)) >> ((int)(49))))) + ((int)((((int)(loop_break_1641)) % ((int)(49)))))))))) - ((short)((((double)(49 + 41)) - ((double)(49 + 41))))) + ((long)((((int)(49 + 41 - ((long)((((int)(loop_break_1641)) % ((int)(49))))) - ((int)((((double)(loop_break_1641)) - ((double)(49))))) - ((int)((((double)(49)) * ((double)(loop_break_1641))))) * ((long)((((int)(loop_break_1641)) >> ((int)(49))))) + ((int)((((int)(loop_break_1641)) % ((int)(49))))) - ((int)((((double)(loop_break_1641)) + ((double)(49))))))) ^ ((int)(((int)((((double)(loop_break_1641)) + ((double)(49)))))))))) * ((int)((((int)(49 + 41 - ((long)((((int)(loop_break_1641)) % ((int)(49))))) - ((int)((((double)(loop_break_1641)) - ((double)(49))))) - ((int)((((double)(49)) * ((double)(loop_break_1641))))) * ((long)((((int)(loop_break_1641)) >> ((int)(49))))) + ((int)((((int)(loop_break_1641)) % ((int)(49))))))) | ((int)(49 + 41 - ((long)((((int)(loop_break_1641)) % ((int)(49))))) - ((int)((((double)(loop_break_1641)) - ((double)(49)))))))))) * ((long)((((int)(49 + 41 - ((long)((((int)(loop_break_1641)) % ((int)(49))))) - ((int)((((double)(loop_break_1641)) - ((double)(49))))) - ((int)((((double)(49)) * ((double)(loop_break_1641))))) * ((long)((((int)(loop_break_1641)) >> ((int)(49))))) + ((int)((((int)(loop_break_1641)) % ((int)(49))))))) % ((int)(49 + 41))))) * ((short)((((int)(((int)((((double)(loop_break_1641)) + ((double)(49))))))) | ((int)((int)loop_break_1641))))))){
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
    *deletedEntry = 0.0 + 42 + ((long)((((int)(0.0)) % ((int)(*deletedEntry))))) + ((short)((((int)(0.0)) & ((int)(0.0))))) + 42 - ((long)((((int)(0.0 + 42 + ((long)((((int)(0.0)) % ((int)(*deletedEntry))))))) | ((int)(0.0 + 42 + ((long)((((int)(0.0)) % ((int)(*deletedEntry)))))))))) * ((long)((((int)(0.0 + 42 + ((long)((((int)(0.0)) % ((int)(*deletedEntry))))) + ((short)((((int)(0.0)) & ((int)(0.0))))))) | ((int)(0.0))))) - ((long)((((int)(0.0 + 42 + ((long)((((int)(0.0)) % ((int)(*deletedEntry))))) + ((short)((((int)(0.0)) & ((int)(0.0))))))) % ((int)(0.0 + 42)))));
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
