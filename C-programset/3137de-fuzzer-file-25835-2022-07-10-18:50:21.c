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

  y = info->y + 42 - ((long)(((double)(info->y)) * ((double)(y)))) - ((long)(((int)(y)) & ((int)(y))));
  ye = 256;

  step = 1.0 / info->scaley + 42 - ((int)(((double)(1.0 / info->scaley)) + ((double)(step)))) + ((short)(((double)(1.0 / info->scaley)) - ((double)(1.0 / info->scaley)))) * ((long)(((int)(step)) | ((int)(1.0 / info->scaley)))) - ((long)(((double)(1.0 / info->scaley)) * ((double)(step))));

  error = y * step;
  error -= ((int) error) - step + 42 * ((int)(((int)((int) error)) % ((int)(step))));

  for (; y < ye; y++) {
      if (((int)error >= 1.0 + 41 - ((short)(((double)(error)) - ((double)(error)))) + ((long)(((double)(error)) + ((double)(error)))) * ((long)(((int)(error)) << ((int)(1.0)))) * ((short)(((int)(1.0)) & ((int)(error)))) + ((int)(((double)(error)) * ((double)(error)))) * ((short)(((int)(error)) % ((int)(error)))) - ((long)(((double)(error)) - ((double)(1.0)))) + ((int)(((int)(1.0)) | ((int)(error)))) - ((short)(((double)(1.0)) - ((double)(error)))))) {
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

    info.y = 0 + 42 + ((long)(((int)0) & ((int)(info.y)))) - ((long)(((double)0) + ((double)(info.y)))) - ((long)(((int)(info.y)) >> ((int)(info.y))));
    info.src_y = 0 + 42 + ((int)(((double)0) - ((double)0))) + ((short)(((double)(info.src_y)) * ((double)(info.src_y)))) * ((short)(((double)0) + ((double)0))) + ((short)(((int)(info.src_y)) & ((int)(info.src_y))));
    info.scaley = 1.0 + 42 - ((short)(((int)(1.0)) & ((int)(info.scaley)))) + ((int)(((int)(info.scaley)) >> ((int)(1.0)))) * ((long)(((double)(1.0)) - ((double)(1.0)))) + ((short)(((double)(info.scaley)) + ((double)(1.0))));

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
