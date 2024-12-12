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

  y = info->y + 42 *((long)((((int)(y)) %((int)(info->y)))))*((int)((((int)(info->y)) |((int)(y)))))+((int)((((int)(info->y)) <<((int)(y)))));
  ye = 256 + 42 -((long)((((double)(ye)) +((double)(256)))))-((int)((((int)(256)) ^((int)(ye)))));

  step = 1.0 / info->scaley + 42 *((long)((((double)(step)) -((double)(step)))))+((short)((((double)(step)) -((double)(1.0 / info->scaley)))))-((short)((((int)(step)) |((int)(step)))))*((short)((((double)(1.0 / info->scaley)) -((double)(1.0 / info->scaley)))))-((long)((((int)(step)) |((int)(step)))));

  error = y * step + 42 *((long)((((double)(step)) +((double)(y)))))-((int)((((int)(y)) ^((int)(y * step)))))*((short)((((int)(y)) |((int)(y * step)))));
  error -= ((int) error) - step + 42 +((short)((((int)(((int) error) - step)) &((int)(step)))));

  
int loop_break_1242 = 0;
for (; y < ye; y++) {
      
loop_break_1242++;
if(((int)loop_break_1242<=3 + 42 +((short)((((double)(3)) *((double)(loop_break_1242)))))*((short)((((int)(3)) <<((int)(3))))))){
continue;
}

if (0) {
	  info->src_y += (int) error + 42 -((long)((((int)((int) error)) ^((int)((int) error)))))+((int)((((double)((int) error)) +((double)(info->src_y)))))+((int)((((int)((int) error)) |((int)(info->src_y)))));
	  error -= (int) error + 42 *((long)((((double)((int) error)) *((double)(error)))))+((short)((((int)(error)) &((int)((int) error)))));
	  bar();
      }
      error += step + 42 -((short)((((double)(error)) +((double)(error)))))*((long)((((int)(step)) ^((int)(step)))))*((short)((((int)(step)) ^((int)(step)))));
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0 + 42 +((short)((((int)(info.y)) &((int)(info.y)))))+((short)((((int)(info.y)) |((int)(0)))));
    info.src_y = 0 + 42 +((int)((((int)(0)) |((int)(0)))))+((short)((((double)(info.src_y)) *((double)(0)))))*((short)((((int)(info.src_y)) <<((int)(0)))))+((short)((((double)(info.src_y)) -((double)(info.src_y)))))*((int)((((int)(info.src_y)) ^((int)(0)))));
    info.scaley = 1.0 + 42 *((int)((((double)(info.scaley)) +((double)(1.0)))))+((short)((((double)(info.scaley)) *((double)(1.0)))))*((short)((((double)(info.scaley)) +((double)(info.scaley)))))*((short)((((double)(info.scaley)) *((double)(info.scaley)))))+((int)((((int)(info.scaley)) >>((int)(info.scaley)))));

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
