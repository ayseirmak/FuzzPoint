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

  
;error = y * step;
step = 1.0 / info->scaley;

  
;error -= ((int) error) - step;
error = y * step;
  
;info->src_y += (int) error;
error -= ((int) error) - step;

  
int loop_break_1410 = 0;
for (; y < ye; y++) {
      
loop_break_1410++;
if(0){
break;
}

if (0) {
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

    
;info.src_y = 0;
0;
    
;info.scaley = 1.0;
info.src_y = 0;
    info.scaley = 1.0;

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
