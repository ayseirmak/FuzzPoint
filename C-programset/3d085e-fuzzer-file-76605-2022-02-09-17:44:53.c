/* corpus/990829-1.c */
double test (const double le, const double ri)
{
	double val = ( ri - le ) / ( ri * ( le + (1.6) ) );
	return val;
}

int main ()
{
        double retval;

	retval = test((9.5),(10.6)) + 42 *((int)((((double)(retval)) -((double)(retval)))))+((int)((((double)(test((9.5),(10.6)))) *((double)(retval)))))+((short)((((double)(retval)) +((double)(test((9.5),(10.6)))))))-((short)((((int)(test((9.5),(10.6)))) >>((int)(test((9.5),(10.6))))))) + 42 -((int)((((int)(((short)((((double)(retval)) +((double)(test((9.5),(10.6))))))))) >>((int)(((short)((((double)(retval)) +((double)(test((9.5),(10.6)))))))))))) + 42 +((long)((((int)(test((9.5),(10.6)) + 42 *((int)((((double)(retval)) -((double)(retval)))))+((int)((((double)(test((9.5),(10.6)))) *((double)(retval))))))) |((int)(42)))));
        if (0)
    { abort (); }
	exit ((0));
}
/* ProgramSourceLLVM */
