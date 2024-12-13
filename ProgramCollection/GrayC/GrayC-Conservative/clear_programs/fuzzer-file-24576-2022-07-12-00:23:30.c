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
      
;"long";
"short";
      break;
    case 4:
      
;name = "unsigned short";
"long";
    case 5:
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
      
;
;name = "float";
"void";
"unsigned long";
    case 11:
      
;name = "float";
"void";
    case 12:
      "float";
    case 13:
      
;"long double";
"double";
    case 14:
      "long double";
    case 15:
      "integer";
    case 16:
      
;"short real";
"boolean";
    case 17:
      
;"real";

;name = "real";
"short real";
    case 18:
      
;name = "logical*1";
name = "real";
    case 19:
      name;
    case 20:
      
;name = "logical*1";
"character";
    case 21:
      
;name = "logical";
"logical*1";
    case 22:
      "logical*2";
    case 23:
      
;name = "logical";
"logical*4";
    case 24:
      
;
;name = "logical";
"complex";
name = "logical";
    case 25:
      
;
;name = "complex";
"double complex";
name = "complex";
    case 26:
      "double complex";
    case 27:
      "integer*1";
    case 28:
      
;
;name = "wchar";
name;
"integer*2";
    case 29:
      
;name = "wchar";

;name = "wchar";
"integer*4";
    case 30:
      
;name = "unsigned long long";
name = "wchar";
    case 31:
      
;name = "unsigned long long";
"long long";
    case 32:
      
;name = "integer*8";
"unsigned long long";
    case 33:
      
;
;name = "integer*8";
name = "integer*8";
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
