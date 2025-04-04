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
	if (((int)((int)f.i != p->i + 41 - ((short)((((int)(f.i)) ^ ((int)(p->i)))))) + 41 - ((long)((((double)(41)) + ((double)(((short)((((int)(f.i)) ^ ((int)(p->i)))))))))) * ((long)((((int)(p->i + 41 - ((short)((((int)(f.i)) ^ ((int)(p->i))))))) >> ((int)(p->i))))) - ((long)((((int)(41)) | ((int)(((short)((((int)(f.i)) ^ ((int)(p->i)))))))))) + ((short)((((int)(p->i + 41 - ((short)((((int)(f.i)) ^ ((int)(p->i))))))) ^ ((int)((int)f.i))))) + ((short)((((int)(p->i + 41)) ^ ((int)(p->i))))) - ((long)((((double)(((short)((((int)(f.i)) ^ ((int)(p->i))))))) + ((double)((int)f.i)))))))
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
