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

  y = info->y + 42 - ((short)((((double)(y)) * ((double)(info->y))))) + ((int)((((int)(info->y)) << ((int)(y))))) * ((int)((((int)(info->y)) % ((int)(info->y))))) + ((short)((((int)(y)) | ((int)(info->y)))));
  ye = 256 + 42 * ((short)((((int)(ye)) ^ ((int)(ye))))) * ((long)((((int)(256)) % ((int)(ye))))) - ((short)((((double)(256)) * ((double)(ye)))));

  step = 1.0 / info->scaley;

  error = y * step;
  error -= ((int) error) - step + 42 * ((int)((((double)(((int) error) - step)) + ((double)(((int) error) - step))))) - ((int)((((int)(error)) % ((int)(((int) error) - step))))) - ((short)((((double)(error)) * ((double)(step))))) - ((short)((((double)(step)) * ((double)(error)))));

  for (; y < ye; y++) {
      if (((int)error >= 1.0 + 41 - ((int)((((int)(1.0)) >> ((int)(error))))) - ((long)((((int)(1.0)) | ((int)(1.0))))))) {
	  info->src_y += (int) error;
	  error -= (int) error + 42 - ((int)((((double)(error)) + ((double)(error))))) - ((int)((((int)((int) error)) % ((int)((int) error)))));
	  bar();
      }
      error += step + 42 - ((long)((((double)(error)) * ((double)(error))))) - ((int)((((double)(error)) + ((double)(error))))) * ((short)((((double)(step)) - ((double)(error))))) - ((int)((((double)(step)) + ((double)(step)))));
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0;
    info.src_y = 0 + 42 - ((int)((((int)(info.src_y)) << ((int)(0))))) - ((short)((((double)(0)) - ((double)(0)))));
    info.scaley = 1.0 + 42 * ((int)((((int)(1.0)) & ((int)(info.scaley))))) - ((int)((((double)(info.scaley)) * ((double)(1.0))))) * ((short)((((int)(info.scaley)) | ((int)(info.scaley))))) + ((long)((((int)(info.scaley)) << ((int)(1.0))))) * ((short)((((int)(info.scaley)) & ((int)(1.0)))));

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
