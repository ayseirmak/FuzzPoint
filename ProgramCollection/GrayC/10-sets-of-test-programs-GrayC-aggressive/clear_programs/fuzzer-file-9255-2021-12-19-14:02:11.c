/* corpus/00113.c */
/* Taken from: https://github.com/c-testsuite/c-testsuite */
int
main()
{
	int a = (-(0x3F6));
	float f = a + ((0x24CD));

	return f == a;
}
/* ProgramSourceWild */
