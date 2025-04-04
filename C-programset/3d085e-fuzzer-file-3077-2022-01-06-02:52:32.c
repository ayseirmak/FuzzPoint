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

  y = info->y + 42 -((short)((((int)(y)) ^((int)(info->y)))))+((int)((((double)(info->y)) +((double)(y)))))+((int)((((int)(y)) %((int)(y)))))+((short)((((double)(info->y)) -((double)(y)))));
  ye = 256 + 42 *((long)((((int)(ye)) ^((int)(256)))))+((short)((((double)(256)) -((double)(ye)))));

  step = 1.0 / info->scaley + 42 -((short)((((double)(1.0 / info->scaley)) +((double)(1.0 / info->scaley)))))*((long)((((double)(1.0 / info->scaley)) +((double)(1.0 / info->scaley)))))+((int)((((int)(1.0 / info->scaley)) &((int)(1.0 / info->scaley)))))-((long)((((int)(1.0 / info->scaley)) &((int)(1.0 / info->scaley)))))-((short)((((int)(step)) ^((int)(1.0 / info->scaley)))));

  error = y * step + 42 +((short)((((int)(y * step)) <<((int)(error)))))-((short)((((int)(y * step)) &((int)(y * step)))));
  error -= ((int) error) - step + 42 *((short)((((int)(((int) error))) %((int)(error)))))*((long)((((double)(error)) +((double)(((int) error) - step)))))+((long)((((int)(error)) |((int)(((int) error))))))+((short)((((double)(((int) error) - step)) -((double)(step)))));

  for (; y < ye; y++) {
      if (((int)error >= 1.0 + 42 -((int)((((int)(1.0)) |((int)(error)))))*((short)((((int)(error)) ^((int)(error)))))+((long)((((double)(error)) *((double)(error)))))*((short)((((int)(1.0)) <<((int)(1.0)))))*((short)((((int)(1.0)) <<((int)(error)))))-((long)((((double)(error)) -((double)(error))))))) {
	  info->src_y += (int) error + 42 -((int)((((double)(info->src_y)) +((double)((int) error)))))+((short)((((double)((int) error)) +((double)(info->src_y)))))+((short)((((double)(info->src_y)) +((double)(info->src_y)))))*((short)((((double)(info->src_y)) -((double)(info->src_y)))))*((int)((((double)((int) error)) +((double)((int) error)))));
	  error -= (int) error + 42 *((short)((((int)((int) error)) ^((int)((int) error)))))+((short)((((double)(error)) *((double)(error)))))-((long)((((int)(error)) ^((int)((int) error)))))+((short)((((int)((int) error)) &((int)(error)))))*((short)((((int)((int) error)) &((int)((int) error)))));
	  bar();
      }
      error += step + 42 +((long)((((double)(step)) *((double)(step)))));
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0 + 42 +((long)((((int)(0)) >>((int)(0)))))-((short)((((double)(0)) +((double)(info.y)))));
    info.src_y = 0 + 42 -((int)((((double)(info.src_y)) +((double)(0)))))-((short)((((int)(0)) ^((int)(0)))))+((int)((((double)(0)) +((double)(0)))))-((int)((((int)(info.src_y)) ^((int)(info.src_y)))));
    info.scaley = 1.0 + 42 +((long)((((double)(1.0)) +((double)(info.scaley)))))*((long)((((int)(1.0)) ^((int)(info.scaley)))))-((short)((((int)(1.0)) &((int)(1.0)))));

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
