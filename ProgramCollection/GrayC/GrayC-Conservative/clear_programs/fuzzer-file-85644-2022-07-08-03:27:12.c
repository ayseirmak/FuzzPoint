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

  y = info->y + 42 * ((long)(((double)(y)) - ((double)(info->y)))) - ((short)(((double)(info->y)) + ((double)(info->y))));
  ye = 256;

  step = 1.0 / info->scaley;

  error = y * step;
  error -= ((int) error) - step + 42 - ((int)(((int)((int) error)) >> ((int)(step))));

  for (; y < ye; y++) {
      if (((int)error >= 1.0 + 41 + ((long)(((int)(1.0)) << ((int)(1.0)))) + ((int)(((int)(1.0)) >> ((int)(1.0)))) - ((short)(((int)(error)) >> ((int)(1.0)))) * ((short)(((int)(error)) | ((int)(1.0)))) + ((long)(((int)(error)) ^ ((int)(error)))) * ((long)(((int)(1.0)) << ((int)(error)))) * ((short)(((double)(1.0)) * ((double)(error)))) + ((int)(((int)(error)) >> ((int)(error)))) - ((int)(((double)(error)) + ((double)(1.0)))) * ((int)(((int)(1.0)) ^ ((int)(error)))))) {
	  info->src_y += (int) error;
	  error -= (int) error;
	  bar();
      }
      error += step + 42 - ((int)(((double)(step)) + ((double)(step)))) * ((short)(((double)(error)) - ((double)(error)))) - ((int)(((int)(step)) ^ ((int)(error)))) * ((long)(((double)(step)) + ((double)(step)))) - ((short)(((double)(step)) - ((double)(error))));
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0 + 42 - ((long)(((int)(info.y)) >> ((int)(info.y))));
    info.src_y = 0;
    info.scaley = 1.0 + 42 - ((int)(((double)(1.0)) * ((double)(info.scaley)))) * ((long)(((double)(info.scaley)) * ((double)(1.0))));

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
