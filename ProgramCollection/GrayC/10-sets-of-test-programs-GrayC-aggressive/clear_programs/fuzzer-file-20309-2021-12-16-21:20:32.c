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

  y = info->y + 42 +((short)((((double)(y)) -((double)(y)))))-((int)((((double)(y)) +((double)(y)))))*((int)((((int)(info->y)) >>((int)(info->y)))));
  ye = (255) + 42 -((int)((((double)(ye)) *((double)(ye)))))+((long)((((double)((255))) *((double)(ye)))));

  step = (7.8) / info->scaley + 42 *((int)((((double)((7.8) / info->scaley)) *((double)((7.8) / info->scaley)))))+((short)((((int)((7.8) / info->scaley)) <<((int)((7.8) / info->scaley)))))+((long)((((int)((7.8) / info->scaley)) &((int)((7.8) / info->scaley)))));

  error = y * step + 42 -((short)((((int)(step)) %((int)(y)))));
  error -= ((int) error) - step + 42 -((short)((((int)(error)) ^((int)(step)))))-((int)((((int)(((int) error) - step)) >>((int)(step)))))*((long)((((int)(step)) ^((int)(((int) error) - step)))))*((long)((((int)(step)) ^((int)(step)))))*((long)((((int)(error)) >>((int)(step)))));

  
int loop_break_3980 = 0;
for (; y < ye; y++) {
      
loop_break_3980++;
if(0){
break;
}

if ((-1)) {
	  info->src_y += (int) error + 42 -((int)((((int)(info->src_y)) ^((int)(info->src_y)))))+((short)((((int)((int) error)) ^((int)((int) error)))));
	  error -= (int) error + 42 -((short)((((double)((int) error)) -((double)((int) error)))))+((long)((((int)(error)) %((int)(error)))))-((long)((((int)((int) error)) |((int)((int) error)))));
	  bar();
      }
      error += step + 42 *((short)((((double)(error)) *((double)(step)))))+((short)((((int)(step)) <<((int)(error)))));
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = (0) + 42 *((int)((((int)((0))) ^((int)((0))))))-((short)((((double)((0))) -((double)((0))))))*((int)((((double)(info.y)) *((double)((0))))));
    info.src_y = (0) + 42 +((int)((((double)((0))) *((double)((0))))))*((int)((((int)(info.src_y)) ^((int)((0))))))-((short)((((int)(info.src_y)) >>((int)((0))))))*((short)((((int)((0))) ^((int)(info.src_y)))));
    info.scaley = (3.5) + 42 +((int)((((int)((3.5))) %((int)((3.5))))))-((int)((((double)((3.5))) *((double)((3.5))))))*((int)((((double)(info.scaley)) +((double)(info.scaley)))))-((int)((((int)((3.5))) ^((int)((3.5))))));

    if (0)
    { abort (); }
    exit((0));
}
/* ProgramSourceLLVM */
