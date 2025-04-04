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

  y = info->y + 42 -((int)((((double)(y)) *((double)(info->y)))))*((short)((((int)(info->y)) <<((int)(info->y)))))+((long)((((double)(info->y)) *((double)(y)))));
  ye = 256 + 42 +((short)((((double)(256)) +((double)(ye)))))*((int)((((int)(256)) |((int)(ye)))))+((short)((((int)(256)) &((int)(ye)))));

  step = 1.0 / info->scaley + 42 -((int)((((int)(step)) <<((int)(step)))))+((int)((((int)(step)) &((int)(1.0 / info->scaley)))))+((short)((((int)(1.0 / info->scaley)) |((int)(step)))))*((short)((((int)(1.0 / info->scaley)) >>((int)(1.0 / info->scaley)))))*((int)((((double)(1.0 / info->scaley)) *((double)(step)))));

  error = y * step + 42 -((long)((((int)(y)) |((int)(y * step)))))*((short)((((int)(error)) >>((int)(step)))));
  error -= ((int) error) - step + 42 -((long)((((double)(step)) -((double)(((int) error))))))+((short)((((int)(error)) >>((int)(((int) error))))))+((int)((((int)(((int) error) - step)) |((int)(error)))))-((int)((((int)(error)) |((int)(((int) error))))));

  for (; y < ye; y++) {
      if (0) {
	  info->src_y += (int) error + 42 +((long)((((double)(info->src_y)) *((double)((int) error)))))-((int)((((int)((int) error)) &((int)((int) error)))));
	  error -= (int) error + 42 -((int)((((double)(error)) +((double)((int) error)))))*((int)((((double)((int) error)) *((double)((int) error)))));
	  bar();
      }
      error += step + 42 +((short)((((int)(error)) |((int)(error)))))-((int)((((int)(error)) &((int)(error)))))*((long)((((int)(step)) &((int)(error)))))-((short)((((double)(step)) *((double)(error)))));
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0 + 42 *((short)((((int)(0)) &((int)(0)))))-((long)((((int)(0)) >>((int)(0)))))*((short)((((double)(0)) +((double)(info.y)))))+((long)((((int)(info.y)) |((int)(info.y)))))*((long)((((double)(0)) +((double)(0)))));
    info.src_y = 0 + 42 *((long)((((double)(info.src_y)) +((double)(info.src_y)))));
    info.scaley = 1.0 + 42 *((short)((((int)(info.scaley)) &((int)(1.0)))));

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
