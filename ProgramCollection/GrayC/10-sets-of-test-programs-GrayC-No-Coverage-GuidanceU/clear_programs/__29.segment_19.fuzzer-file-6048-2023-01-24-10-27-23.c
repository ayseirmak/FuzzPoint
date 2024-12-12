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
	if (((int)((int)f.i != p->i + 41 - ((long)((((double)(f.i)) - ((double)(p->i))))) * ((int)((((double)(f.i)) - ((double)(f.i))))) - ((short)((((double)(f.i)) + ((double)(f.i))))) + ((int)((((double)(f.i)) + ((double)(f.i))))) - ((short)((((int)(f.i)) >> ((int)(p->i))))) - ((short)((((double)(p->i)) - ((double)(p->i)))))) + 41 + ((int)((((int)(p->i + 41 - ((long)((((double)(f.i)) - ((double)(p->i))))) * ((int)((((double)(f.i)) - ((double)(f.i))))) - ((short)((((double)(f.i)) + ((double)(f.i))))) + ((int)((((double)(f.i)) + ((double)(f.i))))) - ((short)((((int)(f.i)) >> ((int)(p->i))))))) << ((int)(((int)((((double)(f.i)) + ((double)(f.i)))))))))) + ((int)((((double)((int)f.i)) * ((double)(p->i + 41))))) - ((long)((((double)(p->i + 41)) + ((double)((int)f.i))))) + ((short)((((int)(p->i + 41)) >> ((int)((int)f.i))))) - ((short)((((int)(((int)((((double)(f.i)) + ((double)(f.i))))))) & ((int)(((int)((((double)(f.i)) - ((double)(f.i))))))))))))
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
