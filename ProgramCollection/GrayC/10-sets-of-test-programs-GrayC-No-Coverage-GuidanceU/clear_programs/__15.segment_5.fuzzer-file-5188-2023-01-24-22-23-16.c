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
	if (((int)((int)f.i != p->i + 41 - ((short)((((int)(f.i)) ^ ((int)(p->i)))))) + 41 * ((long)((((int)(((short)((((int)(f.i)) ^ ((int)(p->i))))))) & ((int)(p->i))))) - ((short)((((int)(41)) & ((int)(p->i + 41 - ((short)((((int)(f.i)) ^ ((int)(p->i)))))))))) + ((short)((((double)((int)f.i)) + ((double)(((short)((((int)(f.i)) ^ ((int)(p->i)))))))))) - ((long)((((int)(p->i)) ^ ((int)(p->i))))) * ((long)((((double)((int)f.i)) - ((double)(p->i + 41))))) + ((long)((((int)(p->i)) ^ ((int)(41))))) - ((long)((((int)(41)) ^ ((int)(((short)((((int)(f.i)) ^ ((int)(p->i)))))))))) * ((long)((((double)((int)f.i)) - ((double)(p->i + 41)))))))
		return 0;
	return p->j + n;
}

int
main(void)
{
	struct foo f;

	f.i = f.j = 1 + 42 - ((short)((((double)(1)) * ((double)(1))))) - ((int)((((int)(f.j)) & ((int)(1)))));
	f1(f, &f, 2);
	f1(f, &f, 2, 1, f, &f);

	return 0;
}
/* ProgramSourceWild */
