#include <math.h>

#define PI (3.141592653589793)
#define g (9.81)

double generic_function(double x){ // 14
    // return PI * x - exp(x);
    return exp(5*x) - 2;
}

double populational_growth(double l){ // taxa de crescimento pop 15
        double p0 = 1741212;
        double v = 198574 ;
        double p = 3473188;
        return p0 * exp(l) + (v/l)*(exp(l) - 1) - p;
}

double d_populational_growth(double l){ //
    double p0 = 1311701;
    double v = 160954;
    double p = 2475159;

    return p0*exp(l)+(v*(exp(l)*l-exp(l)+1)/(l*l));
}

double sky_diver_velocity(double m) {
    double c = 26.61;
    double v = 30.01;
    double t = 7.69;

    return ((g*m)/c)*(1-exp(-(c/m)*t))-v;
}

double d_sky_diver_velocity(double m) {
    return (exp(-204.631/m))*(-(75.4389/m)-0.368658)+0.368658;
}

double water_pipe_exit_velocity(double H) {
    double L = 8.12;
    double v = 6.26;
    double t = 7.1;

    return sqrt(2*g*H) * tanh((sqrt(2*g*H)/(2*L))*t) - v;
}

double d_water_pipe_exit_velocity(double H) {
    return (2.21472*tanh(1.93652*sqrt(H)))/sqrt(H) + 4.28885*pow((1/(cosh(1.93652*sqrt(H)))), 2);
}

double water_depth_flow(double y) {
    double B = 8.93 + y;
    double Ac = 8.93 * y + pow(y, 2)/2;
    double Q = 107.42; 

    return 1 - (pow(Q, 2) / (g*pow(Ac, 3)))*B;
}

double dome_volume(double h) {
    double R = 9.04;
    double V = 2380.99;

    return PI * pow(h, 2)*((3*R-h)/3) - V;
}

double d_dome_volume(double h) {
    return h*(56.8 - PI * h);
}

double sphere_buoyancy(double h) {
    double r = 7.21;
    double ps = 376.4; // densidade esfera
    double pw = 1000; //densidade agua
    double vs = (4.0/3) * PI * pow(r, 3); // volume esfera

    double v = ((PI*pow(h, 2))/3)*(3*r-h);

    return pw * (vs - v) - (ps * vs);
}

double d_sphere_buoyancy(double h) {
    double r = 7.21;

    return -1000 * PI * h * (2 * r - h);
}

double semi_circular_tank(double h) {
    double l = 8.12;
    double r = 1.46;
    double v = 24.34;

    return l * (0.5*PI*pow(r,2) - pow(r,2)*asin(h/r) - h*sqrt(pow(r,2) - pow(h,2))) - v;
}

double particle_position(double w) {
    double t = 1.46; // segundos
    double xt = 4.17; //metros que moveu

    return -((g/(2*pow(w,2)))*(sinh(w*t) - sin(w*t))) - xt;
}

double d_particle_position(double w) {
    double t = 1;
    double xt = 1.01;

    return (1/pow(w,3)) * (-g*sin(1.46*w) + 7.1613 * w * cos(1.46 * w) + 9.81*sinh(1.46*w) - 7.1613*w*cosh(1.46*w));
}

double box_lid_size(double l) {

    return 4 * pow(l,3) - 50.68 * pow(l,2) + 147.569 * l;
}

double d_box_lid_size(double l) {
    // 4 * pow(l,3) - 55.84*pow(l,2) + 165.505*l;
    return 147.5689 - 101.36*l + 12*pow(l,2);
}
