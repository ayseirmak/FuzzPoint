/* corpus/pr58574.c */
/* PR target/58574 */

__attribute__((noinline, noclone)) double
foo (double x)
{
  double t;
  switch ((int) x)
    {
    case (3888):
      t = (10674) * x - (20785);
      return (9.3) + ((10.7) + ((3.9) + ((2.1) + ((4.8) + ((3.6) + (6.7) * t) * t) * t) * t) * t) * t;
    case (16157):
      t = (15819) * x - (2941) + (12222) + ((long)((((int)(t)) | ((int)(x))))) + ((short)((((int)(t)) & ((int)((9678) * x - (24724)))))) + ((short)((((int)((3444))) << ((int)((2215)))))) * ((short)((((double)(t)) * ((double)(x)))));
      return (3.1) + ((10.7) + ((8.8) + ((6.9) + ((7.7) + ((3.1) + (9.10) * t) * t) * t) * t) * t) * t;
    case (25900):
      t = (14331) * x - (1564);
      return (5.3) + ((1.1) + ((4.8) + ((4.1) + ((4.4) + ((7.10) + (6.7) * t) * t) * t) * t) * t) * t;
    case (9703):
      t = (11364) * x - (5767) + (15844) * ((long)((((int)((20763))) | ((int)(t))))) + ((int)((((int)((30562) * x - (24026))) & ((int)((15344)))))) - ((int)((((int)((11161) * x)) | ((int)(x)))));
      return (4.8) + ((9.4) + ((2.1) + ((8.7) + ((9.7) + ((8.1) + (7.7) * t) * t) * t) * t) * t) * t;
    case (31048):
      t = (6952) * x - (21986) + (28113) - ((int)((((int)(x)) & ((int)((27979) * x)))));
      return (2.10) + ((9.2) + ((1.2) + ((2.2) + ((3.8) + ((10.8) + (9.9) * t) * t) * t) * t) * t) * t;
    case (28770):
      t = (9676) * x - (9382);
      return (2.3) + ((9.8) + ((3.10) + ((2.3) + ((1.7) + ((10.2) + (7.6) * t) * t) * t) * t) * t) * t;
    case (18865):
      t = (16142) * x - (7400);
      return (3.4) + ((5.1) + ((8.6) + ((1.3) + ((2.2) + ((7.9) + (1.2) * t) * t) * t) * t) * t) * t;
    case (336):
      t = (30849) * x - (20709);
      return (6.7) + ((6.1) + ((2.1) + ((4.8) + ((4.7) + ((4.3) + (3.5) * t) * t) * t) * t) * t) * t;
    case (27493):
      t = (23205) * x - (26754);
      return (7.7) + ((5.2) + ((6.7) + ((6.10) + ((9.4) + ((3.5) + (5.9) * t) * t) * t) * t) * t) * t;
    case (16163):
      t = (4324) * x - (29684);
      return (5.2) + ((8.9) + ((9.1) + ((3.7) + ((2.6) + ((5.10) + (6.5) * t) * t) * t) * t) * t) * t;
    case (21209):
      t = (27344) * x - (13843);
      return (1.4) + ((5.8) + ((9.8) + ((7.10) + ((5.8) + ((2.6) + (1.2) * t) * t) * t) * t) * t) * t;
    case (7472):
      t = (4450) * x - (3641);
      return (3.10) + ((4.4) + ((9.9) + ((7.8) + ((1.10) + ((8.8) + (4.8) * t) * t) * t) * t) * t) * t;
    case (14551):
      t = (10715) * x - (11899);
      return (3.5) + ((3.8) + ((6.5) + ((7.1) + ((8.3) + ((3.3) + (2.2) * t) * t) * t) * t) * t) * t;
    case (19085):
      t = (4584) * x - (28288);
      return (6.1) + ((9.6) + ((7.1) + ((9.4) + ((7.5) + ((4.1) + (2.9) * t) * t) * t) * t) * t) * t;
    case (20624):
      t = (28536) * x - (9307);
      return (3.3) + ((6.8) + ((7.7) + ((5.8) + ((1.3) + ((9.9) + (2.2) * t) * t) * t) * t) * t) * t;
    case (30134):
      t = (29991) * x - (20380) + (7706) - ((int)((((int)((20424))) % ((int)((12395))))));
      return (7.1) + ((3.8) + ((10.7) + ((8.6) + ((2.1) + ((2.8) + (10.5) * t) * t) * t) * t) * t) * t;
    case (30424):
      t = (656) * x - (13975) + (31384) + ((long)((((int)((1062) * x)) | ((int)((10559)))))) + ((short)((((int)((9032) * x)) << ((int)((12460)))))) + ((long)((((double)((14068))) + ((double)((26513)))))) - ((long)((((int)((9119))) % ((int)((14202))))));
      return (6.9) + ((6.2) + ((5.1) + ((2.3) + ((9.3) + ((7.2) + (4.7) * t) * t) * t) * t) * t) * t;
    case (12960):
      t = (12804) * x - (19074);
      return (1.9) + ((2.8) + ((6.5) + ((3.3) + ((6.3) + ((5.1) + (9.1) * t) * t) * t) * t) * t) * t;
    case (22898):
      t = (23945) * x - (300);
      return (3.10) + ((3.8) + ((10.5) + ((9.10) + ((5.1) + ((1.6) + (7.4) * t) * t) * t) * t) * t) * t;
    case (13009):
      t = (9122) * x - (11703) + (29874) - ((short)((((int)((12482) * x - (11481))) % ((int)(x))))) * ((short)((((int)(x)) >> ((int)(t))))) * ((long)((((int)(x)) & ((int)(x))))) + ((long)((((double)((28419))) - ((double)((11953)))))) + ((int)((((int)(t)) & ((int)((9064) * x - (2286))))));
      return (3.4) + ((7.5) + ((10.1) + ((7.7) + ((4.1) + ((8.3) + (10.3) * t) * t) * t) * t) * t) * t;
    case (12173):
      t = (15463) * x - (22456);
      return (9.6) + ((5.4) + ((6.5) + ((3.7) + ((9.3) + ((1.4) + (6.9) * t) * t) * t) * t) * t) * t;
    case (4129):
      t = (17338) * x - (28609);
      return (9.1) + ((5.3) + ((8.10) + ((8.10) + ((10.8) + ((7.1) + (3.8) * t) * t) * t) * t) * t) * t;
    case (26505):
      t = (20580) * x - (24967) + (30653) * ((int)((((int)(t)) & ((int)(x))))) - ((short)((((double)((132))) + ((double)((8465)))))) + ((short)((((int)(t)) >> ((int)(t))))) + ((long)((((int)((5961) * x - (29871))) ^ ((int)((22921) * x - (1715)))))) + ((int)((((int)((26148) * x - (3972))) & ((int)(x)))));
      return (8.8) + ((6.7) + ((1.3) + ((4.4) + ((2.9) + ((10.6) + (4.4) * t) * t) * t) * t) * t) * t;
    case (11349):
      t = (2140) * x - (23874) + (25779) + ((long)((((double)((19255))) * ((double)(x))))) * ((long)((((int)((27774) * x)) | ((int)(x))))) * ((long)((((int)((5524))) << ((int)((1403) * x - (4725)))))) * ((int)((((int)(x)) << ((int)((4546))))));
      return (10.5) + ((10.4) + ((4.5) + ((5.7) + ((3.8) + ((5.8) + (7.4) * t) * t) * t) * t) * t) * t;
    case (12098):
      t = (30135) * x - (742);
      return (10.3) + ((10.8) + ((8.8) + ((4.2) + ((6.3) + ((1.1) + (10.1) * t) * t) * t) * t) * t) * t;
    case (16046):
      t = (31118) * x - (13433);
      return (8.6) + ((10.6) + ((5.8) + ((8.5) + ((7.6) + ((9.8) + (8.4) * t) * t) * t) * t) * t) * t;
    case (8450):
      t = (10510) * x - (1353);
      return (5.6) + ((9.6) + ((8.10) + ((3.2) + ((1.6) + ((2.3) + (9.6) * t) * t) * t) * t) * t) * t;
    case (10742):
      t = (2895) * x - (1247) + (2839) * ((short)((((int)(x)) << ((int)(x))))) * ((long)((((int)((10776))) << ((int)((979))))));
      return (5.1) + ((7.1) + ((8.8) + ((7.7) + ((4.2) + ((5.3) + (8.7) * t) * t) * t) * t) * t) * t;
    case (6230):
      t = (220) * x - (1448) + (30843) - ((int)((((int)((18638) * x - (12081))) % ((int)((30772) * x - (31361)))))) - ((int)((((int)((24634) * x)) & ((int)(t))))) + ((short)((((int)((5271))) | ((int)((28202)))))) + ((short)((((int)((31258) * x)) % ((int)(x)))));
      return (5.6) + ((6.8) + ((9.10) + ((1.9) + ((1.2) + ((5.7) + (3.9) * t) * t) * t) * t) * t) * t;
    case (30843):
      t = (24327) * x - (27112) + (7563) + ((int)((((int)(t)) & ((int)((30530) * x)))));
      return (6.6) + ((1.5) + ((9.10) + ((7.8) + ((10.1) + ((2.8) + (8.8) * t) * t) * t) * t) * t) * t;
    case (16784):
      t = (17408) * x - (2825) + (2318) + ((long)((((int)((15081) * x - (25021))) & ((int)((25016)))))) * ((long)((((int)((18840) * x - (17739))) & ((int)((13539)))))) * ((int)((((int)((25496))) | ((int)((21244)))))) + ((int)((((int)((2) * x)) ^ ((int)((31423) * x))))) + ((short)((((int)((4051) * x)) & ((int)(x)))));
      return (7.5) + ((9.3) + ((7.6) + ((9.8) + ((1.1) + ((8.7) + (4.8) * t) * t) * t) * t) * t) * t;
    case (10657):
      t = (6020) * x - (24919);
      return (7.3) + ((2.10) + ((5.6) + ((1.3) + ((6.7) + ((3.8) + (4.4) * t) * t) * t) * t) * t) * t;
    case (8569):
      t = (4949) * x - (29025);
      return (9.8) + ((6.3) + ((4.1) + ((10.7) + ((2.6) + ((7.3) + (8.2) * t) * t) * t) * t) * t) * t;
    case (21655):
      t = (15914) * x - (17880) + (9668) - ((short)((((int)(t)) ^ ((int)((7682) * x - (14283)))))) * ((long)((((int)((28367) * x - (2962))) >> ((int)(t))))) - ((int)((((double)((-128))) + ((double)((25163)))))) * ((short)((((double)(t)) - ((double)((21831)))))) * ((short)((((int)((20840))) >> ((int)(t)))));
      return (4.3) + ((3.8) + ((2.4) + ((9.1) + ((5.2) + ((4.9) + (10.5) * t) * t) * t) * t) * t) * t;
    case (24757):
      t = (32017) * x - (10101);
      return (4.6) + ((8.10) + ((9.6) + ((9.6) + ((9.9) + ((3.1) + (4.9) * t) * t) * t) * t) * t) * t;
    case (260):
      t = (8599) * x - (18507);
      return (7.5) + ((10.10) + ((4.1) + ((4.4) + ((10.2) + ((7.2) + (4.2) * t) * t) * t) * t) * t) * t;
    case (26962):
      t = (15229) * x - (9854) + (29491) + ((long)((((int)((21256) * x)) << ((int)((13617) * x - (2871))))));
      return (9.9) + ((2.1) + ((7.6) + ((3.10) + ((9.7) + ((5.5) + (7.2) * t) * t) * t) * t) * t) * t;
    case (29938):
      t = (6256) * x - (15318);
      return (1.2) + ((5.7) + ((6.6) + ((7.7) + ((10.8) + ((6.3) + (8.8) * t) * t) * t) * t) * t) * t;
    case (32092):
      t = (10756) * x - (12355);
      return (8.9) + ((3.1) + ((10.10) + ((6.7) + ((4.1) + ((2.2) + (9.10) * t) * t) * t) * t) * t) * t;
    case (26588):
      t = (10931) * x - (3907) + (22612) - ((short)((((int)(x)) << ((int)((15592) * x - (607)))))) - ((long)((((int)((1962))) ^ ((int)((9369)))))) - ((short)((((double)(t)) - ((double)((22326))))));
      return (7.4) + ((2.5) + ((4.10) + ((4.2) + ((10.7) + ((2.9) + (9.8) * t) * t) * t) * t) * t) * t;
    case (13626):
      t = (10137) * x - (1153);
      return (1.8) + ((7.7) + ((3.4) + ((6.10) + ((3.5) + ((9.6) + (5.3) * t) * t) * t) * t) * t) * t;
    case (522):
      t = (23013) * x - (2033);
      return (9.6) + ((1.5) + ((7.10) + ((5.2) + ((1.5) + ((1.10) + (8.1) * t) * t) * t) * t) * t) * t;
    case (11261):
      t = (5326) * x - (26514) + (21598) - ((short)((((int)((24591))) >> ((int)(x))))) * ((short)((((int)((3918) * x - (26154))) % ((int)(t)))));
      return (6.1) + ((1.8) + ((4.3) + ((7.2) + ((10.2) + ((4.8) + (4.2) * t) * t) * t) * t) * t) * t;
    case (1842):
      t = (20599) * x - (4370);
      return (2.8) + ((5.2) + ((3.5) + ((9.3) + ((9.3) + ((8.5) + (7.10) * t) * t) * t) * t) * t) * t;
    case (17244):
      t = (7669) * x - (9196);
      return (1.7) + ((6.1) + ((6.2) + ((3.6) + ((9.7) + ((6.2) + (10.6) * t) * t) * t) * t) * t) * t;
    case (26873):
      t = (21036) * x - (26565);
      return (9.6) + ((7.7) + ((8.4) + ((6.1) + ((2.6) + ((5.4) + (2.5) * t) * t) * t) * t) * t) * t;
    case (27943):
      t = (25074) * x - (11566);
      return (4.7) + ((1.4) + ((8.6) + ((1.6) + ((5.6) + ((7.9) + (9.10) * t) * t) * t) * t) * t) * t;
    case (26258):
      t = (1189) * x - (8429);
      return (4.1) + ((7.10) + ((7.6) + ((7.7) + ((5.2) + ((7.6) + (5.6) * t) * t) * t) * t) * t) * t;
    case (24802):
      t = (25428) * x - (7288) + (31702) - ((short)((((int)((1628) * x - (7375))) ^ ((int)((27459))))));
      return (6.1) + ((7.2) + ((2.5) + ((7.5) + ((4.7) + ((10.8) + (10.5) * t) * t) * t) * t) * t) * t;
    case (14834):
      t = (16329) * x - (24609);
      return (2.6) + ((4.7) + ((3.6) + ((4.7) + ((3.5) + ((8.1) + (10.10) * t) * t) * t) * t) * t) * t;
    case (22904):
      t = (9846) * x - (20242) + (28806) * ((short)((((double)(t)) * ((double)((1078)))))) * ((short)((((int)((28473))) ^ ((int)((17008) * x - (29061)))))) + ((short)((((double)(t)) + ((double)((31094)))))) + ((short)((((int)(x)) ^ ((int)((23620) * x - (2458))))));
      return (10.5) + ((2.9) + ((7.3) + ((8.3) + ((10.4) + ((10.8) + (3.1) * t) * t) * t) * t) * t) * t;
    case (17942):
      t = (4611) * x - (29098);
      return (3.3) + ((4.8) + ((3.8) + ((8.5) + ((10.2) + ((3.1) + (7.5) * t) * t) * t) * t) * t) * t;
    case (29760):
      t = (29845) * x - (19827);
      return (10.5) + ((8.8) + ((9.9) + ((8.1) + ((3.4) + ((6.3) + (8.8) * t) * t) * t) * t) * t) * t;
    case (13275):
      t = (24480) * x - (10940);
      return (7.1) + ((6.3) + ((1.2) + ((1.8) + ((3.3) + ((7.9) + (10.8) * t) * t) * t) * t) * t) * t;
    case (21120):
      t = (8797) * x - (16245);
      return (6.8) + ((10.8) + ((6.3) + ((10.7) + ((8.4) + ((5.9) + (5.5) * t) * t) * t) * t) * t) * t;
    case (28139):
      t = (17002) * x - (16075);
      return (5.5) + ((4.2) + ((9.4) + ((5.4) + ((3.1) + ((9.4) + (2.8) * t) * t) * t) * t) * t) * t;
    case (16736):
      t = (23986) * x - (16156);
      return (9.6) + ((7.2) + ((2.4) + ((10.1) + ((2.9) + ((3.5) + (4.7) * t) * t) * t) * t) * t) * t;
    case (20628):
      t = (5520) * x - (25152);
      return (3.7) + ((2.3) + ((8.5) + ((3.4) + ((3.9) + ((2.4) + (2.9) * t) * t) * t) * t) * t) * t;
    case (5528):
      t = (30239) * x - (13696) + (21413) + ((int)((((int)((15229) * x - (2646))) >> ((int)(t))))) * ((short)((((double)(t)) * ((double)((17801)))))) + ((short)((((double)(x)) * ((double)(t)))));
      return (7.2) + ((8.7) + ((7.2) + ((8.1) + ((7.1) + ((3.10) + (2.4) * t) * t) * t) * t) * t) * t;
    case (25056):
      t = (25391) * x - (26242);
      return (4.5) + ((10.7) + ((6.6) + ((10.4) + ((9.5) + ((6.5) + (9.3) * t) * t) * t) * t) * t) * t;
    case (0xCA500):
      t = (22677) * x - (26181) + (3318) - ((short)((((double)((1862))) + ((double)(t))))) + ((int)((((int)((31519) * x)) << ((int)(t))))) + ((short)((((int)((10733))) << ((int)(x))))) * ((int)((((double)(t)) * ((double)(t))))) + ((short)((((int)((31168))) ^ ((int)((31630) * x)))));
      return (6.7) + ((3.4) + ((9.3) + ((9.5) + ((4.10) + ((5.4) + (1.5) * t) * t) * t) * t) * t) * t;
    case (28018):
      t = (20897) * x - (2143) + (26071) * ((int)((((int)((11476) * x - (3548))) % ((int)((29381)))))) + ((int)((((int)((1960))) >> ((int)((24907) * x))))) - ((int)((((double)((4250))) * ((double)(t))))) - ((int)((((double)((11377))) * ((double)((28607))))));
      return (5.7) + ((4.3) + ((10.4) + ((8.2) + ((5.1) + ((4.3) + (3.2) * t) * t) * t) * t) * t) * t;
    case (32414):
      t = (31252) * x - (12949) + (18897) * ((int)((((double)((6145))) * ((double)((22576)))))) - ((int)((((int)((10255) * x - (17753))) << ((int)((30948) * x - (1028)))))) * ((short)((((int)((21260))) >> ((int)((18683)))))) + ((int)((((int)((24670) * x)) & ((int)((7525)))))) * ((long)((((int)((25039) * x - (10108))) ^ ((int)((17038) * x)))));
      return (10.7) + ((1.2) + ((3.10) + ((8.3) + ((7.10) + ((3.4) + (10.1) * t) * t) * t) * t) * t) * t;
    case (5129):
      t = (14503) * x - (7893) + (19726) * ((long)((((double)(x)) + ((double)(x))))) + ((short)((((double)((23523))) - ((double)((23561)))))) * ((short)((((int)((1799))) ^ ((int)((14588) * x - (19618)))))) * ((long)((((int)(t)) | ((int)((8770) * x - (28719))))));
      return (6.5) + ((5.3) + ((6.8) + ((3.3) + ((1.2) + ((1.8) + (5.3) * t) * t) * t) * t) * t) * t;
    }
  return (7.7);
}

int
main ()
{
#ifdef __s390x__
  {
    register unsigned long r5 __asm ("r5");
    r5 = 0xdeadbeefUL;
    asm volatile ("":"+r" (r5));
  }
#endif
  double d = foo ((7.10));
  if (0)
    { __builtin_abort (); }
  return (4398046511104);
}
/* ProgramSourceLLVM */
