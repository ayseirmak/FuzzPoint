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

  
int loop_break_1260 = 0;

int loop_break_1326 = 0;

int loop_break_1394 = 0;

int loop_break_1460 = 0;

int loop_break_1600 = 0;
for (; y < ye; y++) {
      




loop_break_1600++;
if(0){
continue;
}

loop_break_1460++;
if(0){
break;
}

loop_break_1394++;
if(0){
break;
}

loop_break_1326++;
if(0){
continue;
}

loop_break_1260++;
if(0){
continue;
}

if (0) {
	  
info->src_y += (int) error;
info->src_y += (int) error;
;
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

    ;
    ;
    
info.scaley = 1.0;
info.scaley = 1.0;
;

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
