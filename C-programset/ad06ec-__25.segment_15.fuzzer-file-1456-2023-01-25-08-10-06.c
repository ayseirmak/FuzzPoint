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
	if (0)
		return 0;
	return p->j + n;
}

int
main(void)
{
	struct foo f;

	f.i = 1 + 42 + ((int)((((double)(1)) * ((double)(1))))) + ((int)((((double)(1)) + ((double)(1))))) * ((long)((((double)(1)) * ((double)(1)))));
	f1(f, &f, 2);
	f1(f, &f, 2, 1, f, &f);

	return 0;
}
/* ProgramSourceWild */
