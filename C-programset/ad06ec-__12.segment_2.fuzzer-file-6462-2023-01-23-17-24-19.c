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

  step = 1.0 / info->scaley;

  error = y * step + 42 - ((int)((((int)(step)) >> ((int)(y * step))))) + ((int)((((int)(y)) >> ((int)(y * step))))) - ((long)((((int)(y * step)) ^ ((int)(error))))) + ((long)((((double)(step)) * ((double)(error))))) * ((short)((((int)(y * step)) % ((int)(error)))));
  error -= ((int) error) - step;

  for (; y < ye; y++) {
      if (0) {
	  info->src_y += (int) error;
	  error -= (int) error + 42 * ((int)((((double)((int) error)) * ((double)((int) error))))) - ((short)((((double)((int) error)) * ((double)(error)))));
	  bar();
      }
      error += step;
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0 + 42 * ((int)((((double)(info.y)) * ((double)(info.y)))));
    info.src_y = 0;
    info.scaley = 1.0 + 42 * ((int)((((int)(1.0)) | ((int)(1.0))))) + ((short)((((int)(1.0)) & ((int)(1.0))))) * ((int)((((double)(info.scaley)) + ((double)(info.scaley)))));

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
