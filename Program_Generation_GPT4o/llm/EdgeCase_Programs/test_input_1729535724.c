
#include <stdio.h>
#include <math.h>
#include <float.h>

// Define mathematical constants if not preset
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#ifndef M_E
#define M_E 2.71828182845904523536
#endif

// Function to simulate RC circuit response to a sinusoidal input
void simulate_rc_circuit_response(double frequency, double resistance, double capacitance, int steps) {
    double time_step = 1.0 / (frequency * steps); // Time step for iterations
    double time = 0.0;
    double voltage = 0.0;

    printf("Starting simulation...\n");

    for (int i = 0; i < steps; ++i) {
        // Calculating input voltage using sin wave
        double input_voltage = sin(2 * M_PI * frequency * time);

        // RC circuit behavior using exponential decay based on RC time constant
        double rc_time_constant = resistance * capacitance;
        voltage += (input_voltage - voltage) * (1 - exp(-time_step / rc_time_constant));

        // Cast to different types, demonstrating precision and potential overflow handling
        float voltage_float = (float)voltage;
        long double voltage_long_double = (long double)voltage;

        // Avoid overflow by checking limits
        if (voltage > DBL_MAX) {
            printf("Overflow detected at step %d!\n", i);
            break;
        }

        printf("Time: %.4f ms, Input Voltage: %.4f V, Voltage: %.6f V (float: %.6f, long double: %.9Lf)\n",
               time * 1000, input_voltage, voltage, voltage_float, voltage_long_double);

        time += time_step;
    }
}

int main() {
    double frequency = 60.0; // 60 Hz, typical AC line frequency
    double resistance = 1000.0; // 1000 ohms
    double capacitance = 1.0e-6; // 1 microfarad

    printf("RC Circuit Voltage Response Simulation\n");
    simulate_rc_circuit_response(frequency, resistance, capacitance, 100);

    return 0;
}
