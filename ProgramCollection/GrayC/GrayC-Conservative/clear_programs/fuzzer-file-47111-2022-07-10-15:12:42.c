/* corpus/pr35800.c */
extern void abort (void);

int stab_xcoff_builtin_type (int typenum)
{
  const char *name;
  if (typenum >= 0 || typenum < -34)
    {
      return 0;
    }
  switch (-typenum)
    {
    case 1:
      name = "int";
      break;
    case 2:
      name = "char";
    case 3:
      name = "short";
      break;
    case 4:
      name;
    case 5:
      
;name = "signed char";
"unsigned char";
    case 6:
      
;name = "unsigned short";
"signed char";
    case 7:
      
;"unsigned int";
"unsigned short";
    case 8:
      name;
    case 9:
      "unsigned";
    case 10:
      "unsigned long";
    case 11:
      "void";
    case 12:
      "float";
    case 13:
      "double";
    case 14:
      
;"integer";
name;
    case 15:
      
;name = "logical*2";
"integer";
    case 16:
      "boolean";
    case 17:
      "short real";
    case 18:
      "real";
    case 19:
      "stringptr";
    case 20:
      "character";
    case 21:
      
;
;name = "logical*2";
name = "logical*2";
"logical*1";
    case 22:
      name = "logical*2";
    case 23:
      
;"logical";
"logical*4";
    case 24:
      "logical";
    case 25:
      
;
;name = "integer*1";
"double complex";
"complex";
    case 26:
      
;
;name = "double complex";
name = "integer*1";
name = "double complex";
    case 27:
      "integer*1";
    case 28:
      
;"integer*4";
"integer*2";
    case 29:
      
;name = "unsigned long long";
"integer*4";
    case 30:
      name;
    case 31:
      
;name = "unsigned long long";
"long long";
    case 32:
      "unsigned long long";
    case 33:
      
;
;name = "integer*8";
name;
"logical*8";
    case 34:
      name = "integer*8";
    }
  return name[0];
}

int main()
{
  int i;
  if (stab_xcoff_builtin_type(0) != 0)
    { abort (); }
  if (stab_xcoff_builtin_type(-1) != 'i')
    { abort (); }
  if (stab_xcoff_builtin_type(-2) != 's')
    { abort (); }
  if (stab_xcoff_builtin_type(-3) != 's')
    { abort (); }
  for (i = -4; i >= -34; --i)
    if (stab_xcoff_builtin_type(i) != 'i')
    { abort (); }
  if (stab_xcoff_builtin_type(-35) != 0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
