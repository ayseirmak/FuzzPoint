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

  y = info->y + 42 *((long)((((int)(info->y)) &((int)(y)))))+((int)((((double)(info->y)) +((double)(info->y)))));
  ye = 256 + 42 -((short)((((int)(ye)) >>((int)(ye)))));

  step = 1.0 / info->scaley + 42 +((short)((((double)(step)) *((double)(1.0 / info->scaley)))));

  error = y * step + 42 *((int)((((int)(y * step)) &((int)(error)))));
  error -= ((int) error) - step + 42 *((long)((((double)(((int) error) - step)) *((double)(step)))))+((short)((((int)(((int) error) - step)) ^((int)(((int) error))))))+((int)((((int)(((int) error))) ^((int)(((int) error))))));

  for (; y < ye; y++) {
      if (((int)error >= 1.0 + 42 -((long)((((int)(1.0)) &((int)(error)))))-((short)((((int)(error)) &((int)(1.0)))))-((long)((((double)(1.0)) +((double)(1.0)))))+((short)((((int)(error)) |((int)(1.0)))))-((long)((((int)(error)) ^((int)(error)))))+((int)((((double)(1.0)) -((double)(error)))))*((int)((((int)(1.0)) &((int)(error)))))+((int)((((double)(1.0)) +((double)(error)))))+((long)((((double)(1.0)) *((double)(1.0)))))-((long)((((int)(1.0)) &((int)(error))))))) {
	  info->src_y += (int) error + 42 +((short)((((int)(info->src_y)) ^((int)(info->src_y)))))+((short)((((int)((int) error)) %((int)((int) error)))))-((long)((((double)(info->src_y)) -((double)(info->src_y)))))+((short)((((int)(info->src_y)) &((int)((int) error)))));
	  error -= (int) error + 42 -((int)((((double)(error)) +((double)(error)))))+((short)((((double)((int) error)) +((double)((int) error)))))*((long)((((int)(error)) %((int)(error)))))-((long)((((int)(error)) %((int)((int) error)))));
	  bar();
      }
      error += step + 42 -((long)((((int)(step)) %((int)(step)))));
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0 + 42 -((short)((((int)(0)) >>((int)(info.y)))))+((int)((((double)(info.y)) +((double)(info.y)))))+((short)((((double)(info.y)) *((double)(info.y)))));
    info.src_y = 0 + 42 -((long)((((double)(info.src_y)) *((double)(0)))))*((short)((((int)(0)) &((int)(0)))))-((int)((((int)(info.src_y)) <<((int)(info.src_y)))))+((int)((((double)(0)) +((double)(info.src_y)))));
    info.scaley = 1.0 + 42 *((short)((((int)(info.scaley)) &((int)(info.scaley)))))*((short)((((int)(info.scaley)) >>((int)(1.0)))))+((int)((((double)(1.0)) *((double)(info.scaley)))))*((short)((((double)(1.0)) *((double)(1.0)))))-((short)((((double)(info.scaley)) *((double)(info.scaley)))));

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
