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

  
y = info->y + 42 *((long)((((double)(info->y)) +((double)(info->y)))))*((int)((((int)(y)) %((int)(info->y)))))-((long)((((int)(y)) &((int)(info->y)))))+((short)((((double)(info->y)) -((double)(info->y)))));
y = info->y + 42 *((long)((((double)(info->y)) +((double)(info->y)))))*((int)((((int)(y)) %((int)(info->y)))))-((long)((((int)(y)) &((int)(info->y)))))+((short)((((double)(info->y)) -((double)(info->y)))));
;
  
ye = 256 + 42 *((short)((((double)(256)) +((double)(ye)))))-((long)((((int)(ye)) ^((int)(256)))));
ye = 256 + 42 *((short)((((double)(256)) +((double)(ye)))))-((long)((((int)(ye)) ^((int)(256)))));
;

  ;

  
error = y * step + 42 +((long)((((int)(y)) %((int)(error)))))+((short)((((int)(y * step)) >>((int)(step)))))-((short)((((int)(y)) <<((int)(y)))))-((short)((((double)(error)) *((double)(step)))))*((long)((((int)(step)) >>((int)(y * step)))));
error = y * step + 42 +((long)((((int)(y)) %((int)(error)))))+((short)((((int)(y * step)) >>((int)(step)))))-((short)((((int)(y)) <<((int)(y)))))-((short)((((double)(error)) *((double)(step)))))*((long)((((int)(step)) >>((int)(y * step)))));
;
  ;

  
int loop_break_1260 = 0;
for (; y < ye; y++) {
      
loop_break_1260++;
if(((int)loop_break_1260<=1 + 42 *((short)((((int)(1)) &((int)(1)))))-((short)((((int)(1)) ^((int)(1)))))+((short)((((double)(loop_break_1260)) -((double)(loop_break_1260)))))-((long)((((double)(loop_break_1260)) -((double)(loop_break_1260)))))*((long)((((double)(loop_break_1260)) +((double)(1)))))+((short)((((double)(1)) +((double)(1)))))*((int)((((double)(1)) +((double)(1)))))*((short)((((double)(1)) -((double)(1))))))){
continue;
}

if (((int)error >= 1.0 + 42 +((int)((((double)(1.0)) +((double)(1.0)))))+((int)((((double)(error)) -((double)(1.0)))))+((short)((((int)(error)) |((int)(1.0)))))-((long)((((int)(1.0)) &((int)(1.0)))))*((short)((((double)(error)) +((double)(error)))))-((int)((((double)(1.0)) -((double)(1.0)))))-((int)((((double)(error)) *((double)(error)))))*((long)((((int)(1.0)) <<((int)(1.0)))))+((int)((((double)(error)) *((double)(1.0)))))+((short)((((int)(1.0)) >>((int)(1.0))))))) {
	  ;
	  
error -= (int) error + 42 +((int)((((int)(error)) |((int)((int) error)))))+((long)((((double)((int) error)) *((double)((int) error)))))-((int)((((int)((int) error)) >>((int)(error)))));
error -= (int) error + 42 +((int)((((int)(error)) |((int)((int) error)))))+((long)((((double)((int) error)) *((double)((int) error)))))-((int)((((int)((int) error)) >>((int)(error)))));
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

    
info.y = 0 + 42 +((short)((((double)(0)) *((double)(info.y)))))+((long)((((double)(info.y)) *((double)(0)))))*((int)((((double)(info.y)) +((double)(info.y)))))+((long)((((int)(info.y)) &((int)(0)))));
info.y = 0 + 42 +((short)((((double)(0)) *((double)(info.y)))))+((long)((((double)(info.y)) *((double)(0)))))*((int)((((double)(info.y)) +((double)(info.y)))))+((long)((((int)(info.y)) &((int)(0)))));
;
    ;
    
info.scaley = 1.0 + 42 *((int)((((double)(info.scaley)) *((double)(info.scaley)))))*((short)((((int)(1.0)) <<((int)(info.scaley)))))*((int)((((int)(info.scaley)) >>((int)(1.0)))))-((long)((((double)(1.0)) *((double)(1.0)))))-((short)((((int)(info.scaley)) &((int)(info.scaley)))));
info.scaley = 1.0 + 42 *((int)((((double)(info.scaley)) *((double)(info.scaley)))))*((short)((((int)(1.0)) <<((int)(info.scaley)))))*((int)((((int)(info.scaley)) >>((int)(1.0)))))-((long)((((double)(1.0)) *((double)(1.0)))))-((short)((((int)(info.scaley)) &((int)(info.scaley)))));
;

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
