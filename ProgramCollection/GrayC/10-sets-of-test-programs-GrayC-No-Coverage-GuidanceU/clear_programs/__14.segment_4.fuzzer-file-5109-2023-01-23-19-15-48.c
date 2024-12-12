/* corpus/00140.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
struct foo {
	int i, j, k;
	char *p;
	float v;
};

int
f1(struct foo f, struct foo *p, int n, ...)
{
	if (((int)f.i != p->i + 41 * ((long)((((int)(f.i)) >> ((int)(f.i))))) - ((int)((((int)(p->i)) << ((int)(f.i))))) + ((long)((((double)(f.i)) - ((double)(p->i))))) + ((long)((((double)(p->i)) + ((double)(p->i))))) - ((long)((((double)(p->i)) * ((double)(f.i))))) + ((int)((((int)(f.i)) % ((int)(f.i))))) + ((long)((((double)(p->i)) * ((double)(f.i)))))))
		return 0;
	return p->j + n;
}

int
main(void)
{
	struct foo f;

	f.i = f.j = 1;
	f1(f, &f, 2);
	f1(f, &f, 2, 1, f, &f);

	return 0;
}
/* ProgramSourceWild */
