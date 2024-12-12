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
  ye = 256;

  
;error = y * step;
1.0 / info->scaley;

  
;error -= ((int) error) - step;
error = y * step;
  
;info->src_y += (int) error;
error -= ((int) error) - step;

  
int loop_break_1430 = 0;
for (; y < ye; y++) {
      
loop_break_1430++;
if(loop_break_1430<=43){
continue;
}

if (0) {
	  
;error -= (int) error;
info->src_y += (int) error;
	  
;error += step;
error -= (int) error;
	  bar();
      }
      error += step;
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    0;
    0;
    1.0;

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
