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

  y = info->y + 42 *((short)((((double)(info->y)) +((double)(info->y)))))-((short)((((int)(info->y)) |((int)(y)))))-((long)((((int)(info->y)) |((int)(info->y)))))*((long)((((int)(info->y)) &((int)(info->y)))))*((int)((((double)(y)) -((double)(info->y)))));
  ye = 256 + 42 *((int)((((double)(256)) +((double)(256)))));

  step = 1.0 / info->scaley + 42 -((long)((((int)(1.0 / info->scaley)) %((int)(1.0 / info->scaley)))))+((int)((((double)(1.0 / info->scaley)) +((double)(step)))))*((int)((((int)(step)) ^((int)(1.0 / info->scaley)))))+((long)((((double)(1.0 / info->scaley)) -((double)(1.0 / info->scaley)))));

  error = y * step + 42 -((long)((((double)(error)) *((double)(step)))))+((short)((((double)(step)) +((double)(error)))))-((int)((((int)(y * step)) <<((int)(y * step)))));
  error -= ((int) error) - step + 42 -((long)((((double)(step)) -((double)(step)))))*((long)((((int)(error)) |((int)(((int) error))))))*((long)((((double)(((int) error))) -((double)(((int) error))))))+((long)((((int)(((int) error) - step)) <<((int)(error)))))-((int)((((double)(step)) +((double)(error)))));

  for (; y < ye; y++) {
      if (0) {
	  info->src_y += (int) error + 42 +((long)((((double)(info->src_y)) -((double)((int) error)))))-((short)((((int)(info->src_y)) &((int)((int) error)))));
	  error -= (int) error + 42 +((short)((((int)(error)) %((int)((int) error)))))*((short)((((double)((int) error)) *((double)(error)))))*((short)((((double)(error)) +((double)(error)))));
	  bar();
      }
      error += step + 42 *((int)((((double)(step)) *((double)(step)))));
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0 + 42 *((long)((((double)(0)) *((double)(info.y)))))*((long)((((double)(0)) +((double)(0)))))*((int)((((int)(0)) &((int)(0)))));
    info.src_y = 0 + 42 *((short)((((double)(0)) +((double)(info.src_y)))));
    info.scaley = 1.0 + 42 -((long)((((int)(1.0)) >>((int)(info.scaley)))))-((long)((((double)(info.scaley)) +((double)(info.scaley)))))+((long)((((double)(info.scaley)) -((double)(info.scaley)))))-((long)((((double)(1.0)) +((double)(1.0)))))*((short)((((int)(1.0)) &((int)(1.0)))));

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
