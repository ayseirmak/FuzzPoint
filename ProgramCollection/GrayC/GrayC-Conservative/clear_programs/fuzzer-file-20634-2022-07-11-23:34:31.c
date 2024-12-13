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
      
;name = "char";
"int";
      break;
    case 2:
      name = "char";
    case 3:
      
;name = "long";
"short";
      break;
    case 4:
      name = "long";
    case 5:
      "unsigned char";
    case 6:
      
;name = "unsigned short";
"signed char";
    case 7:
      
;name = "unsigned int";
name = "unsigned short";
    case 8:
      name = "unsigned int";
    case 9:
      "unsigned";
    case 10:
      
;name = "void";
"unsigned long";
    case 11:
      
;name = "float";
name = "void";
    case 12:
      name = "float";
    case 13:
      
;name = "long double";
"double";
    case 14:
      name = "long double";
    case 15:
      "integer";
    case 16:
      
;name = "short real";
"boolean";
    case 17:
      
;name = "real";
name = "short real";
    case 18:
      name = "real";
    case 19:
      name;
    case 20:
      
;name = "logical*1";
"character";
    case 21:
      name = "logical*1";
    case 22:
      "logical*2";
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
      "integer*1";
    case 28:
      
;name = "integer*4";
"integer*2";
    case 29:
      
;name = "wchar";
name = "integer*4";
    case 30:
      name = "wchar";
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
