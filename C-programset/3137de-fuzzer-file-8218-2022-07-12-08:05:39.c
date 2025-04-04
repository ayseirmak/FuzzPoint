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
      
;
;name = "unsigned short";
"unsigned short";
"long";
    case 5:
      "unsigned char";
    case 6:
      
;
;name = "float";
name = "unsigned short";
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
      
;"float";
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

;name;
"short real";
    case 18:
      
;
;name = "real";
"logical*1";
name = "real";
    case 19:
      name;
    case 20:
      
;"logical*1";
"character";
    case 21:
      
;"logical";
"logical*1";
    case 22:
      "logical*2";
    case 23:
      
;"logical";
"logical*4";
    case 24:
      
;
;"logical";
"complex";
"logical";
    case 25:
      
;
;"complex";
"double complex";

;name = "wchar";
"complex";
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
      
;"wchar";

;
;name = "unsigned long long";
"wchar";
"integer*4";
    case 30:
      
;
;name = "wchar";
name = "unsigned long long";
name = "wchar";
    case 31:
      
;"unsigned long long";
"long long";
    case 32:
      
;"integer*8";
"unsigned long long";
    case 33:
      
;
;"integer*8";
"integer*8";
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
