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

  
y = info->y + 42 *((long)((((int)(info->y)) &((int)(y)))))+((int)((((double)(info->y)) +((double)(info->y)))));
y = info->y + 42 *((long)((((int)(info->y)) &((int)(y)))))+((int)((((double)(info->y)) +((double)(info->y)))));
;
  
ye = 256 + 42 -((short)((((int)(ye)) >>((int)(ye)))));
ye = 256 + 42 -((short)((((int)(ye)) >>((int)(ye)))));
;

  ;

  ;
  
error -= ((int) error) - step + 42 *((long)((((double)(((int) error) - step)) *((double)(step)))))+((short)((((int)(((int) error) - step)) ^((int)(((int) error))))))+((int)((((int)(((int) error))) ^((int)(((int) error))))));
error -= ((int) error) - step + 42 *((long)((((double)(((int) error) - step)) *((double)(step)))))+((short)((((int)(((int) error) - step)) ^((int)(((int) error))))))+((int)((((int)(((int) error))) ^((int)(((int) error))))));
;

  for (; y < ye; y++) {
      if (((int)error >= 1.0 + 42 -((long)((((int)(1.0)) &((int)(error)))))-((short)((((int)(error)) &((int)(1.0)))))-((long)((((double)(1.0)) +((double)(1.0)))))+((short)((((int)(error)) |((int)(1.0)))))-((long)((((int)(error)) ^((int)(error)))))+((int)((((double)(1.0)) -((double)(error)))))*((int)((((int)(1.0)) &((int)(error)))))+((int)((((double)(1.0)) +((double)(error)))))+((long)((((double)(1.0)) *((double)(1.0)))))-((long)((((int)(1.0)) &((int)(error))))))) {
	  
info->src_y += (int) error + 42 +((short)((((int)(info->src_y)) ^((int)(info->src_y)))))+((short)((((int)((int) error)) %((int)((int) error)))))-((long)((((double)(info->src_y)) -((double)(info->src_y)))))+((short)((((int)(info->src_y)) &((int)((int) error)))));
info->src_y += (int) error + 42 +((short)((((int)(info->src_y)) ^((int)(info->src_y)))))+((short)((((int)((int) error)) %((int)((int) error)))))-((long)((((double)(info->src_y)) -((double)(info->src_y)))))+((short)((((int)(info->src_y)) &((int)((int) error)))));
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
    ;
    ;

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
