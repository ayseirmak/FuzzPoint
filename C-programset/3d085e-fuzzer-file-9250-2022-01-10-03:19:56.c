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
y = info->y;
;
  
ye = 256;
ye = 256;
;

  ;

  
error = y * step;
error = y * step;
;
  
error -= ((int) error) - step;
error -= ((int) error) - step;
;

  for (; y < ye; y++) {
      if (error >= 1.0) {
	  ;
	  
error -= (int) error;
error -= (int) error;
;
	  bar();
      }
      ;
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    
info.y = 0;
info.y = 0;
;
    ;
    ;

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
