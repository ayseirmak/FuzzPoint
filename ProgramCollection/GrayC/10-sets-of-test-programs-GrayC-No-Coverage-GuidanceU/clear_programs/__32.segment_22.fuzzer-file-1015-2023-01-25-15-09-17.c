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

  
int loop_break_1260 = 0;

int loop_break_1308 = 0;

int loop_break_1376 = 0;
for (; y < ye; y++) {
      


loop_break_1376++;
if(loop_break_1376<=2){
continue;
}

loop_break_1308++;
if(loop_break_1308<=34){
break;
}

loop_break_1260++;
if(loop_break_1260<=46){
continue;
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
