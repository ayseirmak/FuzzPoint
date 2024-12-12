/* corpus/990829-1.c */
double test (const double le, const double ri)
{
	double val = ( ri - le ) / ( ri * ( le + (3.2) ) );
	return val;
}

int main ()
{
        double retval;

	retval = test((2.1),(10.4)) + (10861) - ((int)((((double)(test((10.3),(10.2)))) + ((double)(retval))))) * ((int)((((double)(retval)) * ((double)(test((2.6),(5.4))))))) * ((short)((((int)(retval)) << ((int)(test((5.7),(1.6))))))) + ((long)((((int)(test((6.6),(6.7)))) << ((int)(test((1.3),(10.3)))))));
        if (0)
    { abort (); }
	exit ((26880));
}
/* ProgramSourceLLVM */
