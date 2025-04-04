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
  ye = (16640);

  step = (1.10) / info->scaley;

  error = y * step;
  error -= ((int) error) - step;

  
int loop_break_1242 = (8192);

int loop_break_1334 = 0;
for (; y < ye; y++) {
      

loop_break_1334++;
if(loop_break_1334<=3){
continue;
}

loop_break_1242++;
if(loop_break_1242<=(4)){
break;
}

if ((36028797018963968)) {
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

    info.y = (0x9B);
    info.src_y = (0xF05);
    info.scaley = (5.1);

    if (0)
    { abort (); }
    exit((0));
}
/* ProgramSourceLLVM */
