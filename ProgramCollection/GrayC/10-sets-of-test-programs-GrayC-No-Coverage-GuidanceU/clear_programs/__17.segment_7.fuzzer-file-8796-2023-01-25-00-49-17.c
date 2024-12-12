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
  ye = 256 + 42 + ((long)((((double)(ye)) - ((double)(ye))))) * ((short)((((double)(ye)) * ((double)(256))))) - ((int)((((int)(256)) & ((int)(256))))) * ((int)((((double)(ye)) + ((double)(256)))));

  
;error = y * step;
1.0 / info->scaley;

  
;error -= ((int) error) - step;
error = y * step;
  
;info->src_y += (int) error;
error -= ((int) error) - step;

  
int loop_break_1430 = 0;
for (; y < ye; y++) {
      
loop_break_1430++;
if(((int)loop_break_1430<=43 + 41 - ((int)((((double)(loop_break_1430)) + ((double)(43))))) + ((short)((((int)(43)) | ((int)(43))))) - ((int)((((int)(43)) << ((int)(43))))) - ((long)((((double)(loop_break_1430)) * ((double)(loop_break_1430))))) + ((long)((((int)(43)) ^ ((int)(43))))) * ((int)((((double)(43)) + ((double)(43))))) - ((short)((((double)(43)) - ((double)(loop_break_1430))))) - ((int)((((double)(loop_break_1430)) + ((double)(43))))) * ((short)((((int)(loop_break_1430)) & ((int)(43))))) - ((long)((((int)(43)) | ((int)(loop_break_1430))))))){
continue;
}

if (0) {
	  
;error -= (int) error + 42 - ((long)((((int)(error)) << ((int)(error))))) + ((long)((((double)(error)) * ((double)(error))))) - ((int)((((int)((int) error)) | ((int)((int) error))))) * ((short)((((double)(error)) + ((double)((int) error))))) + ((int)((((double)(error)) - ((double)(error)))));
info->src_y += (int) error;
	  
;error += step;
error -= (int) error;
	  bar();
      }
      error += step + 42 * ((int)((((double)(error)) * ((double)(error))))) - ((long)((((int)(error)) | ((int)(error))))) + ((long)((((int)(error)) & ((int)(error))))) - ((short)((((int)(error)) ^ ((int)(error)))));
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
