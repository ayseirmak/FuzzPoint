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
  ye = (-257);

  step = (4.1) / info->scaley;

  error = y * step;
  error -= ((int) error) - step;

  for (; y < ye; y++) {
      if (0) {
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

    info.y = (0x71E7D);
    info.src_y = (0x0B54D);
    info.scaley = (10.2);

    if ((0))
    { abort (); }
    exit((0));
}
/* ProgramSourceLLVM */
