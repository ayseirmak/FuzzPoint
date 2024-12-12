
#include <stdio.h>
#include <math.h>
#include <float.h>

// Structure for financial data representation
typedef struct {
    long double initial_investment; // Initial amount of money invested
    long double interest_rate; // Annual interest rate
    long double compounded_amount; // Amount after compounding
} FinancialModel;

// Function to calculate compounded interest with edge-case handling
void calculate_compound_interest(FinancialModel* model, int years) {
    for (int i = 0; i < years; i++) {
        // Using logarithm to determine compounded growth factor
        long double growth_factor = expl(model->interest_rate * i);

        // Edge case: multiplication by a huge factor
        model->compounded_amount = model->initial_investment * growth_factor;

        // Check for special case NaNs and Infinites
        if (isnan(model->compounded_amount) || isinf(model->compounded_amount)) {
            model->compounded_amount = LDBL_MAX; // Cap to maximum representable value
        }

        // Simulate precision loss using sin and fractional adjustments
        model->compounded_amount += sinl(i * M_PI / 180.0) * 1e-12L;

        // Handle -0.0 representation adjustment
        if (model->compounded_amount == -0.0L) {
            model->compounded_amount = 0.0L;
        }
    }
}

// Reset and normalize values to handle edge cases
void normalize_values(FinancialModel *model) {
    // Iterative casting across different precisions
    for (int i = 0; i < 3; ++i) {
        long long casted_value = (long long)model->compounded_amount;
        model->compounded_amount = (long double)((double)casted_value);
    }

    // Final adjustment ensuring non-negative representation
    if (model->compounded_amount < 0) {
        model->compounded_amount = -model->compounded_amount;
    }
}

int main() {
    FinancialModel model = {
        10000.0L,     // Initial investment
        0.05L,        // Annual interest rate
        0.0L          // Initialized compounded amount
    };

    calculate_compound_interest(&model, 20); // Simulate for 20 years
    normalize_values(&model); // Handle edge-case normalizations

    // Determine if the compounded amount reached a certain threshold
    int result = (model.compounded_amount > 100000.0L) ? 1 : 0;

    return result;
}
