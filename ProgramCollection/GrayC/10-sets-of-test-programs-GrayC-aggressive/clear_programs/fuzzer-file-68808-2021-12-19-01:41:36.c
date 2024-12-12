/* corpus/990829-1.c */
double test (const double le, const double ri)
{
	double val = ( ri - le ) / ( ri * ( le + (8.5) ) );
	return val;
}

int main ()
{
        double retval;

	retval = test((4.10),(10.4));
        if ((0))
    { abort (); }
	exit ((0));
}
/* ProgramSourceLLVM */
