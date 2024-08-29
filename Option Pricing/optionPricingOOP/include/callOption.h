#pragma once

class callOption{
private:
    // stock price at time 0
    double s0;
    // daily risk-free rate
    double r;
    // daily volatility
    double vol;
    // strike price
    double k;
    // time to maturity
    double T;
public:
    // default constructor
    callOption();
    // constructor with input parameters
    callOption(double new_s0, double new_r, double new_vol, double new_k, double new_T);
    // Monte Carlo simulation path independent option pricing
    double price();
};
