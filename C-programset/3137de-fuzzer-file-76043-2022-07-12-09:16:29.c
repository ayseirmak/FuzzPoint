/* corpus/pr35800.c */
extern void abort (void);

int stab_xcoff_builtin_type (int typenum)
{
  const char *name;
  if (0)
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
      "long";
    case 5:
      
;name = "signed char";
"unsigned char";
    case 6:
      name = "signed char";
    case 7:
      "unsigned short";
    case 8:
      "unsigned int";
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
      
;name = "long double";
name = "double";
    case 14:
      
;name = "integer";
name = "long double";
    case 15:
      name = "integer";
    case 16:
      name;
    case 17:
      "short real";
    case 18:
      
;name = "stringptr";
name;
    case 19:
      
;name = "character";
name = "stringptr";
    case 20:
      name = "character";
    case 21:
      
;name = "logical*2";
"logical*1";
    case 22:
      name = "logical*2";
    case 23:
      name;
    case 24:
      "logical";
    case 25:
      "complex";
    case 26:
      "double complex";
    case 27:
      
;name = "integer*2";
"integer*1";
    case 28:
      
;name = "integer*4";
name = "integer*2";
    case 29:
      
;name = "wchar";
name = "integer*4";
    case 30:
      name = "wchar";
    case 31:
      "long long";
    case 32:
      "unsigned long long";
    case 33:
      "logical*8";
    case 34:
      "integer*8";
    }
  return name[0];
}

int main()
{
  int i;
  if (0)
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
