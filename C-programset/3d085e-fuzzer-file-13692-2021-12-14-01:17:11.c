/* corpus/990829-1.c */
double test (const double le, const double ri)
{
	double val = ( ri - le ) / ( ri * ( le + (6.3) ) );
	return val;
}

int main ()
{
        double retval;

	retval = test((7.1),(2.5)) + (-43) +((short)((((int)(test((10.4),(3.2)))) >>((int)(test((8.5),(2.2)))))))+((int)((((double)(test((5.7),(2.2)))) +((double)(retval)))))+((int)((((int)(test((3.5),(2.4)))) &((int)(test((8.8),(5.3)))))))-((long)((((double)(retval)) -((double)(test((2.5),(3.4)))))));
        if (0)
    { abort (); }
	exit ((0));
}
/* ProgramSourceLLVM */
