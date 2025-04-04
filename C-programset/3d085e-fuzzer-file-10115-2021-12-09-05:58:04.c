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

  
int loop_break_1260 = 0;
for (; y < ye; y++) {
      
loop_break_1260++;
if(loop_break_1260<=2){
continue;
}

if (error >= 1.0) {
	  
info->src_y += (int) error;
info->src_y += (int) error;
;
	  
error -= (int) error;
error -= (int) error;
;
	  bar();
      }
      
error += step;
error += step;
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
