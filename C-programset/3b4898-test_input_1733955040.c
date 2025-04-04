
#include <stdio.h>
#include <math.h>

// Define a structure to represent an asset in the portfolio
typedef struct {
    double expected_return; // Asset's expected return (annualized)
    double weight;          // Asset's weight in the portfolio
} Asset;

// Function to calculate the portfolio's expected return
double calculate_portfolio_return(Asset* assets, int num_assets) {
    double portfolio_return = 0.0;
    for (int i = 0; i < num_assets; i++) {
        portfolio_return += assets[i].weight * assets[i].expected_return;
    }
    return portfolio_return;
}

// Function to calculate the variance of the portfolio
double calculate_portfolio_variance(Asset* assets, int num_assets, double** covariance_matrix) {
    double portfolio_variance = 0.0;
    for (int i = 0; i < num_assets; i++) {
        for (int j = 0; j < num_assets; j++) {
            portfolio_variance += assets[i].weight * assets[j].weight * covariance_matrix[i][j];
        }
    }
    return portfolio_variance;
}

int main() {
    // Define the assets in the portfolio
    Asset portfolio[] = {
        {0.08, 0.3},  // Asset 1: Expected return 8%, weight 30%
        {0.12, 0.4},  // Asset 2: Expected return 12%, weight 40%
        {0.06, 0.3}   // Asset 3: Expected return 6%, weight 30%
    };
    
    int num_assets = sizeof(portfolio) / sizeof(portfolio[0]);

    // Define the covariance matrix of the assets
    double covariance_data[][3] = {
        {0.0025, 0.0008, 0.0007},  // Covariance between assets 1 and others
        {0.0008, 0.0010, 0.0009},  // Covariance between assets 2 and others
        {0.0007, 0.0009, 0.0015}   // Covariance between assets 3 and others
    };
    
    // Convert covariance data to a pointer array for function compatibility
    double* covariance_matrix[3];
    for (int i = 0; i < num_assets; i++) {
        covariance_matrix[i] = covariance_data[i];
    }

    // Calculate portfolio metrics
    double portfolio_return = calculate_portfolio_return(portfolio, num_assets);
    double portfolio_variance = calculate_portfolio_variance(portfolio, num_assets, covariance_matrix);
    double portfolio_std_dev = sqrt(portfolio_variance);

    printf("Portfolio Analysis:\n");
    printf("Expected Portfolio Return: %.2f%%\n", portfolio_return * 100);
    printf("Portfolio Variance: %.6f\n", portfolio_variance);
    printf("Portfolio Standard Deviation: %.6f\n", portfolio_std_dev);

    return 0;
}
