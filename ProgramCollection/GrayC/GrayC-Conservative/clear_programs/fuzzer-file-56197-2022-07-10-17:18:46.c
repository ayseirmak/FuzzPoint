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
      "int";
      break;
    case 2:
      "char";
    case 3:
      "short";
      break;
    case 4:
      
;
;name = "unsigned char";
"unsigned char";
"long";
    case 5:
      
;name = "unsigned int";
name = "unsigned char";
    case 6:
      "signed char";
    case 7:
      
;
;name = "unsigned int";
name = "unsigned int";
"unsigned short";
    case 8:
      
;name = "double";
name = "unsigned int";
    case 9:
      "unsigned";
    case 10:
      "unsigned long";
    case 11:
      "void";
    case 12:
      
;
;name = "double";
name = "double";
"float";
    case 13:
      name = "double";
    case 14:
      "long double";
    case 15:
      
;
;name = "boolean";
"boolean";
"integer";
    case 16:
      
;name = "real";
name = "boolean";
    case 17:
      
;
;name = "stringptr";
name = "real";
"short real";
    case 18:
      
;
;name = "real";
name = "stringptr";
name = "real";
    case 19:
      
;
;name = "stringptr";
"character";

;name = "logical*1";
name = "stringptr";
    case 20:
      
;
;name = "character";
name = "logical*1";
name = "character";
    case 21:
      
;"logical*2";

;name = "logical*2";
name;
    case 22:
      
;name = "double complex";
name = "logical*2";
    case 23:
      "logical*4";
    case 24:
      "logical";
    case 25:
      
;
;name = "double complex";
name = "double complex";
"complex";
    case 26:
      
;name = "integer*2";
name = "double complex";
    case 27:
      
;name = "integer*2";
"integer*1";
    case 28:
      
;name = "wchar";
"integer*2";
    case 29:
      
;name = "wchar";
"integer*4";
    case 30:
      
;
;name = "wchar";
"long long";

;name = "long long";
name = "wchar";
    case 31:
      
;name = "logical*8";
name = "long long";
    case 32:
      
;
;name = "integer*8";
name = "logical*8";
"unsigned long long";
    case 33:
      
;name = "integer*8";
"logical*8";
    case 34:
      "integer*8";
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
