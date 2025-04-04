/* corpus/00113.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
main()
{
	int a = (0xF);
	float f = a + (0x60FE);

	return f == a;
}
/* ProgramSourceWild */
