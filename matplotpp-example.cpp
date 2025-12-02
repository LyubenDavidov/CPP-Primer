/**
 * Small script to illustrate plotting using Matplot++
 * Plots are generated using GNUPlot
*/

#include <iostream>
#include <matplot/matplot.h>
#include <vector>

int main() {

    // ----- calculate sinewave data -----
    std::vector<double> x(100), y(100);
    for (int i = 0; i < 100; ++i) {
        x[i] = i / 10.0;         // x: [0.0, 9.9]
        y[i] = std::sin(x[i]);   // y: sine of x
    }

    // ----- initialize figure -----
    matplot::figure();

    // ----- create plot -----
    auto line = matplot::plot(x, y);

    // ----- make line 2 points thick -----
    line->line_width(2.0); 

    // ----- customize plot -----
    matplot::title("Sine Wave");
    matplot::xlabel("x (units)");
    matplot::ylabel("sin(x)");

    // ----- display plot -----
    matplot::show();

    // ----- save plot -----
    matplot::save("./plots/test-plot.svg");

    return 0;
}

