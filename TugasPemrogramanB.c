#include <stdio.h>
#include <math.h>

// Heat capacity function: c(T) = 0.132 + 1.56e-4*T + 2.64e-7*T^2
double heat_capacity(double T) {
    return 0.132 + 1.56e-4 * T + 2.64e-7 * T * T;
}

// Simpson's 1/3 rule integration (requires even number of intervals)
double simpsons_rule(double (*func)(double), double a, double b, int n) {
    if (n % 2 != 0) {
        printf("Error: Simpson's rule requires even number of intervals\n");
        return 0.0;
    }
    
    double h = (b - a) / n;
    double sum = func(a) + func(b);
    
    // Add odd-indexed terms (coefficient 4)
    for (int i = 1; i < n; i += 2) {
        double x = a + i * h;
        sum += 4 * func(x);
    }
    
    // Add even-indexed terms (coefficient 2)
    for (int i = 2; i < n; i += 2) {
        double x = a + i * h;
        sum += 2 * func(x);
    }
    
    return sum * h / 3.0;
}

// Calculate percentage error
double percent_error(double approximate, double exact) {
    return fabs((approximate - exact) / exact) * 100.0;
}

// Analytical solution for the given heat capacity function
double analytical_solution(double m, double T1, double T2) {
    // Integral of c(T) = 0.132*T + 1.56e-4*T^2/2 + 2.64e-7*T^3/3
    double integral_T2 = 0.132 * T2 + 1.56e-4 * T2 * T2 / 2.0 + 2.64e-7 * T2 * T2 * T2 / 3.0;
    double integral_T1 = 0.132 * T1 + 1.56e-4 * T1 * T1 / 2.0 + 2.64e-7 * T1 * T1 * T1 / 3.0;
    return m * (integral_T2 - integral_T1);
}

// Print heat capacity table
void print_heat_capacity_table(double T1, double T2, int points) {
    printf("\n=== Heat Capacity Table ===\n");
    printf("T, C\t\tc, cal/(g*C)\n");
    printf("----------------------------------------\n");
    
    double step = (T2 - T1) / (points - 1);
    for (int i = 0; i < points; i++) {
        double T = T1 + i * step;
        double c = heat_capacity(T);
        printf("%.0f\t\t%.5f\n", T, c);
    }
    printf("\n");
}

int main() {
    // Problem parameters
    double mass = 1000.0;  // grams
    double T1 = -100.0;    // initial temperature (°C)
    double T2 = 200.0;     // final temperature (°C)
    
    printf("=== Heat Integration Calculator ===\n");
    printf("Problem: Calculate heat required to raise %.0f g of material\n", mass);
    printf("from %.0f C to %.0f C\n", T1, T2);
    printf("Heat capacity function: c(T) = 0.132 + 1.56e-4*T + 2.64e-7*T^2\n\n");
    
    // Calculate analytical solution
    double exact_delta_H = analytical_solution(mass, T1, T2);
    printf("Analytical solution: Delta H = %.0f cal\n\n", exact_delta_H);
    
    // Print heat capacity table
    print_heat_capacity_table(T1, T2, 7);
    
    // Test Simpson's rule with different segments
    printf("\n=== Simpson's 1/3 Rule Results ===\n");
    int segments[] = {6, 12, 24, 48};
    int num_segments = sizeof(segments) / sizeof(segments[0]);
    
    printf("Segments\tDelta H, cal\tError (%%)\n");
    printf("------------------------------------\n");
    
    for (int i = 0; i < num_segments; i++) {
        int n = segments[i];
        double integral = simpsons_rule(heat_capacity, T1, T2, n);
        double delta_H = mass * integral;
        double error = percent_error(delta_H, exact_delta_H);
        
        printf("%d\t\t%.3f\t\t%.6f\n", n, delta_H, error);
    }
    
    // Demonstrate the integration process step by step for 6-segment Simpson's rule
    printf("\n=== Step-by-Step Simpson's Rule (6 segments) ===\n");
    int n = 6;
    double h = (T2 - T1) / n;
    printf("Step size h = (%.0f - (%.0f))/6 = %.1f C\n", T2, T1, h);
    printf("\nTemperature points and c(T) values:\n");
    printf("i\tT(C)\tc(T)\tCoeff\tc(T)*Coeff\n");
    printf("------------------------------------------------\n");
    
    double sum = 0.0;
    for (int i = 0; i <= n; i++) {
        double T = T1 + i * h;
        double c = heat_capacity(T);
        int coeff;
        
        if (i == 0 || i == n) {
            coeff = 1;
        } else if (i % 2 == 1) {
            coeff = 4;
        } else {
            coeff = 2;
        }
        
        double contribution = c * coeff;
        sum += contribution;
        
        printf("%d\t%.1f\t%.5f\t%d\t%.5f\n", i, T, c, coeff, contribution);
    }
    
    double integral_simpson = sum * h / 3.0;
    double delta_H_simpson = mass * integral_simpson;
    
    printf("\nSum = %.5f\n", sum);
    printf("Integral = (%.5f * %.1f) / 3 = %.3f\n", sum, h, integral_simpson);
    printf("Delta H = %.0f * %.3f = %.0f cal\n", mass, integral_simpson, delta_H_simpson);
    
    return 0;
}
