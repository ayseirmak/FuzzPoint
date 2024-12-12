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
		return (0xC904D);
	return p->j + n;
}

int
main(void)
{
	struct foo f;

	f.i = f.j = (0xF0E5D);
	f1(f, &f, (0x5114));
	f1(f, &f, (-3), (1), f, &f);

	return (4096);
}
/* ProgramSourceWild */
