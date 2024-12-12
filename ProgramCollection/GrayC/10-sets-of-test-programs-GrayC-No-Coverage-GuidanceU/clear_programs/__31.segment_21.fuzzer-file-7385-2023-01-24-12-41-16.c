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
  ye = 256;

  step = 1.0 / info->scaley;

  error = y * step;
  error -= ((int) error) - step;

  
int loop_break_2600 = 0;

int loop_break_2665 = 0;
for (; y < ye; y++) {
      

loop_break_2665++;
if(loop_break_2665<=33){
continue;
}

loop_break_2600++;
if(loop_break_2600<=23){
break;
}

if (((int)error >= 1.0 + 41 + ((long)((((double)(error)) - ((double)(1.0))))) - ((short)((((double)(1.0)) - ((double)(1.0))))) * ((long)((((int)(1.0)) ^ ((int)(error))))) + ((short)((((int)(1.0)) ^ ((int)(error))))) + ((short)((((double)(error)) + ((double)(1.0))))) * ((int)((((double)(error)) * ((double)(error))))) - ((short)((((int)(1.0)) & ((int)(error))))) - ((long)((((double)(error)) * ((double)(error))))) - ((short)((((int)(error)) ^ ((int)(error))))) - ((int)((((double)(error)) + ((double)(error))))))) {
	  info->src_y += (int) error;
	  error -= (int) error;
	  bar();
      }
      error += step + 42 + ((int)((((double)(error)) * ((double)(step))))) - ((int)((((double)(step)) * ((double)(error)))));
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0;
    info.src_y = 0 + 42 * ((short)((((double)(0)) - ((double)(0))))) - ((long)((((int)(0)) >> ((int)(0))))) - ((short)((((int)(0)) & ((int)(0))))) * ((short)((((int)(info.src_y)) >> ((int)(0)))));
    info.scaley = 1.0;

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
