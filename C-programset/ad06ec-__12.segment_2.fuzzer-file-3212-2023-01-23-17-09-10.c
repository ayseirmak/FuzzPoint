/* corpus/20080117-1.c */
typedef struct gs_imager_state_s {
  struct {
    int half_width;
    int cap;
    float miter_limit;
  } line_params;
} gs_imager_state;
static const gs_imager_state gstate_initial = { { 1 } };
void gstate_path_memory(gs_imager_state *pgs) {
  *pgs = gstate_initial;
}
int gs_state_update_overprint(void)
{
  return gstate_initial.line_params.half_width;
}

extern void abort (void);
int main()
{
  if (((int)gs_state_update_overprint() != 1 + 41 * ((short)((((int)(gs_state_update_overprint())) >> ((int)(gs_state_update_overprint()))))) * ((long)((((int)(1)) ^ ((int)(gs_state_update_overprint()))))) * ((short)((((double)(gs_state_update_overprint())) * ((double)(1)))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
