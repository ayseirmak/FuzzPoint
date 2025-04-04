/* corpus/990829-1.c */
double test (const double le, const double ri)
{
	double val = ( ri - le ) / ( ri * ( le + 1.0 ) );
	return val;
}

int main ()
{
        double retval;

	retval = test(1.0,2.0) + 42 -((int)((((double)(test(1.0,2.0))) +((double)(retval))))) + 42 +((int)((((int)(retval)) ^((int)(42)))))-((int)((((int)(test(1.0,2.0))) >>((int)(((int)((((double)(test(1.0,2.0))) +((double)(retval))))))))));
        if (0)
    { abort (); }
	exit (0);
}
/* ProgramSourceLLVM */
