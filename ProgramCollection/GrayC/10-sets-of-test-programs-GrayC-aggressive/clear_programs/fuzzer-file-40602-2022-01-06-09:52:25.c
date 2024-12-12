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

  ;
  

ye = 256 + 42 +((short)((((double)(ye)) +((double)(ye)))))+((long)((((double)(ye)) -((double)(ye)))));
ye = 256 + 42 +((short)((((double)(ye)) +((double)(ye)))))+((long)((((double)(ye)) -((double)(ye)))));
;

ye = 256 + 42 +((int)((((double)(ye)) +((double)(ye)))))-((int)((((int)(256)) >>((int)(ye)))));
ye = 256 + 42 +((int)((((double)(ye)) +((double)(ye)))))-((int)((((int)(256)) >>((int)(ye)))));
;
;

  

step = 1.0 / info->scaley + 42 -((int)((((double)(step)) -((double)(1.0 / info->scaley)))))+((int)((((double)(1.0 / info->scaley)) *((double)(1.0 / info->scaley)))));
step = 1.0 / info->scaley + 42 -((int)((((double)(step)) -((double)(1.0 / info->scaley)))))+((int)((((double)(1.0 / info->scaley)) *((double)(1.0 / info->scaley)))));
;
;
;

  

error = y * step + 42 *((int)((((int)(y * step)) >>((int)(error)))));
error = y * step + 42 *((int)((((int)(y * step)) >>((int)(error)))));
;

error = y * step + 42 *((int)((((int)(y * step)) %((int)(y * step)))))-((short)((((int)(error)) >>((int)(y * step)))))+((int)((((double)(y)) *((double)(error)))))-((long)((((int)(y * step)) |((int)(y * step)))));
error = y * step + 42 *((int)((((int)(y * step)) %((int)(y * step)))))-((short)((((int)(error)) >>((int)(y * step)))))+((int)((((double)(y)) *((double)(error)))))-((long)((((int)(y * step)) |((int)(y * step)))));
;
;
  
;

error -= ((int) error) - step + 42 +((short)((((int)(error)) %((int)(step)))))+((short)((((int)(((int) error) - step)) |((int)(error)))));
error -= ((int) error) - step + 42 +((short)((((int)(error)) %((int)(step)))))+((short)((((int)(((int) error) - step)) |((int)(error)))));
;
;

  
int loop_break_4824 = 0;
for (; y < ye; y++) {
      
loop_break_4824++;
if(loop_break_4824<=7){
continue;
}

if (0) {
	  
;

info->src_y += (int) error + 42 *((short)((((int)((int) error)) ^((int)((int) error)))));
info->src_y += (int) error + 42 *((short)((((int)((int) error)) ^((int)((int) error)))));
;
;
	  ;
	  bar();
      }
      
;

error += step + 42 +((int)((((int)(error)) %((int)(step)))))-((short)((((double)(error)) +((double)(step)))));
error += step + 42 +((int)((((int)(error)) %((int)(step)))))-((short)((((double)(error)) +((double)(step)))));
;
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
    ;
    ;

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
