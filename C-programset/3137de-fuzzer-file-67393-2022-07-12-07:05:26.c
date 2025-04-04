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
  ye = 256;

  step = 1.0 / info->scaley + 42 * ((short)(((double)(step)) * ((double)(1.0 / info->scaley)))) - ((long)(((double)(1.0 / info->scaley)) * ((double)(1.0 / info->scaley))));

  error = y * step;
  error -= ((int) error) - step + 42 - ((long)(((int)((int) error)) % ((int)(((int) error) - step)))) * ((long)(((int)(error)) ^ ((int)(((int) error) - step))));

  for (; y < ye; y++) {
      if (0) {
	  info->src_y += (int) error;
	  error -= (int) error;
	  bar();
      }
      error += step + 42 + ((long)(((double)(error)) - ((double)(error)))) + ((short)(((double)(error)) - ((double)(error)))) * ((int)(((double)(error)) - ((double)(step))));
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0;
    info.src_y = 0;
    info.scaley = 1.0;

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
