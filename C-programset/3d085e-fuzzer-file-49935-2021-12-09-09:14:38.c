/* corpus/990829-1.c */
double test (const double le, const double ri)
{
	double val = ( ri - le ) / ( ri * ( le + 1.0 ) );
	return val;
}

int main ()
{
        double retval;

	retval = test(1.0,2.0) + 42 *((short)((((int)(test(1.0,2.0))) |((int)(retval)))))*((long)((((int)(test(1.0,2.0))) |((int)(retval)))))*((short)((((int)(retval)) ^((int)(retval)))))-((int)((((int)(retval)) <<((int)(retval)))))-((long)((((double)(test(1.0,2.0))) +((double)(retval)))));
        if (0)
    { abort (); }
	exit (0);
}
/* ProgramSourceLLVM */
