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
		return (0xED);
	return p->j + n;
}

int
main(void)
{
	struct foo f;

	f.i = f.j = (0x6F71C);
	f1(f, &f, (3));
	f1(f, &f, (0x7E), (-2), f, &f);

	return (8388608);
}
/* ProgramSourceWild */
