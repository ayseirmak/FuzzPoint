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

  y = info->y + 42 * ((long)(((double)(y)) - ((double)(info->y)))) + ((int)(((double)(y)) + ((double)(y)))) + 42 + ((short)(((int)(info->y + 42 * ((long)(((double)(y)) - ((double)(info->y)))) + ((int)(((double)(y)) + ((double)(y)))))) << ((int)(info->y + 42 * ((long)(((double)(y)) - ((double)(info->y)))) + ((int)(((double)(y)) + ((double)(y))))))));
  ye = 256 + 42 - ((short)(((int)(ye)) << ((int)256))) * ((int)(((double)256) - ((double)256))) + ((long)(((double)256) + ((double)(ye)))) - ((long)(((int)256) % ((int)(ye)))) + ((short)(((int)(ye)) >> ((int)256))) + 42 - ((long)(((int)(256 + 42 - ((short)(((int)(ye)) << ((int)256))) * ((int)(((double)256) - ((double)256))) + ((long)(((double)256) + ((double)(ye)))) - ((long)(((int)256) % ((int)(ye)))) + ((short)(((int)(ye)) >> ((int)256))))) ^ ((int)(256 + 42 - ((short)(((int)(ye)) << ((int)256))) * ((int)(((double)256) - ((double)256))) + ((long)(((double)256) + ((double)(ye)))) - ((long)(((int)256) % ((int)(ye)))) + ((short)(((int)(ye)) >> ((int)256))))))) - ((int)(((int)(ye)) ^ ((int)(256 + 42 - ((short)(((int)(ye)) << ((int)256))) * ((int)(((double)256) - ((double)256))) + ((long)(((double)256) + ((double)(ye)))) - ((long)(((int)256) % ((int)(ye)))) + ((short)(((int)(ye)) >> ((int)256))))))) - ((short)(((int)(256 + 42 - ((short)(((int)(ye)) << ((int)256))) * ((int)(((double)256) - ((double)256))) + ((long)(((double)256) + ((double)(ye)))) - ((long)(((int)256) % ((int)(ye)))) + ((short)(((int)(ye)) >> ((int)256))))) & ((int)(ye)))) * ((long)(((int)(ye)) >> ((int)(256 + 42 - ((short)(((int)(ye)) << ((int)256))) * ((int)(((double)256) - ((double)256))) + ((long)(((double)256) + ((double)(ye)))) - ((long)(((int)256) % ((int)(ye)))) + ((short)(((int)(ye)) >> ((int)256)))))));

  step = 1.0 / info->scaley;

  error = y * step + 42 * ((int)(((double)(y)) - ((double)(y)))) + ((int)(((double)(step)) - ((double)(error)))) - ((short)(((double)(error)) * ((double)(error))));
  error -= ((int) error) - step + 42 + ((long)(((int)((int) error)) % ((int)((int) error)))) * ((int)(((int)(step)) ^ ((int)(error)))) * ((int)(((int)(((int) error) - step)) ^ ((int)(((int) error) - step)))) + ((int)(((double)(error)) - ((double)((int) error)))) + ((short)(((int)(error)) ^ ((int)((int) error))));

  
int loop_break_2944 = 0;
for (; y < ye; y++) {
      
loop_break_2944++;
if(((int)loop_break_2944<=9 + 41 + ((short)(((double)(loop_break_2944)) + ((double)9))) * ((short)(((int)(loop_break_2944)) | ((int)(loop_break_2944)))) + ((int)(((int)(loop_break_2944)) | ((int)9))) * ((int)(((int)(loop_break_2944)) >> ((int)(loop_break_2944)))) - ((int)(((double)9) - ((double)9))) - ((long)(((double)9) + ((double)9))) * ((int)(((double)9) + ((double)(loop_break_2944)))) * ((long)(((double)(loop_break_2944)) * ((double)(loop_break_2944)))) * ((long)(((int)(loop_break_2944)) ^ ((int)(loop_break_2944)))) - ((int)(((int)9) ^ ((int)(loop_break_2944)))))){
continue;
}

if (0) {
	  info->src_y += (int) error;
	  error -= (int) error + 42 - ((int)(((double)((int) error)) + ((double)((int) error)))) + ((int)(((int)(error)) << ((int)((int) error)))) + 42 * ((short)(((int)((int) error + 42 - ((int)(((double)((int) error)) + ((double)((int) error)))) + ((int)(((int)(error)) << ((int)((int) error)))))) % ((int)(error)))) + ((long)(((int)((int) error + 42 - ((int)(((double)((int) error)) + ((double)((int) error)))) + ((int)(((int)(error)) << ((int)((int) error)))))) >> ((int)((int) error + 42 - ((int)(((double)((int) error)) + ((double)((int) error)))) + ((int)(((int)(error)) << ((int)((int) error))))))));
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
