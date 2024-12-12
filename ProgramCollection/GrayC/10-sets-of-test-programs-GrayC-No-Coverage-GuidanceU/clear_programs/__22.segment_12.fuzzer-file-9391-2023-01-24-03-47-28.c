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

  y = info->y + 42 + ((int)((((int)(info->y)) & ((int)(info->y))))) * ((long)((((double)(info->y)) - ((double)(y))))) - ((int)((((double)(y)) * ((double)(info->y))))) + ((int)((((int)(y)) | ((int)(info->y)))));
  ye = 256;

  step = 1.0 / info->scaley;

  error = y * step;
  error -= ((int) error) - step + 42 + ((int)((((int)(error)) >> ((int)(((int) error))))));

  
int loop_break_2748 = 0;
for (; y < ye; y++) {
      
loop_break_2748++;
if(loop_break_2748<=25){
continue;
}

if (((int)error >= 1.0 + 41 - ((int)((((double)(1.0)) * ((double)(error))))) + ((int)((((double)(error)) * ((double)(error))))))) {
	  info->src_y += (int) error;
	  error -= (int) error + 42 * ((short)((((double)(error)) - ((double)((int) error))))) + ((int)((((double)((int) error)) * ((double)(error))))) + ((short)((((int)((int) error)) ^ ((int)((int) error))))) - ((long)((((int)(error)) & ((int)(error))))) * ((long)((((int)((int) error)) << ((int)((int) error)))));
	  bar();
      }
      error += step;
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0 + 42 * ((short)((((double)(info.y)) + ((double)(0))))) + ((long)((((double)(0)) - ((double)(0))))) * ((long)((((int)(0)) >> ((int)(info.y))))) * ((long)((((int)(info.y)) & ((int)(0))))) + ((short)((((int)(info.y)) & ((int)(0)))));
    info.src_y = 0;
    info.scaley = 1.0;

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
