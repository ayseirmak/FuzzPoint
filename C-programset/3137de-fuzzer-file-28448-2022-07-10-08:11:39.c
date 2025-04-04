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
ye;

  
;error = y * step;
step = 1.0 / info->scaley;

  error = y * step;
  
;info->src_y += (int) error + 42 + ((short)(((int)(info->src_y)) << ((int)((int) error)))) - ((short)(((double)((int) error)) - ((double)((int) error)))) * ((short)(((double)((int) error)) + ((double)((int) error))));
((int) error) - step;

  for (; y < ye; y++) {
      if (((int)error >= 1.0 + 41 + ((int)(((double)(1.0)) + ((double)(1.0)))) * ((long)(((double)(error)) - ((double)(1.0)))))) {
	  info->src_y += (int) error + 42 + ((short)(((int)(info->src_y)) << ((int)((int) error)))) - ((short)(((double)((int) error)) - ((double)((int) error)))) * ((short)(((double)((int) error)) + ((double)((int) error))));
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

    0 + 42 * ((int)(((double)0) + ((double)0)));
    0;
    1.0;

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
