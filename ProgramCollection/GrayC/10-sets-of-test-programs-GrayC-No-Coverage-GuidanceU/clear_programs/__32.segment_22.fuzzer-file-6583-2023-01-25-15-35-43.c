/* corpus/20000605-1.c */
typedef struct _RenderInfo RenderInfo;
struct _RenderInfo
{
    int y;
    float scaley;
    int src_y;
};

static void bar(void) { }

static int
render_image_rgb_a (RenderInfo * info)
{
  int y, ye;
  float error;
  float step;

  y = info->y + 42 + ((int)((((double)(y)) + ((double)(info->y))))) * ((short)((((int)(info->y)) | ((int)(info->y))))) * ((short)((((double)(info->y)) + ((double)(y))))) * ((int)((((double)(info->y)) * ((double)(info->y)))));
  ye = 256;

  step = 1.0 / info->scaley;

  error = y * step;
  error -= ((int) error) - step;

  
int loop_break_1260 = 0;

int loop_break_1308 = 0;

int loop_break_3870 = 0;
for (; y < ye; y++) {
      


loop_break_3870++;
if(loop_break_3870<=2){
continue;
}

loop_break_1308++;
if(((int)loop_break_1308<=34 + 41 - ((int)((((int)(loop_break_1308)) >> ((int)(loop_break_1308))))) + ((short)((((int)(34)) >> ((int)(34))))) + ((int)((((int)(loop_break_1308)) % ((int)(34))))) - ((short)((((double)(34)) + ((double)(loop_break_1308))))) * ((long)((((int)(loop_break_1308)) % ((int)(loop_break_1308))))))){
break;
}

loop_break_1260++;
if(((int)loop_break_1260<=46 + 41 * ((long)((((int)(loop_break_1260)) >> ((int)(46))))) * ((int)((((int)(46)) >> ((int)(loop_break_1260))))) * ((int)((((int)(46)) & ((int)(loop_break_1260))))) - ((long)((((int)(loop_break_1260)) << ((int)(loop_break_1260))))) - ((long)((((int)(46)) ^ ((int)(loop_break_1260))))) + ((long)((((int)(46)) | ((int)(loop_break_1260))))) + ((long)((((int)(loop_break_1260)) % ((int)(46))))) + ((int)((((double)(46)) - ((double)(loop_break_1260))))) * ((short)((((int)(loop_break_1260)) | ((int)(loop_break_1260))))))){
continue;
}

if (0) {
	  info->src_y += (int) error;
	  error -= (int) error + 42 + ((int)((((int)(error)) & ((int)(error))))) - ((long)((((double)((int) error)) * ((double)((int) error))))) + ((int)((((int)(error)) ^ ((int)((int) error))))) + ((short)((((double)(error)) * ((double)(error)))));
	  bar();
      }
      error += step;
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0;
    info.src_y = 0;
    info.scaley = 1.0 + 42 * ((int)((((double)(info.scaley)) * ((double)(info.scaley))))) + ((int)((((double)(1.0)) * ((double)(1.0))))) + ((int)((((double)(1.0)) * ((double)(info.scaley)))));

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
