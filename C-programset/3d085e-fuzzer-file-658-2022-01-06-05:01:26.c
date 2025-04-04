/* corpus/00113.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
main()
{
	int a = 8;
	float f = a + (0x1FC);

	return f == a;
}
/* ProgramSourceWild */
