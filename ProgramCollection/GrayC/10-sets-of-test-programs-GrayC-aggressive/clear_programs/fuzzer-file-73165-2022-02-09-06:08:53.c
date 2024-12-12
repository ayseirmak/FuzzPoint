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
	if (f.i != p->i)
		return ((-1));
	return p->j + n;
}

int
main(void)
{
	struct foo f;

	f.i = f.j = ((0));
	f1(f, &f, ((-3)));
	f1(f, &f, ((-3)), ((-4)), f, &f);

	return ((1152921504606846976));
}
/* ProgramSourceWild */
