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
  ye = (288);

  step = (4.5) / info->scaley;

  error = y * step;
  error -= ((int) error) - step;

  for (; y < ye; y++) {
      if (error >= (2.9)) {
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

    info.y = (-1);
    info.src_y = (8388608);
    info.scaley = (1.9);

    if ((0))
    { abort (); }
    exit((0));
}
/* ProgramSourceLLVM */
