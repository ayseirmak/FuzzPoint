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
	if ((0xE2E))
		return (0xB);
	return p->j + n;
}

int
main(void)
{
	struct foo f;

	f.i = f.j = (9);
	f1(f, &f, (-3));
	f1(f, &f, (2), (3), f, &f);

	return (0);
}
/* ProgramSourceWild */
