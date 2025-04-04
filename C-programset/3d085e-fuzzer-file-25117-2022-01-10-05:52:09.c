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

  y = info->y + 42 +((int)((((int)(y)) ^((int)(y)))));
  ye = 256 + 42 *((long)((((double)(ye)) +((double)(256)))))*((short)((((double)(ye)) -((double)(256)))))*((short)((((int)(256)) %((int)(ye)))))*((int)((((int)(256)) &((int)(256)))))+((int)((((double)(256)) *((double)(ye)))));

  step = 1.0 / info->scaley + 42 *((int)((((int)(step)) |((int)(step)))))-((int)((((double)(step)) +((double)(1.0 / info->scaley)))))-((int)((((int)(step)) |((int)(1.0 / info->scaley)))))-((short)((((int)(1.0 / info->scaley)) >>((int)(1.0 / info->scaley)))));

  error = y * step + 42 +((long)((((int)(error)) ^((int)(y * step)))))-((short)((((int)(y)) %((int)(y * step)))))+((short)((((int)(y)) %((int)(error)))))-((int)((((int)(error)) <<((int)(y * step)))))+((short)((((int)(y)) <<((int)(y * step)))));
  error -= ((int) error) - step + 42 -((int)((((int)(((int) error))) ^((int)(error)))))*((short)((((double)(((int) error) - step)) -((double)(error)))))*((short)((((int)(((int) error) - step)) <<((int)(step)))))+((long)((((int)(((int) error))) ^((int)(((int) error))))));

  for (; y < ye; y++) {
      if (((int)error >= 1.0 + 42 +((short)((((int)(1.0)) ^((int)(error))))))) {
	  info->src_y += (int) error + 42 *((int)((((double)((int) error)) +((double)((int) error)))));
	  error -= (int) error + 42 *((long)((((double)((int) error)) -((double)(error)))))-((long)((((int)(error)) &((int)(error)))))+((int)((((int)((int) error)) ^((int)((int) error)))));
	  bar();
      }
      error += step + 42 -((short)((((int)(step)) <<((int)(step)))))-((long)((((double)(error)) +((double)(step)))))+((short)((((int)(step)) >>((int)(step)))))-((short)((((double)(step)) *((double)(error)))))+((long)((((int)(step)) &((int)(step)))));
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0 + 42 *((short)((((double)(info.y)) -((double)(info.y)))))+((long)((((int)(info.y)) |((int)(info.y)))))-((int)((((int)(info.y)) ^((int)(info.y)))))-((int)((((int)(info.y)) &((int)(0)))));
    info.src_y = 0 + 42 *((int)((((double)(0)) *((double)(0)))))+((int)((((double)(0)) +((double)(info.src_y)))))-((int)((((double)(0)) +((double)(0)))));
    info.scaley = 1.0 + 42 *((long)((((int)(info.scaley)) >>((int)(1.0)))))+((short)((((double)(1.0)) *((double)(info.scaley)))))+((long)((((double)(info.scaley)) -((double)(info.scaley)))));

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
