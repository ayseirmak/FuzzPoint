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
  
;step = 1.0 / info->scaley;
256;

  
;error = y * step + 42 * ((int)(((int)(y)) ^ ((int)(step)))) + ((int)(((double)(error)) - ((double)(y)))) * ((short)(((int)(y)) % ((int)(y * step))));
step = 1.0 / info->scaley;

  
;error -= ((int) error) - step + 42 * ((short)(((int)(((int) error) - step)) % ((int)(error)))) + ((int)(((int)((int) error)) & ((int)(error)))) - ((int)(((int)(step)) % ((int)((int) error)))) + ((short)(((double)(error)) + ((double)(error)))) + ((int)(((int)((int) error)) & ((int)(((int) error) - step))));
error = y * step;
  
;info->src_y += (int) error;
error -= ((int) error) - step;

  for (; y < ye; y++) {
      if (((int)error >= 1.0 + 41 - ((long)(((int)(error)) << ((int)(error)))) + ((short)(((double)(1.0)) + ((double)(1.0)))))) {
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

    
;info.src_y = 0 + 42 + ((long)(((double)(info.src_y)) - ((double)0))) - ((short)(((double)(info.src_y)) - ((double)(info.src_y))));
0;
    
;info.scaley = 1.0 + 42 * ((long)(((int)(info.scaley)) | ((int)(info.scaley)))) - ((long)(((double)(info.scaley)) + ((double)(1.0)))) - ((short)(((int)(1.0)) >> ((int)(info.scaley)))) - ((int)(((double)(info.scaley)) - ((double)(info.scaley))));
info.src_y = 0;
    info.scaley = 1.0;

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
