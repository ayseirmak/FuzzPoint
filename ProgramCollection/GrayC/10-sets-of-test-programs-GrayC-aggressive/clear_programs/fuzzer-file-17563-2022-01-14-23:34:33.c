/* corpus/990829-1.c */
double test (const double le, const double ri)
{
	double val = ( ri - le ) / ( ri * ( le + (4.8) ) );
	return val;
}

int main ()
{
        double retval;

	
retval = test((7.1),(10.2)) + (42) +((long)((((int)(test((5.3),(7.8)))) ^((int)(test((7.5),(6.2)))))))-((short)((((double)(retval)) +((double)(test((6.2),(8.3)))))));
retval = test((7.1),(10.2)) + (42) +((long)((((int)(test((5.3),(7.8)))) ^((int)(test((7.5),(6.2)))))))-((short)((((double)(retval)) +((double)(test((6.2),(8.3)))))));
;
        if (0)
    { abort (); }
	exit ((0));
}
/* ProgramSourceLLVM */
