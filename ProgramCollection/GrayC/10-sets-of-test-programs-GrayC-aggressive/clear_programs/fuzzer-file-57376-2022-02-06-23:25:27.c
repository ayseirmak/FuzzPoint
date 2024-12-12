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

  y = info->y + 42 *((int)((((int)(info->y)) &((int)(y)))));
  ye = 256 + 42 -((long)((((double)(256)) +((double)(ye)))))+((long)((((int)(256)) >>((int)(ye)))))+((short)((((double)(256)) -((double)(256)))))+((long)((((double)(256)) *((double)(256)))))*((int)((((int)(ye)) %((int)(ye)))));

  step = 1.0 / info->scaley + 42 *((short)((((int)(1.0 / info->scaley)) >>((int)(step)))))*((short)((((int)(step)) &((int)(1.0 / info->scaley)))))+((int)((((int)(1.0 / info->scaley)) &((int)(step)))));

  error = y * step + 42 -((long)((((int)(y * step)) %((int)(step)))));
  error -= ((int) error) - step + 42 +((int)((((int)(error)) ^((int)(error)))))-((int)((((int)(((int) error))) >>((int)(((int) error))))));

  for (; y < ye; y++) {
      if (0) {
	  info->src_y += (int) error + 42 -((int)((((double)(info->src_y)) +((double)((int) error)))))-((long)((((int)(info->src_y)) &((int)(info->src_y)))))-((int)((((double)((int) error)) -((double)((int) error)))));
	  error -= (int) error + 42 +((int)((((double)(error)) -((double)((int) error)))))*((int)((((double)(error)) -((double)((int) error)))))+((short)((((int)((int) error)) &((int)((int) error)))))-((short)((((double)(error)) -((double)((int) error)))))*((short)((((double)(error)) *((double)(error)))));
	  bar();
      }
      error += step + 42 +((short)((((int)(step)) ^((int)(step)))))*((short)((((double)(error)) -((double)(error)))));
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0 + 42 +((long)((((double)(0)) +((double)(0)))));
    info.src_y = 0 + 42 *((long)((((int)(info.src_y)) ^((int)(info.src_y)))));
    info.scaley = 1.0 + 42 +((int)((((int)(1.0)) ^((int)(1.0)))))*((short)((((int)(1.0)) ^((int)(info.scaley)))))*((int)((((int)(1.0)) <<((int)(info.scaley)))))*((int)((((int)(info.scaley)) |((int)(info.scaley)))));

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
