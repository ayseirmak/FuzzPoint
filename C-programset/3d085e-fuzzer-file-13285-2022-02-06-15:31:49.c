/* corpus/00113.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
main()
{
	int a = (268435456);
	float f = a + (0xED799);

	return f == a;
}
/* ProgramSourceWild */
