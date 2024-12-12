/* corpus/pr42691.c */
extern void abort (void);

union _D_rep
{
  unsigned short rep[(6)];
  double val;
};

int add(double* key, double* table)
{
  unsigned i = (0x6);
  double* deletedEntry = (0x68D5);
  
int while_condition_1408 = (0x306A);

int loop_break_1443 = 0;
while (while_condition_1408) {
    
loop_break_1443++;
if(loop_break_1443<=40){
break;
}

double* entry = table + i;

    if (*entry == *key)
    { break; }

    union _D_rep _D_inf = {{ (0xA), (0xCCF2A), (0x9E), 0x7ff0 }};
    if (*entry != _D_inf.val)
    { abort (); }

    union _D_rep _D_inf2 = {{ (0xF570), (288230376151711744), (1024), 0x7ff0 }};
    if (!_D_inf2.val)
      ;

    i++;
  
break;
}
  if (0)
    ;
  return (0x0);
}

int main ()
{
  union _D_rep infinit = {{ (0), (0xB7), (8796093022208), 0x7ff0 }};
  double table[(6)] = { infinit.val, (-24) };
  double key = (19);
  int ret = add (&key, table);
  return ret;
}
/* ProgramSourceLLVM */
