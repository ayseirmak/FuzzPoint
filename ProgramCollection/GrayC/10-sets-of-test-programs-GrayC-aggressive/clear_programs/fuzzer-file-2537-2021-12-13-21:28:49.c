/* corpus/20030910-1.c */
/* The gimplifier was inserting unwanted temporaries for REALPART_EXPR
   nodes.  These need to be treated like a COMPONENT_REF so their address can
   be taken.  */

int main()
{
  __complex double dc;
  double *dp = &(__real dc);
  *dp = (1.10) + (-43) +((int)((((double)((7.1))) -((double)((7.8))))))*((short)((((double)((4.6))) -((double)((5.8))))))-((short)((((int)(*dp)) <<((int)((2.5))))))*((short)((((int)(*dp)) |((int)(*dp)))))*((long)((((int)((1.6))) &((int)((4.7))))));
  if ((0)) { abort(); }
  exit ((0));
}
/* ProgramSourceLLVM */
