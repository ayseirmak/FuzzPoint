/* corpus/00113.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
main()
{
	int a = (536870912);
	float f = a + (0xFAEF3);

	return f == a;
}
/* ProgramSourceWild */
