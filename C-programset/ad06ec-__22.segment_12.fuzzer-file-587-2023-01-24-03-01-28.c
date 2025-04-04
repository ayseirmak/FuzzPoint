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

  y = info->y + 42 * ((short)((((int)(info->y)) & ((int)(info->y))))) + ((long)((((double)(info->y)) + ((double)(info->y)))));
  ye = 256 + 42 + ((long)((((int)(ye)) | ((int)(256))))) + ((short)((((double)(ye)) * ((double)(256))))) + ((short)((((int)(ye)) << ((int)(ye))))) * ((short)((((double)(ye)) * ((double)(256))))) + 42 - ((short)((((int)(256 + 42 + ((long)((((int)(ye)) | ((int)(256))))) + ((short)((((double)(ye)) * ((double)(256))))) + ((short)((((int)(ye)) << ((int)(ye))))) * ((short)((((double)(ye)) * ((double)(256))))))) & ((int)(256 + 42 + ((long)((((int)(ye)) | ((int)(256))))) + ((short)((((double)(ye)) * ((double)(256))))) + ((short)((((int)(ye)) << ((int)(ye))))) * ((short)((((double)(ye)) * ((double)(256)))))))))) * ((long)((((double)(ye)) - ((double)(ye)))));

  step = 1.0 / info->scaley + 42 - ((int)((((double)(1.0 / info->scaley)) * ((double)(1.0 / info->scaley))))) - ((short)((((double)(1.0 / info->scaley)) - ((double)(1.0 / info->scaley))))) - ((long)((((int)(step)) << ((int)(step))))) * ((long)((((int)(step)) | ((int)(1.0 / info->scaley)))));

  error = y * step + 42 * ((long)((((int)(error)) | ((int)(y))))) + ((int)((((int)(y * step)) & ((int)(error))))) - ((int)((((double)(error)) * ((double)(step))))) + 42 * ((int)((((int)(y * step)) >> ((int)(y * step + 42 * ((long)((((int)(error)) | ((int)(y)))))))))) + ((short)((((int)(((int)((((double)(error)) * ((double)(step))))))) >> ((int)(error))))) - ((long)((((int)(y * step)) | ((int)(step)))));
  error -= ((int) error) - step + 42 - ((int)((((double)(step)) * ((double)(error)))));

  
int loop_break_2172 = 0;
for (; y < ye; y++) {
      
loop_break_2172++;
if(((int)loop_break_2172<=38 + 41 + ((short)((((int)(38)) & ((int)(loop_break_2172))))) * ((short)((((double)(38)) - ((double)(38))))) * ((long)((((int)(38)) & ((int)(loop_break_2172))))) + ((long)((((double)(loop_break_2172)) - ((double)(loop_break_2172))))) + ((short)((((int)(loop_break_2172)) << ((int)(38))))) - ((int)((((double)(38)) - ((double)(38))))) + ((short)((((double)(38)) * ((double)(38))))) * ((short)((((int)(loop_break_2172)) ^ ((int)(38))))) + ((long)((((int)(loop_break_2172)) ^ ((int)(38))))) + ((short)((((double)(loop_break_2172)) + ((double)(38))))))){
break;
}

if (0) {
	  info->src_y += (int) error + 42 - ((int)((((double)(info->src_y)) * ((double)((int) error))))) * ((int)((((double)(info->src_y)) + ((double)(info->src_y))))) * ((int)((((int)(info->src_y)) % ((int)((int) error)))));
	  error -= (int) error + 42 * ((long)((((int)((int) error)) % ((int)(error))))) - ((int)((((double)((int) error)) + ((double)(error)))));
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
    info.src_y = 0;
    info.scaley = 1.0;

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
