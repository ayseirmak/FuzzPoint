/* corpus/20030910-1.c */
/* The gimplifier was inserting unwanted temporaries for REALPART_EXPR
   nodes.  These need to be treated like a COMPONENT_REF so their address can
   be taken.  */

int main()
{
  __complex double dc;
  double *dp = &(__real dc);
  *dp = 3.14 + 42 + ((long)((((int)(3.14)) | ((int)(*dp))))) - ((long)((((int)(*dp)) & ((int)(*dp)))));
  if (0) { abort(); }
  exit (0);
}
/* ProgramSourceLLVM */
