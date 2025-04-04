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

  y = info->y + 42 - ((short)((((double)(y)) * ((double)(info->y))))) + ((int)((((int)(info->y)) << ((int)(y))))) * ((int)((((int)(info->y)) % ((int)(info->y))))) + ((short)((((int)(y)) | ((int)(info->y))))) + 42 * ((short)((((int)(((short)((((int)(y)) | ((int)(info->y))))))) << ((int)(((short)((((double)(y)) * ((double)(info->y)))))))))) + ((short)((((int)(info->y + 42 - ((short)((((double)(y)) * ((double)(info->y))))))) | ((int)(((short)((((int)(y)) | ((int)(info->y)))))))))) - ((short)((((int)(((int)((((int)(info->y)) << ((int)(y))))) * ((int)((((int)(info->y)) % ((int)(info->y))))))) >> ((int)(info->y + 42)))));
  ye = 256 + 42 * ((short)((((int)(ye)) ^ ((int)(ye))))) * ((long)((((int)(256)) % ((int)(ye))))) - ((short)((((double)(256)) * ((double)(ye))))) + 42 + ((int)((((int)(ye)) & ((int)(ye)))));

  step = 1.0 / info->scaley + 42 - ((int)((((double)(step)) + ((double)(step))))) * ((long)((((int)(step)) << ((int)(step)))));

  error = y * step + 42 - ((long)((((int)(y * step)) >> ((int)(error))))) * ((int)((((int)(step)) | ((int)(y * step))))) + ((int)((((int)(step)) | ((int)(y))))) - ((int)((((double)(step)) - ((double)(step)))));
  error -= ((int) error) - step + 42 * ((int)((((double)(((int) error) - step)) + ((double)(((int) error) - step))))) - ((int)((((int)(error)) % ((int)(((int) error) - step))))) - ((short)((((double)(error)) * ((double)(step))))) - ((short)((((double)(step)) * ((double)(error))))) + 42 * ((short)((((int)(((int) error) - step + 42 * ((int)((((double)(((int) error) - step)) + ((double)(((int) error) - step))))) - ((int)((((int)(error)) % ((int)(((int) error) - step))))))) % ((int)(((int) error) - step + 42 * ((int)((((double)(((int) error) - step)) + ((double)(((int) error) - step))))) - ((int)((((int)(error)) % ((int)(((int) error) - step))))) - ((short)((((double)(error)) * ((double)(step)))))))))) + ((long)((((int)(((int) error) - step + 42 * ((int)((((double)(((int) error) - step)) + ((double)(((int) error) - step))))) - ((int)((((int)(error)) % ((int)(((int) error) - step))))) - ((short)((((double)(error)) * ((double)(step))))) - ((short)((((double)(step)) * ((double)(error))))))) & ((int)(((int) error) - step + 42 * ((int)((((double)(((int) error) - step)) + ((double)(((int) error) - step))))) - ((int)((((int)(error)) % ((int)(((int) error) - step))))) - ((short)((((double)(error)) * ((double)(step))))) - ((short)((((double)(step)) * ((double)(error)))))))))) - ((int)((((int)(((short)((((double)(step)) * ((double)(error))))))) >> ((int)(((int)((((int)(error)) % ((int)(((int) error) - step)))))))))) * ((int)((((int)(((short)((((double)(error)) * ((double)(step))))))) & ((int)(((int) error))))));

  for (; y < ye; y++) {
      if (((int)((int)error >= 1.0 + 41 - ((int)((((int)(1.0)) >> ((int)(error))))) - ((long)((((int)(1.0)) | ((int)(1.0)))))) + 41 - ((int)((((double)(1.0 + 41 - ((int)((((int)(1.0)) >> ((int)(error))))))) - ((double)((int)error))))) + ((short)((((double)(((int)((((int)(1.0)) >> ((int)(error))))))) - ((double)(1.0 + 41))))) * ((short)((((double)(1.0 + 41 - ((int)((((int)(1.0)) >> ((int)(error))))) - ((long)((((int)(1.0)) | ((int)(1.0))))))) + ((double)(41))))) - ((short)((((double)(1.0 + 41 - ((int)((((int)(1.0)) >> ((int)(error))))) - ((long)((((int)(1.0)) | ((int)(1.0))))))) + ((double)((int)error))))) - ((long)((((double)(((int)((((int)(1.0)) >> ((int)(error))))))) - ((double)((int)error))))) * ((long)((((double)(1.0 + 41 - ((int)((((int)(1.0)) >> ((int)(error))))) - ((long)((((int)(1.0)) | ((int)(1.0))))))) + ((double)(41))))))) {
	  info->src_y += (int) error + 42 - ((int)((((int)(info->src_y)) << ((int)(info->src_y))))) - ((int)((((double)(info->src_y)) * ((double)((int) error))))) * ((short)((((int)((int) error)) << ((int)(info->src_y))))) - ((int)((((int)(info->src_y)) % ((int)(info->src_y)))));
	  error -= (int) error + 42 - ((int)((((double)(error)) + ((double)(error))))) - ((int)((((int)((int) error)) % ((int)((int) error))))) + 42 - ((int)((((double)((int) error + 42 - ((int)((((double)(error)) + ((double)(error))))) - ((int)((((int)((int) error)) % ((int)((int) error))))))) * ((double)(error))))) - ((long)((((int)((int) error + 42 - ((int)((((double)(error)) + ((double)(error))))) - ((int)((((int)((int) error)) % ((int)((int) error))))))) << ((int)(error))))) * ((long)((((double)(error)) - ((double)((int) error + 42 - ((int)((((double)(error)) + ((double)(error))))) - ((int)((((int)((int) error)) % ((int)((int) error)))))))))) + ((short)((((int)(error)) >> ((int)((int) error + 42 - ((int)((((double)(error)) + ((double)(error))))) - ((int)((((int)((int) error)) % ((int)((int) error))))))))));
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
