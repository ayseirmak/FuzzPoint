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

  y = info->y + 42 - ((int)((((int)(info->y)) ^ ((int)(y))))) * ((short)((((double)(info->y)) * ((double)(info->y)))));
  ye = 256 + 42 + ((long)((((int)(ye)) | ((int)(256))))) + ((short)((((double)(ye)) * ((double)(256))))) + ((short)((((int)(ye)) << ((int)(ye))))) * ((short)((((double)(ye)) * ((double)(256))))) + 42 * ((int)((((int)(256 + 42 + ((long)((((int)(ye)) | ((int)(256))))) + ((short)((((double)(ye)) * ((double)(256))))) + ((short)((((int)(ye)) << ((int)(ye))))) * ((short)((((double)(ye)) * ((double)(256))))))) & ((int)(ye))))) + ((int)((((int)(ye)) << ((int)(ye))))) + ((long)((((int)(ye)) >> ((int)(ye))))) + ((long)((((int)(256 + 42 + ((long)((((int)(ye)) | ((int)(256))))) + ((short)((((double)(ye)) * ((double)(256))))) + ((short)((((int)(ye)) << ((int)(ye))))) * ((short)((((double)(ye)) * ((double)(256))))))) | ((int)(ye))))) - ((int)((((int)(256 + 42 + ((long)((((int)(ye)) | ((int)(256))))) + ((short)((((double)(ye)) * ((double)(256))))) + ((short)((((int)(ye)) << ((int)(ye))))) * ((short)((((double)(ye)) * ((double)(256))))))) >> ((int)(ye)))));

  step = 1.0 / info->scaley + 42 * ((long)((((int)(1.0 / info->scaley)) & ((int)(step)))));

  error = y * step + 42 * ((long)((((int)(error)) | ((int)(y))))) + ((int)((((int)(y * step)) & ((int)(error))))) - ((int)((((double)(error)) * ((double)(step)))));
  error -= ((int) error) - step + 42 - ((int)((((double)(step)) * ((double)(error)))));

  
int loop_break_2172 = 8;
for (; y < ye; y++) {
      
loop_break_2172++;
if(((int)loop_break_2172<=38 + 41 + ((short)((((int)(38)) & ((int)(38))))) * ((short)((((double)(38)) + ((double)(38))))) - ((int)((((int)(loop_break_2172)) ^ ((int)(loop_break_2172))))) + ((short)((((int)(38)) >> ((int)(loop_break_2172))))))){
break;
}

if (0) {
	  info->src_y += (int) error + 42 - ((int)((((int)((int) error)) ^ ((int)(info->src_y))))) + ((int)((((double)((int) error)) + ((double)((int) error)))));
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

    info.y = 0;
    info.src_y = 0 + 42 - ((long)((((int)(0)) << ((int)(0))))) * ((int)((((double)(info.src_y)) - ((double)(info.src_y)))));
    info.scaley = 1.0;

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
