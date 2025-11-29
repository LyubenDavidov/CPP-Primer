#include <matplot/matplot.h>
#include <vector>

int main() {
    // Prepare data (for example, a sine wave)
    std::vector<double> x(100), y(100);
    for (int i = 0; i < 100; ++i) {
        x[i] = i / 10.0;         // x: [0.0, 9.9]
        y[i] = std::sin(x[i]);   // y: sine of x
    }

    // Initialize the figure
    matplot::figure();

    /// Create the plot and make the line thicker
    auto line = matplot::plot(x, y);
    line->line_width(2.0);  // Make the line 2 points thick

    // Customize the plot (optional)
    matplot::title("Sine Wave");
    matplot::xlabel("x (units)");
    matplot::ylabel("sin(x)");

    // Display the plot
    matplot::show();

    return 0;
}

