/* corpus/990829-1.c */
double test (const double le, const double ri)
{
	double val = ( ri - le ) / ( ri * ( le + (9.10) ) );
	return val;
}

int main ()
{
        double retval;

	retval = test((7.4),(9.9)) + 42 +((long)((((int)(retval)) ^((int)(retval)))))*((short)((((double)(test((7.4),(9.9)))) -((double)(test((7.4),(9.9)))))))+((long)((((int)(test((7.4),(9.9)))) &((int)(test((7.4),(9.9)))))))-((int)((((double)(retval)) -((double)(retval))))) + 42 *((int)((((double)(((int)((((double)(retval)) -((double)(retval))))))) +((double)(((long)((((int)(test((7.4),(9.9)))) &((int)(test((7.4),(9.9))))))))))))+((short)((((int)(retval)) <<((int)(((long)((((int)(test((7.4),(9.9)))) &((int)(test((7.4),(9.9))))))))))));
        if (0)
    { abort (); }
	exit ((576460752303423488));
}
/* ProgramSourceLLVM */
