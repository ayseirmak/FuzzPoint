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
	if (((int)f.i != p->i + 42 *((int)((((double)(f.i)) *((double)(f.i)))))+((short)((((int)(p->i)) ^((int)(p->i)))))+((short)((((int)(f.i)) ^((int)(p->i)))))*((long)((((double)(f.i)) -((double)(p->i)))))+((int)((((double)(p->i)) *((double)(p->i)))))-((int)((((double)(p->i)) -((double)(p->i)))))+((long)((((int)(f.i)) &((int)(p->i)))))+((long)((((double)(p->i)) -((double)(p->i)))))))
		return 0;
	return p->j + n;
}

int
main(void)
{
	struct foo f;

	f.i = f.j = 1 + 42 *((short)((((int)(f.j = 1)) <<((int)(f.j)))));
	f1(f, &f, 2);
	f1(f, &f, 2, 1, f, &f);

	return 0;
}
/* ProgramSourceWild */
