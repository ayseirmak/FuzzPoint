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

  y = info->y + 42 * ((short)((((int)(info->y)) >> ((int)(y))))) * ((short)((((double)(info->y)) - ((double)(y))))) + ((short)((((double)(y)) * ((double)(info->y))))) - ((short)((((double)(info->y)) * ((double)(info->y))))) + 42 + ((long)((((int)(((short)((((double)(info->y)) - ((double)(y))))))) | ((int)(info->y + 42 * ((short)((((int)(info->y)) >> ((int)(y))))) * ((short)((((double)(info->y)) - ((double)(y))))) + ((short)((((double)(y)) * ((double)(info->y))))) - ((short)((((double)(info->y)) * ((double)(info->y)))))))))) + ((short)((((int)(((short)((((double)(info->y)) - ((double)(y))))))) | ((int)(42 * ((short)((((int)(info->y)) >> ((int)(y)))))))))) * ((short)((((int)(info->y + 42 * ((short)((((int)(info->y)) >> ((int)(y))))) * ((short)((((double)(info->y)) - ((double)(y))))) + ((short)((((double)(y)) * ((double)(info->y))))) - ((short)((((double)(info->y)) * ((double)(info->y))))))) | ((int)(42 * ((short)((((int)(info->y)) >> ((int)(y))))) * ((short)((((double)(info->y)) - ((double)(y)))))))))) * ((int)((((int)(info->y + 42 * ((short)((((int)(info->y)) >> ((int)(y))))) * ((short)((((double)(info->y)) - ((double)(y))))) + ((short)((((double)(y)) * ((double)(info->y))))))) % ((int)(42 * ((short)((((int)(info->y)) >> ((int)(y))))) * ((short)((((double)(info->y)) - ((double)(y))))))))));
  ye = 256 + 42 + ((int)((((int)(256)) << ((int)(ye))))) - ((int)((((double)(ye)) * ((double)(256))))) + 42 - ((short)((((double)(ye)) - ((double)(256))))) - ((int)((((int)(ye)) & ((int)(256))))) + ((short)((((double)(256)) * ((double)(256 + 42)))));

  step = 1.0 / info->scaley;

  error = y * step + 42 - ((long)((((int)(error)) << ((int)(step))))) - ((long)((((int)(step)) << ((int)(y * step))))) * ((long)((((int)(step)) % ((int)(y))))) + ((short)((((int)(step)) % ((int)(step))))) * ((long)((((int)(error)) | ((int)(y * step)))));
  error -= ((int) error) - step + 42 + ((short)((((int)(step)) % ((int)(step))))) * ((int)((((double)(error)) * ((double)(((int) error)))))) * ((short)((((double)(((int) error))) - ((double)(((int) error) - step)))));

  for (; y < ye; y--) {
      if (0) {
	  info->src_y += (int) error + 42 + ((long)((((double)((int) error)) - ((double)((int) error))))) * ((int)((((double)(info->src_y)) + ((double)(info->src_y))))) - ((int)((((int)(info->src_y)) % ((int)((int) error))))) + 42 - ((int)((((double)(((long)((((double)((int) error)) - ((double)((int) error))))))) - ((double)(((long)((((double)((int) error)) - ((double)((int) error)))))))))) * ((short)((((double)(info->src_y)) * ((double)(((int)((((int)(info->src_y)) % ((int)((int) error)))))))))) + ((short)((((int)(((int)((((int)(info->src_y)) % ((int)((int) error))))))) << ((int)(((int)((((double)(info->src_y)) + ((double)(info->src_y))))))))));
	  error -= (int) error + 42 + ((int)((((int)((int) error)) | ((int)((int) error))))) + ((short)((((double)(error)) * ((double)((int) error))))) + ((short)((((double)(error)) + ((double)(error))))) + 42 * ((long)((((int)(error)) | ((int)((int) error + 42 + ((int)((((int)((int) error)) | ((int)((int) error))))) + ((short)((((double)(error)) * ((double)((int) error))))) + ((short)((((double)(error)) + ((double)(error)))))))))) + ((long)((((double)(error)) * ((double)(error))))) - ((short)((((int)(error)) % ((int)((int) error + 42 + ((int)((((int)((int) error)) | ((int)((int) error))))) + ((short)((((double)(error)) * ((double)((int) error))))) + ((short)((((double)(error)) + ((double)(error))))))))));
	  bar();
      }
      error += step + 42 * ((int)((((double)(step)) * ((double)(step))))) - ((int)((((int)(error)) << ((int)(step))))) - ((int)((((double)(step)) + ((double)(error))))) + ((long)((((double)(error)) - ((double)(step))))) + 42 * ((short)((((int)(((int)((((double)(step)) + ((double)(error))))))) | ((int)(step + 42 * ((int)((((double)(step)) * ((double)(step))))) - ((int)((((int)(error)) << ((int)(step)))))))))) * ((long)((((int)(error)) << ((int)(step))))) * ((short)((((int)(error)) ^ ((int)(step + 42 * ((int)((((double)(step)) * ((double)(step))))) - ((int)((((int)(error)) << ((int)(step)))))))))) * ((int)((((int)(step)) & ((int)(((int)((((int)(error)) << ((int)(step))))))))));
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
