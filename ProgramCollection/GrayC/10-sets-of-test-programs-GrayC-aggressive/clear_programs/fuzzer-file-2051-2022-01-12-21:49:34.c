/* corpus/990829-1.c */
double test (const double le, const double ri)
{
	double val = ( ri - le ) / ( ri * ( le + 1.0 ) );
	return val;
}

int main ()
{
        double retval;

	retval = test(1.0,2.0) + 42 +((long)((((int)(retval)) &((int)(retval)))))-((long)((((double)(retval)) *((double)(test(1.0,2.0))))))-((int)((((double)(retval)) *((double)(retval)))))-((int)((((int)(test(1.0,2.0))) <<((int)(retval)))));
        if (0)
    { abort (); }
	exit (0);
}
/* ProgramSourceLLVM */
