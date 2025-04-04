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

  y = info->y + 42 - ((short)((((double)(y)) + ((double)(y))))) - ((short)((((int)(y)) % ((int)(y))))) - ((long)((((double)(y)) * ((double)(info->y))))) * ((int)((((double)(y)) * ((double)(y))))) + ((int)((((double)(info->y)) + ((double)(info->y)))));
  ye = 256 + 42 * ((long)((((int)(ye)) | ((int)(256))))) + 42 - ((int)((((double)(ye)) * ((double)(ye))))) + ((int)((((int)(ye)) | ((int)(ye)))));

  step = 1.0 / info->scaley;

  error = y * step;
  error -= ((int) error) - step + 42 - ((long)((((int)(((int) error))) % ((int)(((int) error)))))) - ((long)((((double)(((int) error))) - ((double)(((int) error))))));

  
int loop_break_1260 = 8;
for (; y < ye; y++) {
      
loop_break_1260--;
if(0){
continue;
}

if (((int)((int)error >= 1.0 + 41 - ((short)((((double)(1.0)) * ((double)(error))))) + ((short)((((double)(1.0)) + ((double)(error))))) * ((long)((((double)(1.0)) * ((double)(1.0)))))) + 41 + ((long)((((int)(1.0 + 41 - ((short)((((double)(1.0)) * ((double)(error))))))) ^ ((int)(1.0 + 41 - ((short)((((double)(1.0)) * ((double)(error))))) + ((short)((((double)(1.0)) + ((double)(error))))) * ((long)((((double)(1.0)) * ((double)(1.0)))))))))) - ((short)((((int)(((short)((((double)(1.0)) * ((double)(error))))))) & ((int)(41))))) - ((long)((((int)(((short)((((double)(1.0)) * ((double)(error))))))) % ((int)(1.0))))) - ((long)((((int)(1.0 + 41 - ((short)((((double)(1.0)) * ((double)(error))))))) % ((int)(((short)((((double)(1.0)) + ((double)(error))))) * ((long)((((double)(1.0)) * ((double)(1.0)))))))))) - ((short)((((int)(((short)((((double)(1.0)) + ((double)(error))))) * ((long)((((double)(1.0)) * ((double)(1.0))))))) & ((int)(1.0))))) * ((int)((((int)(41)) ^ ((int)(((short)((((double)(1.0)) * ((double)(error)))))))))) + ((long)((((int)(1.0)) & ((int)(1.0))))) * ((long)((((int)(1.0 + 41 - ((short)((((double)(1.0)) * ((double)(error))))))) >> ((int)(1.0 + 41))))))) {
	  info->src_y += (int) error + 42 + ((short)((((double)((int) error)) + ((double)((int) error))))) + ((long)((((double)((int) error)) - ((double)(info->src_y))))) * ((long)((((int)((int) error)) << ((int)((int) error)))));
	  error -= (int) error + 42 + ((int)((((int)((int) error)) ^ ((int)(error))))) - ((long)((((int)(error)) & ((int)((int) error))))) + ((long)((((double)((int) error)) - ((double)((int) error))))) * ((int)((((int)((int) error)) | ((int)((int) error))))) - ((int)((((int)((int) error)) | ((int)((int) error)))));
	  bar();
      }
      error += step + 42 + ((short)((((int)(step)) & ((int)(error)))));
  }
  return info->src_y;
}

int main (void)
{
    RenderInfo info;

    info.y = 0 + 42 - ((int)((((int)(info.y)) >> ((int)(info.y))))) * ((long)((((int)(info.y)) & ((int)(0))))) - ((long)((((double)(0)) - ((double)(info.y)))));
    info.src_y = 0;
    info.scaley = 1.0;

    if (0)
    { abort (); }
    exit(0);
}
/* ProgramSourceLLVM */
