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
		return (0);
	return p->j + n;
}

int
main(void)
{
	struct foo f;

	f.i = f.j = (0x3E978);
	f1(f, &f, (2));
	f1(f, &f, (3), (1), f, &f);

	return (16384);
}
/* ProgramSourceWild */
