#include "std_lib_facilities.h"
#include "callOption.h"

// leave this constructor as it is
double random_normal();
callOption::callOption() {
    // stock price at time 0
    s0 = 100;
    // daily risk-free rate
    r = 0.001;
    // daily volatility
    vol = 0.01;
    // strike price
    k = 100;
    // time to maturity 30 days.
    T = 30;
    cout << "stock price: " << s0 << endl;
    cout << "risk-free rate: " << r << endl;
    cout << "daily volatility: " << vol << endl;
    cout << "strike price: " << k << endl;
    cout << "time to maturity: " << T << endl;
    cout << endl;
}

// complete the implementation of this constructor
callOption::callOption(double new_s0, double new_r, double new_vol, double new_k, double new_T) {
    s0 = new_s0;
    r = new_r;
    vol = new_vol;
    k = new_k;
    T = new_T;
}

// use path independent simulation to price this option.
double callOption::price() {
    const int num_simulations = 1000000;
    const double dt = 1.0 / 365.0;

    double sum_payoff = 0.0;
    for (int i = 0; i < num_simulations; ++i) {
        double s_T = s0 * exp((r - 0.5 * vol * vol) * T * dt + vol * sqrt(T * dt) * random_normal());
        double payoff = fmax(s_T - k, 0.0);
        sum_payoff += payoff;
    }
    double call_price = sum_payoff / num_simulations * exp(-r * T);

    return call_price;
}
double random_normal() {
    static const double two_pi = 2.0 * 3.14;
    static bool have_second = false;
    static double second;

    if (have_second) {
        have_second = false;
        return second;
    }

    double x, y, r;
    do {
        x = -1.0 + 2.0 * rand() / (RAND_MAX + 1.0);
        y = -1.0 + 2.0 * rand() / (RAND_MAX + 1.0);
        r = x * x + y * y;
    } while (r >= 1.0 || r == 0.0);

    double z = sqrt(-2.0 * log(r) / r) * x;
    second = sqrt(-2.0 * log(r) / r) * y;
    have_second = true;

    return z;
}


