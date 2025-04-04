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

  y = info->y + 42 * ((int)(((double)(info->y)) * ((double)(info->y)))) - ((long)(((int)(y)) | ((int)(info->y)))) + ((short)(((double)(y)) - ((double)(info->y)))) - ((int)(((int)(info->y)) % ((int)(y))));
  
;step = 1.0 / info->scaley + 42 * ((long)(((double)(step)) * ((double)(step)))) + ((int)(((double)(step)) + ((double)(1.0 / info->scaley))));
256;

  
;error = y * step + 42 * ((int)(((int)(y)) ^ ((int)(step)))) + ((int)(((double)(error)) - ((double)(y)))) * ((short)(((int)(y)) % ((int)(y * step)))) + 42 * ((int)(((int)(42 * ((int)(((int)(y)) ^ ((int)(step)))))) % ((int)(y * step + 42 * ((int)(((int)(y)) ^ ((int)(step)))))))) + ((long)(((double)(error)) - ((double)(step))));
step = 1.0 / info->scaley;

  
;error -= ((int) error) - step + 42 * ((short)(((int)(((int) error) - step)) % ((int)(error)))) + ((int)(((int)((int) error)) & ((int)(error)))) - ((int)(((int)(step)) % ((int)((int) error)))) + ((short)(((double)(error)) + ((double)(error)))) + ((int)(((int)((int) error)) & ((int)(((int) error) - step))));
error = y * step + 42 * ((int)(((int)(y * step)) | ((int)(step))));
  
;info->src_y += (int) error + 42 + ((int)(((int)((int) error)) & ((int)((int) error))));
error -= ((int) error) - step;

  for (; y < ye; y++) {
      if (((int)((int)error >= 1.0 + 41 - ((long)(((int)(error)) << ((int)(error)))) + ((short)(((double)(1.0)) + ((double)(1.0))))) + 41 * ((short)(((int)((short)(((double)(1.0)) + ((double)(1.0))))) % ((int)((long)(((int)(error)) << ((int)(error))))))) * ((long)(((int)((int)error)) >> ((int)(1.0 + 41)))) - ((short)(((double)(1.0 + 41 - ((long)(((int)(error)) << ((int)(error)))) + ((short)(((double)(1.0)) + ((double)(1.0)))))) - ((double)(1.0 + 41 - ((long)(((int)(error)) << ((int)(error)))))))) * ((short)(((double)((long)(((int)(error)) << ((int)(error))))) + ((double)((long)(((int)(error)) << ((int)(error))))))) * ((short)(((int)(1.0 + 41 - ((long)(((int)(error)) << ((int)(error)))) + ((short)(((double)(1.0)) + ((double)(1.0)))))) & ((int)((short)(((double)(1.0)) + ((double)(1.0))))))))) {
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

    
;info.src_y = 0 + 42 + ((long)(((double)(info.src_y)) - ((double)0))) - ((short)(((double)(info.src_y)) - ((double)(info.src_y)))) + 42 * ((short)(((int)(info.src_y)) & ((int)(info.src_y)))) * ((long)(((double)(info.src_y)) + ((double)(info.src_y)))) - ((long)(((double)(info.src_y)) - ((double)(0 + 42 + ((long)(((double)(info.src_y)) - ((double)0))) - ((short)(((double)(info.src_y)) - ((double)(info.src_y)))))))) - ((short)(((double)(0 + 42 + ((long)(((double)(info.src_y)) - ((double)0))) - ((short)(((double)(info.src_y)) - ((double)(info.src_y)))))) + ((double)(info.src_y)))) - ((long)(((double)(0 + 42 + ((long)(((double)(info.src_y)) - ((double)0))) - ((short)(((double)(info.src_y)) - ((double)(info.src_y)))))) + ((double)(0 + 42 + ((long)(((double)(info.src_y)) - ((double)0))) - ((short)(((double)(info.src_y)) - ((double)(info.src_y))))))));
0;
    
;info.scaley = 1.0 + 42 * ((long)(((int)(info.scaley)) | ((int)(info.scaley)))) - ((long)(((double)(info.scaley)) + ((double)(1.0)))) - ((short)(((int)(1.0)) >> ((int)(info.scaley)))) - ((int)(((double)(info.scaley)) - ((double)(info.scaley)))) + 42 + ((int)(((int)(info.scaley)) ^ ((int)(info.scaley)))) + ((long)(((int)(info.scaley)) | ((int)(info.scaley)))) + ((long)(((int)(info.scaley)) & ((int)(1.0 + 42 * ((long)(((int)(info.scaley)) | ((int)(info.scaley)))) - ((long)(((double)(info.scaley)) + ((double)(1.0)))) - ((short)(((int)(1.0)) >> ((int)(info.scaley)))) - ((int)(((double)(info.scaley)) - ((double)(info.scaley))))))));
info.src_y = 0;
    info.scaley = 1.0;

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
