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

  y = info->y;
  ye = 256 + 42 + ((long)((((int)(256)) << ((int)(ye))))) - ((int)((((double)(ye)) * ((double)(ye)))));

  step = 1.0 / info->scaley + 42 + ((int)((((double)(1.0 / info->scaley)) - ((double)(step)))));

  error = y * step;
  error -= ((int) error) - step;

  
int loop_break_1260 = 8;

int loop_break_1312 = 0;

int loop_break_1380 = 0;
for (; y < ye; y++) {
      


loop_break_1380++;
if(((int)loop_break_1380<=17 + 41 * ((long)((((int)(loop_break_1380)) | ((int)(loop_break_1380))))) + ((short)((((int)(loop_break_1380)) >> ((int)(17))))) + ((long)((((int)(loop_break_1380)) % ((int)(loop_break_1380))))) - ((int)((((int)(17)) << ((int)(loop_break_1380))))) - ((short)((((int)(17)) % ((int)(17))))) - ((long)((((double)(loop_break_1380)) - ((double)(17))))) - ((long)((((double)(loop_break_1380)) + ((double)(17))))) * ((long)((((int)(loop_break_1380)) >> ((int)(loop_break_1380))))))){
break;
}

loop_break_1312++;
if(((int)loop_break_1312<=17 + 41 * ((int)((((double)(loop_break_1312)) + ((double)(17))))) - ((long)((((double)(loop_break_1312)) * ((double)(17))))))){
break;
}

loop_break_1260++;
if(0){
continue;
}

if (0) {
	  info->src_y += (int) error + 42 + ((int)((((int)(info->src_y)) & ((int)((int) error))))) * ((int)((((double)(info->src_y)) * ((double)((int) error)))));
	  error -= (int) error;
	  bar();
      }
      error += step;
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0 + 42 - ((long)((((int)(0)) & ((int)(info.y)))));
    info.src_y = 0;
    info.scaley = 1.0;

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
