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
      name = "long";
    case 5:
      
;name = "signed char";
"unsigned char";
    case 6:
      name = "signed char";
    case 7:
      
;name = "unsigned int";
"unsigned short";
    case 8:
      name = "unsigned int";
    case 9:
      name;
    case 10:
      
;name = "void";
"unsigned long";
    case 11:
      name = "void";
    case 12:
      name;
    case 13:
      
;name = "long double";
"double";
    case 14:
      name = "long double";
    case 15:
      
;name = "boolean";
name;
    case 16:
      
;name = "short real";
name = "boolean";
    case 17:
      
;name = "real";
name = "short real";
    case 18:
      
;name = "stringptr";
name = "real";
    case 19:
      name = "stringptr";
    case 20:
      
;name = "logical*1";
"character";
    case 21:
      
;name = "logical*2";
name = "logical*1";
    case 22:
      name = "logical*2";
    case 23:
      
;name = "logical";
"logical*4";
    case 24:
      
;name = "complex";
name = "logical";
    case 25:
      
;name = "double complex";
name = "complex";
    case 26:
      name = "double complex";
    case 27:
      
;name = "integer*2";
name;
    case 28:
      name = "integer*2";
    case 29:
      
;name = "wchar";
"integer*4";
    case 30:
      name = "wchar";
    case 31:
      "long long";
    case 32:
      
;name = "logical*8";
"unsigned long long";
    case 33:
      
;name = "integer*8";
name = "logical*8";
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
