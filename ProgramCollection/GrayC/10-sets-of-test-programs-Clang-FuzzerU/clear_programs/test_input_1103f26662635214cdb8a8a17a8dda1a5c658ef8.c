#include <stdio.h>
#include <stdlib.h>

typedef struct gs_imager_state_s {
    struct {
        int half_width;
        int cap;
        float miter_limit;
    } line_params;
} gs_imager_state;

static const gs_imager_state gstate_initial = {{1, 0, 0.0}};

void gstate_path_memory(gs_imager_state *pgs) {
    *pgs = gstate_initial;
}

int gs_state_update_overprint(void) {
    return gstate_initial.line_params.half_width;
}

int main() {
    union {
        int a;
        int b;
    } u;
    
    // Given that u.b is set after u.a, u.b will be the valid value in this union.
    u.a = 1;
    u.b = 3;

    // Check if union and struct logic works as expected
    if (u.a != 3 || u.b != 3) {
        printf("Test failed for union.\n");
        return 1;
    }

    if (gs_state_update_overprint() != 1) {
        printf("Test failed for gs_state_update_overprint.\n");
        return 1;
    }

    printf("All tests passed.\n");
    return 0;
}