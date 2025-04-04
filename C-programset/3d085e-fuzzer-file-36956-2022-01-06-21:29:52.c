/* corpus/990829-1.c */
double test (const double le, const double ri)
{
	double val = ( ri - le ) / ( ri * ( le + (7.3) ) );
	return val;
}

int main ()
{
        double retval;

	retval = test((1.8),(9.2)) + (0xCE) -((int)((((double)(test((4.5),(7.1)))) +((double)(retval)))));
        if (0)
    { abort (); }
	exit ((0));
}
/* ProgramSourceLLVM */
