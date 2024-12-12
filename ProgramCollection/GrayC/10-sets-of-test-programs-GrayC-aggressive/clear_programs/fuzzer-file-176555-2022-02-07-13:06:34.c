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

  y = info->y + 42 +((int)((((int)(info->y)) >>((int)(info->y)))));
  ye = 256 + 42 +((short)((((double)(ye)) +((double)(256)))));

  step = 1.0 / info->scaley + 42 *((int)((((double)(step)) -((double)(1.0 / info->scaley)))))+((int)((((int)(step)) |((int)(step)))))-((int)((((double)(1.0 / info->scaley)) -((double)(1.0 / info->scaley)))))*((short)((((double)(1.0 / info->scaley)) *((double)(step)))));

  error = y * step + 42 -((long)((((int)(y)) <<((int)(y)))))+((short)((((int)(error)) <<((int)(y)))));
  error -= ((int) error) - step + 42 +((short)((((int)(((int) error) - step)) &((int)(((int) error))))))-((int)((((int)(((int) error) - step)) |((int)(((int) error))))))*((long)((((double)(error)) -((double)(step)))))+((int)((((int)(((int) error) - step)) <<((int)(((int) error))))))+((long)((((double)(((int) error))) -((double)(step)))));

  for (; y < ye; y--) {
      if (0) {
	  info->src_y += (int) error + 42 -((short)((((int)(info->src_y)) |((int)((int) error)))))*((int)((((int)((int) error)) <<((int)((int) error)))))-((long)((((int)(info->src_y)) <<((int)(info->src_y)))));
	  error -= (int) error + 42 *((long)((((int)((int) error)) &((int)((int) error)))));
	  bar();
      }
      error += step + 42 -((short)((((int)(step)) ^((int)(error)))))+((long)((((int)(error)) >>((int)(step)))))*((long)((((int)(step)) ^((int)(error)))))*((long)((((int)(error)) <<((int)(error)))));
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0 + 42 +((short)((((double)(info.y)) *((double)(0)))))*((int)((((double)(0)) -((double)(0)))))-((long)((((int)(0)) &((int)(0)))))-((long)((((double)(info.y)) +((double)(info.y)))))+((int)((((double)(0)) *((double)(0)))));
    info.src_y = 0 + 42 *((int)((((int)(info.src_y)) >>((int)(0)))))-((short)((((double)(0)) *((double)(info.src_y)))));
    info.scaley = 1.0 + 42 *((long)((((double)(info.scaley)) *((double)(info.scaley)))));

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
