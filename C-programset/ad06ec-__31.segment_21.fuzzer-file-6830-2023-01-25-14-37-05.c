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
  ye = 256 + 42 - ((short)((((double)(256)) * ((double)(256)))));

  step = 1.0 / info->scaley;

  error = y * step + 42 * ((int)((((double)(y)) * ((double)(step)))));
  error -= ((int) error) - step + 42 - ((int)((((int)(step)) % ((int)(error)))));

  for (; y < ye; y++) {
      if (0) {
	  info->src_y += (int) error + 42 * ((short)((((int)((int) error)) ^ ((int)(info->src_y))))) * ((long)((((double)((int) error)) - ((double)((int) error))))) * ((int)((((int)((int) error)) >> ((int)((int) error)))));
	  error -= (int) error + 42 + ((int)((((int)((int) error)) | ((int)(error)))));
	  bar();
      }
      error += step;
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0 + 42 + ((long)((((double)(0)) - ((double)(0))))) + ((short)((((double)(info.y)) - ((double)(info.y))))) - ((short)((((double)(0)) - ((double)(info.y))))) - ((int)((((double)(info.y)) + ((double)(info.y)))));
    info.src_y = 0 + 42 * ((int)((((double)(0)) + ((double)(0))))) + ((int)((((double)(info.src_y)) + ((double)(0)))));
    info.scaley = 1.0 + 42 + ((long)((((int)(info.scaley)) | ((int)(info.scaley))))) + ((short)((((double)(1.0)) * ((double)(1.0))))) * ((long)((((double)(info.scaley)) + ((double)(1.0))))) + ((short)((((int)(info.scaley)) % ((int)(1.0)))));

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
