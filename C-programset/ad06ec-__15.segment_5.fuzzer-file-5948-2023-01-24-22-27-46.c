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

  error = y * step;
  error -= ((int) error) - step + 42 - ((long)((((double)(step)) - ((double)(((int) error))))));

  for (; y < ye; y++) {
      if (0) {
	  info->src_y += (int) error + 42 * ((long)((((int)((int) error)) ^ ((int)((int) error))))) + ((short)((((int)(info->src_y)) & ((int)(info->src_y))))) - ((int)((((int)(info->src_y)) << ((int)(info->src_y))))) - ((long)((((double)(info->src_y)) - ((double)(info->src_y)))));
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

    info.y = 0;
    info.src_y = 0 + 42 * ((short)((((int)(0)) << ((int)(0))))) * ((short)((((double)(0)) * ((double)(info.src_y))))) - ((long)((((double)(0)) * ((double)(info.src_y)))));
    info.scaley = 1.0 + 42 + ((long)((((int)(1.0)) ^ ((int)(1.0))))) + ((long)((((int)(info.scaley)) | ((int)(1.0))))) - ((short)((((double)(1.0)) + ((double)(1.0))))) * ((long)((((double)(info.scaley)) * ((double)(1.0))))) + ((short)((((int)(1.0)) | ((int)(1.0)))));

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
