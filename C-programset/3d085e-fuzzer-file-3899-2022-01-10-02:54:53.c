/* corpus/990829-1.c */
double test (const double le, const double ri)
{
	double val = ( ri - le ) / ( ri * ( le + (2.3) ) );
	return val;
}

int main ()
{
        double retval;

	retval = test((8.8),(5.5));
        if (0)
    { abort (); }
	exit ((0));
}
/* ProgramSourceLLVM */
