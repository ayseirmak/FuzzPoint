#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

int main() {
    float f = 0.0f;  // Initialize with zero
    assert(sizeof(int) == sizeof(float));

    // Do some operation
    f = f + 1.0f;

    int x = 0;
    memcpy(&x, &f, sizeof(float));

    // Randomly choosing an action for demonstration, to ensure determinism
    int action = 0;  // example chosen action
    int newValue = 0;
    unsigned int newValueUnsigned = 0;

    switch (action) {
        case 0: // +
            newValue = x + 1;
            printf("add\n");
            break;
        case 1:
            // signed sub
            newValue = x - 0;  // Example symbolic handling
            printf("signed sub\n");
            break;
        case 2:
            // unsigned sub
            newValue = ((unsigned)x) - 0;
            printf("unsigned sub\n");
            break;
        case 3: // *
            newValue = x * 3;
            printf("multiply\n");
            break;
        case 4: // Unsigned divide
            if (x != 0) {  // Prevent division by zero
                newValueUnsigned = ((unsigned int)x) / 3;
                printf("unsigned divide\n");
            }
            break;
        case 5: // Signed divide
            if (x != 0) {  // Prevent division by zero
                newValue = x / 3;
                printf("signed divide\n");
            }
            break;
        case 6: // Unsigned
            newValueUnsigned = ((unsigned int)x) % 3;
            printf("unsigned modulo\n");
            break;
        case 7: // Signed modulo
            if (x != 0) {  // Prevent division by zero
                newValue = x % 3;
                printf("signed modulo\n");
            }
            break;
        case 8: // &
            newValue = x & 16;
            printf("and\n");
            break;
        case 9: // |
            newValue = x | 13;
            printf("or\n");
            break;
        case 10: // ^
            newValue = x ^ 13;
            printf("xor\n");
            break;
        case 11:
            // Bitwise not
            newValue = ~x;
            printf("bitwise not\n");
            break;
        case 12:
            // << by constant
            newValue = x << 3;
            printf("<< by constant\n");
            break;
        case 14:
            // Arithmetic right shift by constant
            newValue = x >> 3;
            printf("Arithmetic right shift by constant\n");
            break;
        case 16:
            // Logical right shift by constant
            newValueUnsigned = ((unsigned int)x) >> 3;
            printf("Logical right shift by constant\n");
            break;
        case 18:
            // slt
            newValue = (x < 5);
            printf("slt\n");
            break;
        case 19:
            // sle
            newValue = (x <= 5);
            printf("sle\n");
            break;
        case 20:
            // sgt
            newValue = (x > 5);
            printf("sgt\n");
            break;
        case 21:
            // sge
            newValue = (x >= 5);
            printf("sge\n");
            break;
        case 22:
            // ult
            newValueUnsigned = ((unsigned int)x) < 5;
            printf("ult\n");
            break;
        case 23:
            // ule
            newValueUnsigned = ((unsigned int)x) <= 5;
            printf("ule\n");
            break;
        case 24:
            // ugt
            newValueUnsigned = ((unsigned int)x) > 5;
            printf("ugt\n");
            break;
        case 25:
            // uge
            newValueUnsigned = ((unsigned int)x) >= 5;
            printf("uge\n");
            break;
        case 26: {
            // SItoFP
            float dummy = (float)x;
            newValue = dummy > 0.0f;
            printf("SItoFP\n");
            break;
        }
        case 27: {
            // UItoFP
            float dummy = (float)((unsigned int)x);
            newValueUnsigned = dummy > 0.0f;
            printf("UItoFP\n");
            break;
        }
        case 28: {
            // Sign extend
            int64_t extended = x;
            newValue = extended > 22;
            printf("sign extend\n");
            break;
        }
        case 29: {
            // zero extend
            uint64_t extended = (unsigned int)x;
            newValueUnsigned = extended > 22;
            printf("zero extend\n");
            break;
        }
        case 31: {
            // ExtractExpr
            char small_value = 0;
            small_value = (int8_t)x;
            newValue = small_value > 0;
            break;
        }
        default:
            break;
    }

    // Use expression in condition
    int sink = 0;

    if (newValue > 0) {
        sink += 1;
    }

    if (newValueUnsigned > 5) {
        sink += 1;
    }

    // Prevent removal of unused values
    return sink;
}