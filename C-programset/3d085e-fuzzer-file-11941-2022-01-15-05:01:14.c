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

  y = info->y + 42 -((long)((((double)(info->y)) -((double)(info->y)))))-((int)((((double)(info->y)) +((double)(y)))))*((int)((((int)(y)) >>((int)(info->y)))))*((short)((((double)(y)) *((double)(y)))));
  ye = 256 + 42 -((int)((((double)(ye)) *((double)(ye)))))-((short)((((int)(256)) >>((int)(256)))));

  step = 1.0 / info->scaley + 42 *((short)((((double)(1.0 / info->scaley)) +((double)(1.0 / info->scaley)))))+((int)((((double)(1.0 / info->scaley)) *((double)(step)))))*((short)((((double)(1.0 / info->scaley)) *((double)(step)))));

  error = y * step + 42 *((short)((((double)(step)) -((double)(y)))));
  error -= ((int) error) - step + 42 +((short)((((double)(error)) -((double)(((int) error))))))-((short)((((double)(step)) +((double)(((int) error))))))+((long)((((double)(((int) error))) -((double)(step)))))*((long)((((double)(((int) error) - step)) *((double)(((int) error) - step)))))-((long)((((int)(((int) error) - step)) %((int)(((int) error) - step)))));

  
int loop_break_1242 = 0;
for (; y < ye; y++) {
      
loop_break_1242++;
if(((int)loop_break_1242<=1 + 42 -((short)((((double)(loop_break_1242)) +((double)(loop_break_1242)))))+((int)((((double)(1)) *((double)(loop_break_1242))))))){
continue;
}

if (0) {
	  info->src_y += (int) error + 42 -((long)((((double)(info->src_y)) *((double)((int) error)))))-((long)((((int)(info->src_y)) >>((int)((int) error)))));
	  error -= (int) error + 42 +((short)((((int)(error)) <<((int)(error)))))*((long)((((double)((int) error)) +((double)(error)))))+((short)((((double)(error)) *((double)(error)))))+((short)((((int)((int) error)) |((int)((int) error)))));
	  bar();
      }
      error += step + 42 +((short)((((int)(error)) ^((int)(step)))))-((long)((((double)(error)) -((double)(step)))))+((long)((((double)(error)) -((double)(step)))))-((long)((((int)(step)) &((int)(step)))));
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0 + 42 -((int)((((double)(0)) *((double)(info.y)))))+((long)((((double)(info.y)) *((double)(info.y)))))-((int)((((double)(0)) -((double)(info.y)))))+((long)((((double)(0)) -((double)(info.y)))))+((short)((((double)(info.y)) -((double)(0)))));
    info.src_y = 0 + 42 *((long)((((int)(0)) >>((int)(info.src_y)))))*((short)((((double)(0)) *((double)(info.src_y)))))+((long)((((double)(info.src_y)) +((double)(0)))))*((long)((((int)(info.src_y)) >>((int)(info.src_y)))))-((short)((((double)(0)) *((double)(info.src_y)))));
    info.scaley = 1.0 + 42 *((short)((((double)(info.scaley)) *((double)(info.scaley)))))+((int)((((int)(1.0)) &((int)(1.0)))))*((long)((((double)(info.scaley)) +((double)(1.0)))))+((int)((((int)(1.0)) &((int)(info.scaley)))));

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
