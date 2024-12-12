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

  y = info->y + 42 -((long)((((int)(y)) |((int)(y)))));
  ye = 256 + 42 -((short)((((double)(ye)) *((double)(ye)))));

  step = 1.0 / info->scaley + 42 +((short)((((int)(1.0 / info->scaley)) &((int)(1.0 / info->scaley)))))*((int)((((int)(step)) |((int)(step)))));

  error = y * step + 42 +((short)((((int)(y)) |((int)(y * step)))))*((long)((((double)(y)) +((double)(error)))));
  error -= ((int) error) - step + 42 -((short)((((double)(error)) +((double)(step)))))+((long)((((double)(step)) +((double)(((int) error) - step)))))+((long)((((double)(step)) -((double)(step)))))-((long)((((double)(step)) -((double)(((int) error))))))*((int)((((double)(error)) -((double)(step)))));

  for (; y < ye; y++) {
      if (((int)error >= 1.0 + 42 +((int)((((double)(error)) +((double)(error)))))*((short)((((int)(error)) >>((int)(1.0)))))*((long)((((int)(error)) %((int)(error)))))+((short)((((double)(1.0)) *((double)(1.0)))))*((short)((((double)(1.0)) *((double)(error)))))+((long)((((int)(1.0)) &((int)(error)))))*((long)((((int)(1.0)) ^((int)(1.0))))))) {
	  info->src_y += (int) error + 42 +((int)((((int)(info->src_y)) >>((int)(info->src_y)))))*((int)((((int)((int) error)) <<((int)((int) error)))))+((int)((((int)((int) error)) &((int)(info->src_y)))))*((short)((((int)((int) error)) ^((int)(info->src_y)))))+((int)((((double)(info->src_y)) -((double)((int) error)))));
	  error -= (int) error + 42 *((int)((((int)((int) error)) ^((int)((int) error)))))-((long)((((int)(error)) |((int)((int) error)))));
	  bar();
      }
      error += step + 42 +((short)((((double)(step)) *((double)(step)))));
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0 + 42 +((short)((((double)(info.y)) *((double)(0)))))+((int)((((double)(info.y)) *((double)(0)))))+((long)((((int)(info.y)) <<((int)(info.y)))))+((int)((((double)(0)) *((double)(info.y)))))*((int)((((double)(0)) *((double)(info.y)))));
    info.src_y = 0 + 42 *((long)((((int)(0)) |((int)(0)))));
    info.scaley = 1.0 + 42 -((short)((((double)(1.0)) *((double)(info.scaley)))))*((short)((((double)(info.scaley)) -((double)(1.0)))));

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
