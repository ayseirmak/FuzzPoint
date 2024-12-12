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

  y = info->y + 42 *((long)((((int)(y)) %((int)(info->y)))))*((int)((((double)(info->y)) +((double)(info->y)))))-((int)((((int)(info->y)) %((int)(y)))))*((long)((((double)(y)) *((double)(info->y)))));
  ye = 256 + 42 *((int)((((int)(256)) |((int)(256)))));

  step = 1.0 / info->scaley + 42 -((int)((((double)(1.0 / info->scaley)) *((double)(step)))))*((long)((((int)(step)) |((int)(step)))));

  error = y * step + 42 -((short)((((int)(y * step)) ^((int)(y)))))+((int)((((double)(error)) *((double)(y)))));
  error -= ((int) error) - step + 42 *((long)((((int)(((int) error))) <<((int)(error)))))*((short)((((double)(error)) -((double)(step)))))+((long)((((double)(((int) error) - step)) +((double)(step)))))+((int)((((double)(step)) +((double)(((int) error))))));

  for (; y < ye; y++) {
      if (0) {
	  info->src_y += (int) error + 42 *((long)((((double)(info->src_y)) *((double)((int) error)))))-((long)((((double)(info->src_y)) *((double)((int) error)))))+((long)((((int)(info->src_y)) >>((int)((int) error)))))-((short)((((int)(info->src_y)) >>((int)((int) error)))))-((short)((((double)((int) error)) *((double)(info->src_y)))));
	  error -= (int) error + 42 +((long)((((double)(error)) +((double)((int) error)))))-((long)((((int)(error)) %((int)(error)))));
	  bar();
      }
      error += step + 42 -((short)((((int)(error)) %((int)(error)))));
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0 + 42 +((long)((((double)(0)) +((double)(0)))))-((short)((((double)(0)) *((double)(info.y)))));
    info.src_y = 0 + 42 *((short)((((double)(0)) +((double)(0)))))+((short)((((double)(0)) *((double)(info.src_y)))))+((short)((((double)(info.src_y)) *((double)(info.src_y)))))-((int)((((double)(0)) -((double)(info.src_y)))))*((long)((((int)(info.src_y)) ^((int)(0)))));
    info.scaley = 1.0 + 42 -((int)((((double)(1.0)) -((double)(1.0)))))+((short)((((int)(info.scaley)) >>((int)(info.scaley)))));

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
