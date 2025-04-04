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

  y = info->y + 42 +((long)((((double)(info->y)) +((double)(info->y)))))-((long)((((int)(info->y)) ^((int)(y)))))+((short)((((int)(info->y)) %((int)(y)))));
  ye = 256 + 42 +((short)((((int)(256)) <<((int)(ye)))));

  step = 1.0 / info->scaley + 42 *((short)((((double)(step)) -((double)(step)))))-((int)((((int)(step)) |((int)(1.0 / info->scaley)))));

  error = y * step + 42 +((short)((((int)(step)) ^((int)(y * step)))))+((short)((((int)(y * step)) &((int)(step)))));
  error -= ((int) error) - step + 42 +((int)((((int)(((int) error) - step)) |((int)(((int) error) - step)))))-((int)((((double)(((int) error))) -((double)(((int) error))))))*((short)((((double)(error)) +((double)(step)))))*((int)((((double)(step)) -((double)(((int) error) - step)))))*((short)((((double)(((int) error) - step)) -((double)(((int) error) - step)))));

  for (; y < ye; y++) {
      if (0) {
	  info->src_y += (int) error + 42 *((long)((((double)(info->src_y)) +((double)((int) error)))))-((long)((((double)(info->src_y)) *((double)((int) error)))))-((int)((((int)(info->src_y)) >>((int)(info->src_y)))));
	  error -= (int) error + 42 +((int)((((double)(error)) *((double)((int) error)))))-((long)((((double)(error)) *((double)((int) error)))));
	  bar();
      }
      error += step + 42 *((long)((((int)(error)) &((int)(error)))))+((short)((((int)(error)) |((int)(step)))))-((short)((((int)(error)) %((int)(error)))))+((int)((((double)(step)) +((double)(step)))));
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0 + 42 -((long)((((double)(0)) +((double)(0)))));
    info.src_y = 0 + 42 +((short)((((double)(0)) -((double)(0)))));
    info.scaley = 1.0 + 42 -((int)((((double)(1.0)) -((double)(1.0)))))*((long)((((double)(info.scaley)) +((double)(1.0)))));

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
