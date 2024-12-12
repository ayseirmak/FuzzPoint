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

  y = info->y;
  ye = (384);

  step = (2.1) / info->scaley;

  error = y * step;
  error -= ((int) error) - step;

  for (; y < ye; y++) {
      if (error >= (3.6)) {
	  info->src_y += (int) error;
	  error -= (int) error;
	  bar();
      }
      error += step;
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = (0);
    info.src_y = (-1);
    info.scaley = (10.6);

    if ((0))
    { abort (); }
    exit((0));
}
/* ProgramSourceLLVM */
