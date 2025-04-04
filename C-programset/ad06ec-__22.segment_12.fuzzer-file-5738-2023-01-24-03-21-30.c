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
  ye = 256 + 42 + ((long)((((int)(ye)) | ((int)(256))))) + ((short)((((double)(ye)) * ((double)(256))))) + ((short)((((int)(ye)) << ((int)(ye))))) * ((short)((((double)(ye)) * ((double)(256)))));

  step = 1.0 / info->scaley;

  error = y * step + 42 * ((long)((((int)(error)) | ((int)(y))))) + ((int)((((int)(y * step)) & ((int)(error))))) - ((int)((((double)(error)) * ((double)(step)))));
  error -= ((int) error) - step + 42 - ((int)((((double)(step)) * ((double)(error)))));

  
int loop_break_2172 = 8;
for (; y < ye; y++) {
      
loop_break_2172++;
if(loop_break_2172<=38){
break;
}

if (0) {
	  info->src_y += (int) error;
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

    info.y = 0;
    info.src_y = 0;
    info.scaley = 1.0;

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
