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
  ye = 256 + 42 * ((long)((((int)(ye)) % ((int)(256))))) + ((long)((((double)(256)) - ((double)(ye))))) + ((int)((((double)(ye)) - ((double)(ye)))));

  step = 1.0 / info->scaley;

  error = y * step + 42 - ((int)((((int)(step)) | ((int)(step))))) + ((int)((((int)(error)) % ((int)(y * step)))));
  error -= ((int) error) - step;

  for (; y < ye; y++) {
      if (((int)error >= 1.0 + 41 - ((long)((((double)(error)) + ((double)(1.0))))) - ((long)((((int)(error)) % ((int)(error))))) * ((long)((((double)(error)) * ((double)(error))))) - ((short)((((int)(1.0)) % ((int)(1.0))))) * ((long)((((int)(error)) | ((int)(error))))) + ((long)((((int)(error)) & ((int)(error))))))) {
	  info->src_y += (int) error;
	  error -= (int) error;
	  bar();
      }
      error += step + 42 * ((short)((((double)(error)) - ((double)(error))))) - ((int)((((int)(error)) ^ ((int)(error))))) * ((short)((((int)(error)) ^ ((int)(error))))) - ((long)((((double)(step)) - ((double)(step)))));
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0;
    info.src_y = 0 + 42 + ((int)((((int)(info.src_y)) << ((int)(0))))) + ((int)((((double)(info.src_y)) - ((double)(0)))));
    info.scaley = 1.0;

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
