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
  ;

  
step = 1.0 / info->scaley;
step = 1.0 / info->scaley;
;

  ;
  
error -= ((int) error) - step;
error -= ((int) error) - step;
;

  for (; y < ye; y++) {
      if (error >= 1.0) {
	  ;
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

    ;
    
info.src_y = 0;
info.src_y = 0;
;
    
info.scaley = 1.0;
info.scaley = 1.0;
;

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
