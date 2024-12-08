#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <assert.h>

void entry(const float tensor_input[1][8], float tensor_output[1][4]);

int main() {
    float tensor_input[1][8] = {
        {-0.6323f, 0.1192f, 0.0237f, -0.0034f, -0.1018f, -0.0160f, 0.0f, 1.0f}
    };
    float tensor_output[1][4];

    /* Assume Statements (Converted to Assertions) */
    assert(tensor_input[0][0] >= -0.6525412598015823f && tensor_input[0][0] <= -0.6120714201984176f);
    assert(tensor_input[0][1] >= 0.0989981501984177f && tensor_input[0][1] <= 0.1394679898015823f);
    assert(tensor_input[0][2] >= 0.0034877771984177033f && tensor_input[0][2] <= 0.0439576168015823f);
    assert(tensor_input[0][3] >= -0.023658929601582297f && tensor_input[0][3] <= 0.0168109100015823f);
    assert(tensor_input[0][4] >= -0.1219949298015823f && tensor_input[0][4] <= -0.0815250901984177f);
    assert(tensor_input[0][5] >= -0.036259037801582295f && tensor_input[0][5] <= 0.004210801801582297f);
    assert(tensor_input[0][6] >= -0.020234919801582298f && tensor_input[0][6] <= 0.020234919801582298f);
    assert(tensor_input[0][7] >= 0.9797650801984177f && tensor_input[0][7] <= 1.0202349198015823f);

    /* Call to the entry function */
    entry(tensor_input, tensor_output);

    /* Verify the output condition */
    assert(!((tensor_output[0][2] <= tensor_output[0][3])));

    return 0;
}

/* Include the full neural network implementation here (from the original code) */
/* Replace custom verification functions with standard C assertions */