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

  y = info->y + 42 * ((int)((((double)(y)) - ((double)(y))))) + ((int)((((double)(y)) - ((double)(info->y)))));
  ye = 256;

  step = 1.0 / info->scaley + 42 - ((int)((((int)(1.0 / info->scaley)) ^ ((int)(step)))));

  error = y * step;
  error -= ((int) error) - step;

  for (; y < ye; y++) {
      if (((int)error >= 1.0 + 41 - ((int)((((double)(error)) + ((double)(1.0))))) + ((short)((((double)(error)) * ((double)(error))))) - ((short)((((int)(error)) | ((int)(error))))) - ((long)((((int)(1.0)) << ((int)(error))))) * ((int)((((double)(error)) * ((double)(error))))) - ((int)((((double)(1.0)) + ((double)(error))))))) {
	  info->src_y += (int) error + 42 - ((short)((((int)(info->src_y)) & ((int)(info->src_y))))) * ((short)((((double)(info->src_y)) - ((double)(info->src_y)))));
	  error -= (int) error + 42 * ((int)((((double)(error)) + ((double)(error))))) * ((long)((((double)(error)) * ((double)(error))))) + ((int)((((int)((int) error)) >> ((int)((int) error)))));
	  bar();
      }
      error += step + 42 - ((short)((((int)(error)) ^ ((int)(step))))) * ((short)((((int)(step)) | ((int)(error))))) + ((long)((((double)(error)) * ((double)(step))))) + ((long)((((int)(error)) % ((int)(step))))) * ((long)((((double)(error)) * ((double)(error)))));
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0;
    info.src_y = 0 + 42 + ((int)((((double)(0)) + ((double)(info.src_y)))));
    info.scaley = 1.0 + 42 - ((short)((((double)(1.0)) * ((double)(info.scaley))))) - ((short)((((int)(info.scaley)) << ((int)(1.0)))));

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
