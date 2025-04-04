/* corpus/00113.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
main()
{
	int a = (549755813888);
	float f = a + (0x6);

	return f == a;
}
/* ProgramSourceWild */
