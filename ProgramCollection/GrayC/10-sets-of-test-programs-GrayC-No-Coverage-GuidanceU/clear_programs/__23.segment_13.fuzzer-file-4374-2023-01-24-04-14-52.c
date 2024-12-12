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
		return (9399);
	return p->j + n;
}

int
main(void)
{
	struct foo f;

	f.i = f.j = (4900);
	f1(f, &f, (24046));
	f1(f, &f, (9537), (12336), f, &f);

	return (70368744177664);
}
/* ProgramSourceWild */
