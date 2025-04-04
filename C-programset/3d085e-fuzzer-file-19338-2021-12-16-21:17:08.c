/* corpus/20030910-1.c */
/* The gimplifier was inserting unwanted temporaries for REALPART_EXPR
   nodes.  These need to be treated like a COMPONENT_REF so their address can
   be taken.  */

int main()
{
  __complex double dc;
  double *dp = &(__real dc);
  
*dp = (1.7);
*dp = (1.7);
;
  if (0) { abort(); }
  exit ((4096));
}
/* ProgramSourceLLVM */
