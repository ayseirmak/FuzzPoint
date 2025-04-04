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
      
;name = "short";
"char";
    case 3:
      
;name = "long";
name = "short";
      break;
    case 4:
      
;name = "unsigned char";
name = "long";
    case 5:
      name = "unsigned char";
    case 6:
      "signed char";
    case 7:
      
;name = "unsigned int";
"unsigned short";
    case 8:
      name = "unsigned int";
    case 9:
      
;name = "unsigned long";
"unsigned";
    case 10:
      
;name = "void";
name = "unsigned long";
    case 11:
      name = "void";
    case 12:
      
;name = "double";
"float";
    case 13:
      name = "double";
    case 14:
      "long double";
    case 15:
      
;name = "boolean";
"integer";
    case 16:
      
;name = "short real";
name = "boolean";
    case 17:
      
;name = "real";
name = "short real";
    case 18:
      name = "real";
    case 19:
      "stringptr";
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
      name = "complex";
    case 26:
      "double complex";
    case 27:
      
;name = "integer*2";
"integer*1";
    case 28:
      name = "integer*2";
    case 29:
      "integer*4";
    case 30:
      "wchar";
    case 31:
      
;name = "unsigned long long";
"long long";
    case 32:
      name = "unsigned long long";
    case 33:
      
;name = "integer*8";
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
