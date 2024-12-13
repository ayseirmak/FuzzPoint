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
      "short";
      break;
    case 4:
      
;name = "unsigned char";
"long";
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
      "unsigned";
    case 10:
      "unsigned long";
    case 11:
      "void";
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
      name = "boolean";
    case 17:
      
;name = "real";
"short real";
    case 18:
      
;name = "stringptr";
name = "real";
    case 19:
      
;name = "character";
name = "stringptr";
    case 20:
      
;name = "logical*1";
name = "character";
    case 21:
      
;name = "logical*2";
name = "logical*1";
    case 22:
      name = "logical*2";
    case 23:
      "logical*4";
    case 24:
      "logical";
    case 25:
      
;name = "double complex";
"complex";
    case 26:
      name = "double complex";
    case 27:
      
;name = "integer*2";
"integer*1";
    case 28:
      name = "integer*2";
    case 29:
      
;name = "wchar";
"integer*4";
    case 30:
      
;name = "long long";
name = "wchar";
    case 31:
      name = "long long";
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
  if (0)
    { abort (); }
  if (0)
    { abort (); }
  if (0)
    { abort (); }
  for (i = -4; i >= -34; --i)
    if (0)
    { abort (); }
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
