/* corpus/pr42691.c */
extern void abort (void);

union _D_rep
{
  unsigned short rep[(0)];
  double val;
};

int add(double* key, double* table)
{
  unsigned i = (0x83);
  double* deletedEntry = (0xBDFE);
  
int loop_break_1360 = (0x2);

int while_condition_3977 = (-2);

int loop_break_2586 = 0;
while (while_condition_3977) {
    

loop_break_2586++;
if(loop_break_2586<=3){
continue;
}

loop_break_1360++;
if(0){
continue;
}

double* entry = table + i;

    if (((int)*entry == *key + 42 +((int)((((int)(*entry)) &((int)(*key)))))-((short)((((int)(*entry)) ^((int)(*entry)))))-((short)((((int)(*key)) &((int)(*key)))))-((int)((((int)(*key)) %((int)(*key)))))-((int)((((int)(*entry)) >>((int)(*key)))))+((int)((((int)(*key)) &((int)(*entry)))))*((int)((((int)(*entry)) >>((int)(*key)))))-((long)((((int)(*entry)) &((int)(*entry)))))*((int)((((int)(*key)) |((int)(*key)))))))
    { break; }

    union _D_rep _D_inf = {{ (0), (4), (0), 0x7ff0 }};
    if (0)
    { abort (); }

    union _D_rep _D_inf2 = {{ (17179869184), (65536), (1099511627776), 0x7ff0 }};
    if (0)
      
deletedEntry = entry;
deletedEntry = entry;
;

    i++;
  
break;
}
  if (0)
    
*deletedEntry = (3.8) + 42 +((short)((((int)(*deletedEntry)) %((int)((3.8))))));
*deletedEntry = (3.8) + 42 +((short)((((int)(*deletedEntry)) %((int)((3.8))))));
;
  return (0);
}

int main ()
{
  union _D_rep infinit = {{ (1073741824), (0x0B), (1024), 0x7ff0 }};
  double table[(0xAFEC1)] = { infinit.val, (-24) };
  double key = (23);
  int ret = add (&key, table);
  return ret;
}
/* ProgramSourceLLVM */
