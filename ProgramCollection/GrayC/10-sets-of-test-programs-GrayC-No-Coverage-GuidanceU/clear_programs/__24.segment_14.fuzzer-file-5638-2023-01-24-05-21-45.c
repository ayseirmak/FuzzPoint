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
  ye = 256 + 42 + ((long)((((int)(ye)) | ((int)(256))))) + ((short)((((double)(ye)) * ((double)(256))))) + ((short)((((int)(ye)) << ((int)(ye))))) * ((short)((((double)(ye)) * ((double)(256))))) + 42 * ((short)((((int)(256 + 42 + ((long)((((int)(ye)) | ((int)(256))))) + ((short)((((double)(ye)) * ((double)(256))))) + ((short)((((int)(ye)) << ((int)(ye))))) * ((short)((((double)(ye)) * ((double)(256))))))) >> ((int)(256 + 42 + ((long)((((int)(ye)) | ((int)(256))))) + ((short)((((double)(ye)) * ((double)(256))))) + ((short)((((int)(ye)) << ((int)(ye))))) * ((short)((((double)(ye)) * ((double)(256)))))))))) - ((int)((((int)(256 + 42 + ((long)((((int)(ye)) | ((int)(256))))) + ((short)((((double)(ye)) * ((double)(256))))) + ((short)((((int)(ye)) << ((int)(ye))))) * ((short)((((double)(ye)) * ((double)(256))))))) & ((int)(256 + 42 + ((long)((((int)(ye)) | ((int)(256))))) + ((short)((((double)(ye)) * ((double)(256))))) + ((short)((((int)(ye)) << ((int)(ye))))) * ((short)((((double)(ye)) * ((double)(256)))))))))) * ((long)((((int)(256 + 42 + ((long)((((int)(ye)) | ((int)(256))))) + ((short)((((double)(ye)) * ((double)(256))))) + ((short)((((int)(ye)) << ((int)(ye))))) * ((short)((((double)(ye)) * ((double)(256))))))) ^ ((int)(256 + 42 + ((long)((((int)(ye)) | ((int)(256))))) + ((short)((((double)(ye)) * ((double)(256))))) + ((short)((((int)(ye)) << ((int)(ye))))) * ((short)((((double)(ye)) * ((double)(256)))))))))) * ((long)((((int)(256 + 42 + ((long)((((int)(ye)) | ((int)(256))))) + ((short)((((double)(ye)) * ((double)(256))))) + ((short)((((int)(ye)) << ((int)(ye))))) * ((short)((((double)(ye)) * ((double)(256))))))) % ((int)(256 + 42 + ((long)((((int)(ye)) | ((int)(256))))) + ((short)((((double)(ye)) * ((double)(256))))) + ((short)((((int)(ye)) << ((int)(ye))))) * ((short)((((double)(ye)) * ((double)(256)))))))))) * ((short)((((int)(256 + 42 + ((long)((((int)(ye)) | ((int)(256))))) + ((short)((((double)(ye)) * ((double)(256))))) + ((short)((((int)(ye)) << ((int)(ye))))) * ((short)((((double)(ye)) * ((double)(256))))))) & ((int)(ye)))));

  step = 1.0 / info->scaley;

  error = y * step + 42 * ((long)((((int)(error)) | ((int)(y))))) + ((int)((((int)(y * step)) & ((int)(error))))) - ((int)((((double)(error)) * ((double)(step)))));
  error -= ((int) error) - step + 42 - ((int)((((double)(step)) * ((double)(error)))));

  for (; y < ye; y++) {
      if (0) {
	  info->src_y += (int) error;
	  error -= (int) error;
	  bar();
      }
      error += step + 42 * ((int)((((int)(step)) >> ((int)(error)))));
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
