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

  
;ye = 256;
info->y;
  ye = 256;

  1.0 / info->scaley;

  y * step;
  
;info->src_y += (int) error;
((int) error) - step;

  
int loop_break_1304 = 0;

int loop_break_1356 = 0;
for (; y < ye; y++) {
      

loop_break_1356++;
if(loop_break_1356<=38){
continue;
}

loop_break_1304++;
if(0){
continue;
}

if (error >= 1.0) {
	  
;error -= (int) error;
info->src_y += (int) error;
	  error -= (int) error;
	  bar();
      }
      step;
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    0;
    
;info.scaley = 1.0;
0;
    info.scaley = 1.0;

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
