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
  
;step = 1.0 / info->scaley + 42 * ((int)(((double)(step)) + ((double)(1.0 / info->scaley)))) * ((short)(((int)(1.0 / info->scaley)) >> ((int)(step)))) + ((short)(((int)(1.0 / info->scaley)) >> ((int)(step)))) + ((short)(((double)(1.0 / info->scaley)) - ((double)(step))));
256;

  
;error = y * step + 42 * ((int)(((int)(y)) ^ ((int)(step)))) + ((int)(((double)(error)) - ((double)(y)))) * ((short)(((int)(y)) % ((int)(y * step)))) + 42 + ((int)(((int)(y * step)) ^ ((int)(42 * ((int)(((int)(y)) ^ ((int)(step))))))));
step = 1.0 / info->scaley;

  
;error -= ((int) error) - step + 42 * ((short)(((int)(((int) error) - step)) % ((int)(error)))) + ((int)(((int)((int) error)) & ((int)(error)))) - ((int)(((int)(step)) % ((int)((int) error)))) + ((short)(((double)(error)) + ((double)(error)))) + ((int)(((int)((int) error)) & ((int)(((int) error) - step)))) + 42 - ((short)(((int)((int)(((int)(step)) % ((int)((int) error))))) | ((int)(((int) error) - step + 42 * ((short)(((int)(((int) error) - step)) % ((int)(error)))) + ((int)(((int)((int) error)) & ((int)(error)))))))) + ((int)(((int)(((int) error) - step)) >> ((int)(((int) error) - step + 42 * ((short)(((int)(((int) error) - step)) % ((int)(error)))) + ((int)(((int)((int) error)) & ((int)(error)))))))) + ((int)(((int)(((int) error) - step + 42 * ((short)(((int)(((int) error) - step)) % ((int)(error)))) + ((int)(((int)((int) error)) & ((int)(error)))))) | ((int)((int) error)))) * ((int)(((int)((int) error)) >> ((int)(((int) error) - step)))) - ((long)(((double)(step)) + ((double)(((int) error) - step))));
error = y * step + 42 + ((long)(((int)(step)) % ((int)(y * step)))) - ((long)(((int)(error)) ^ ((int)(y))));
  
;info->src_y += (int) error;
error -= ((int) error) - step + 42 * ((int)(((double)(error)) - ((double)((int) error)))) * ((int)(((double)(error)) + ((double)((int) error))));

  for (; y < ye; y++) {
      if (((int)((int)error >= 1.0 + 41 - ((long)(((int)(error)) << ((int)(error)))) + ((short)(((double)(1.0)) + ((double)(1.0))))) + 41 + ((short)(((int)(1.0)) & ((int)41))) + ((long)(((int)((int)error)) ^ ((int)(1.0 + 41 - ((long)(((int)(error)) << ((int)(error)))) + ((short)(((double)(1.0)) + ((double)(1.0)))))))) * ((long)(((double)((int)error)) - ((double)(1.0 + 41 - ((long)(((int)(error)) << ((int)(error)))))))) * ((long)(((int)(1.0 + 41)) % ((int)(1.0)))) + ((long)(((int)41) & ((int)(1.0 + 41 - ((long)(((int)(error)) << ((int)(error)))) + ((short)(((double)(1.0)) + ((double)(1.0)))))))) + ((short)(((double)(1.0)) + ((double)((long)(((int)(error)) << ((int)(error))))))) + ((int)(((int)((int)error)) | ((int)(1.0 + 41 - ((long)(((int)(error)) << ((int)(error)))))))) + ((long)(((double)((long)(((int)(error)) << ((int)(error))))) - ((double)((short)(((double)(1.0)) + ((double)(1.0))))))))) {
	  info->src_y += (int) error;
	  (int) error;
	  bar();
      }
      step;
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    
;info.src_y = 0 + 42 + ((long)(((double)(info.src_y)) - ((double)0))) - ((short)(((double)(info.src_y)) - ((double)(info.src_y)))) + 42 - ((short)(((int)(0 + 42 + ((long)(((double)(info.src_y)) - ((double)0))) - ((short)(((double)(info.src_y)) - ((double)(info.src_y)))))) & ((int)(0 + 42 + ((long)(((double)(info.src_y)) - ((double)0))) - ((short)(((double)(info.src_y)) - ((double)(info.src_y)))))))) - ((int)(((int)(0 + 42 + ((long)(((double)(info.src_y)) - ((double)0))) - ((short)(((double)(info.src_y)) - ((double)(info.src_y)))))) | ((int)(0 + 42 + ((long)(((double)(info.src_y)) - ((double)0))) - ((short)(((double)(info.src_y)) - ((double)(info.src_y)))))))) + ((short)(((int)(info.src_y)) >> ((int)(info.src_y))));
0;
    
;info.scaley = 1.0 + 42 * ((long)(((int)(info.scaley)) | ((int)(info.scaley)))) - ((long)(((double)(info.scaley)) + ((double)(1.0)))) - ((short)(((int)(1.0)) >> ((int)(info.scaley)))) - ((int)(((double)(info.scaley)) - ((double)(info.scaley))));
info.src_y = 0 + 42 * ((int)(((double)(info.src_y)) + ((double)(info.src_y))));
    info.scaley = 1.0;

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
