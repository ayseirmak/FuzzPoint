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

  y = info->y + 42 *((int)((((int)(y)) <<((int)(y)))))+((int)((((double)(y)) +((double)(y)))))-((short)((((int)(y)) ^((int)(y)))))+((long)((((double)(info->y)) *((double)(info->y)))));
  ye = 256 + 42 -((long)((((int)(ye)) |((int)(ye)))))*((int)((((double)(ye)) -((double)(ye)))))-((int)((((double)(ye)) +((double)(ye)))))-((short)((((int)(256)) |((int)(ye)))));

  step = 1.0 / info->scaley + 42 -((long)((((int)(step)) %((int)(step)))))-((short)((((double)(1.0 / info->scaley)) -((double)(1.0 / info->scaley)))))+((long)((((double)(1.0 / info->scaley)) +((double)(step)))))-((long)((((double)(1.0 / info->scaley)) -((double)(step)))));

  error = y * step + 42 -((short)((((int)(y * step)) ^((int)(y)))))-((int)((((int)(error)) <<((int)(y)))))*((short)((((int)(y * step)) >>((int)(step)))))*((short)((((int)(y * step)) <<((int)(error)))));
  error -= ((int) error) - step + 42 -((int)((((int)(step)) %((int)(error)))))*((short)((((int)(step)) &((int)(((int) error))))))-((short)((((double)(((int) error))) *((double)(((int) error) - step)))))+((long)((((int)(error)) %((int)(((int) error) - step)))));

  for (; y < ye; y++) {
      if (0) {
	  info->src_y += (int) error + 42 -((short)((((double)(info->src_y)) *((double)(info->src_y)))))*((long)((((int)(info->src_y)) %((int)(info->src_y)))));
	  error -= (int) error + 42 +((short)((((double)((int) error)) *((double)((int) error)))))*((short)((((double)((int) error)) -((double)((int) error)))));
	  bar();
      }
      error += step + 42 +((long)((((double)(step)) *((double)(step)))))+((long)((((int)(step)) ^((int)(error)))));
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0 + 42 *((int)((((double)(info.y)) +((double)(0)))));
    info.src_y = 0 + 42 -((short)((((double)(info.src_y)) *((double)(0)))))+((short)((((int)(0)) |((int)(info.src_y)))));
    info.scaley = 1.0 + 42 -((long)((((double)(info.scaley)) *((double)(1.0)))));

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
