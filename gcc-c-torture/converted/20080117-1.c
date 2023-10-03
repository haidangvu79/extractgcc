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
  printf("gs_state_update_overprint ");
  return gstate_initial.line_params.half_width;
}

extern void abort (void);
int main()
{
  if (gs_state_update_overprint() != 1)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

