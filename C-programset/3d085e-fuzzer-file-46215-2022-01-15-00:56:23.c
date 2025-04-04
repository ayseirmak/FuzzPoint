/* corpus/990829-1.c */
double test (const double le, const double ri)
{
	double val = ( ri - le ) / ( ri * ( le + 1.0 ) );
	return val;
}

int main ()
{
        double retval;

	retval = test(1.0,2.0) + 42 +((long)((((int)(test(1.0,2.0))) ^((int)(test(1.0,2.0))))))-((short)((((double)(retval)) +((double)(test(1.0,2.0)))))) + 42 -((short)((((int)(retval)) <<((int)(((short)((((double)(retval)) +((double)(test(1.0,2.0)))))))))))*((long)((((double)(42)) *((double)(retval)))))-((int)((((double)(test(1.0,2.0))) +((double)(((long)((((int)(test(1.0,2.0))) ^((int)(test(1.0,2.0)))))))))))+((long)((((int)(test(1.0,2.0) + 42 +((long)((((int)(test(1.0,2.0))) ^((int)(test(1.0,2.0)))))))) ^((int)(test(1.0,2.0) + 42)))));
        if (0)
    { abort (); }
	exit (0);
}
/* ProgramSourceLLVM */
