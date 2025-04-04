/* corpus/990829-1.c */
double test (const double le, const double ri)
{
	double val = ( ri - le ) / ( ri * ( le + (7.2) ) );
	return val;
}

int main ()
{
        double retval;

	retval = test((6.10),(4.7)) + (-43) +((long)((((int)(test((7.10),(9.2)))) ^((int)(test((9.7),(7.5)))))))-((short)((((double)(retval)) +((double)(test((8.4),(2.9)))))));
        if (0)
    { abort (); }
	exit ((8192));
}
/* ProgramSourceLLVM */
