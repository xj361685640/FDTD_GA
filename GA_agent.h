#ifndef GA_AGENT_H_
#define GA_AGENT_H_

#define _USE_MATH_DEFINES
#include <cmath>
#include "fdtd3d.h"

double fdtd_calc(perturbation, date, geocoordinate, 
                int Number_of_observation, geocoordinate* Position_of_observation,
                double* Magnitude);

void sort_Individual(int Num_Individual, double* score, bool* chromosome);

double* make_roulette(int Num_Individual, double* score);

void Cross_over(int Head_Index, int* Index_of_Individual, 
                bool* Child_Chromosome, bool* Parent_Chromosome);

void Mutation(int Num_of_Elete, int Num_of_Individual,
                double Incidence_of_Mutation, bool* Child_Chromosome);

int b2i(bool* Binary_Array, int Length_of_Array);

double b2d(bool* Binary_Array, int Length_of_Array,
            double Minimum_of_Parameter, double Parameter_Step);

/* The num of parameters */
constexpr int Num_parameter { 7 };

/* The num of bit (location, range, enhancement) */
constexpr int Nbit_enhance { 4 };
constexpr int Nbit_alt{ 3 };
constexpr int Nbit_th{ 7 };
constexpr int Nbit_phi{ 10 };
constexpr int Nbit_sigr{ 3 };
constexpr int Nbit_sigth{ 6 };
constexpr int Nbit_sigphi{ 6 };

constexpr int Nbit_total
{ Nbit_enhance + Nbit_alt + Nbit_th
+ Nbit_th + Nbit_sigr + Nbit_sigth + Nbit_sigphi };

// range of enhance //
constexpr double param1_min { 0.0 };
constexpr double param1_max { 15.0 };

constexpr double param2_min { 70.0 };
constexpr double param2_max { 80.0 };

constexpr double param3_min { 0.0 };
constexpr double param3_max { 100.0 };

constexpr double param4_min { k_s };
constexpr double param4_max { k_r };

constexpr double param5_min { 1.0 };
constexpr double param5_max { 2.0 };

constexpr double param6_min { 50.0 };
constexpr double param6_max { 100.0 };

constexpr double param7_min { 50.0 };
constexpr double param7_max { 100.0 };

constexpr double param1_step
{ (param1_max - param1_min)/(std::pow(2.0, Nbit_enhance) - 1) };
constexpr double param2_step
{ (param2_max - param2_min)/(std::pow(2.0, Nbit_alt) - 1) };
constexpr double param3_step
{ (param3_max - param3_min)/(std::pow(2.0, Nbit_th) - 1) };
constexpr double param4_step
{ (param4_max - param4_min)/(std::pow(2.0, Nbit_phi) - 1) };
constexpr double param5_step
{ (param5_max - param5_min)/(std::pow(2.0, Nbit_sigr) - 1) };
constexpr double param6_step
{ (param6_max - param6_min)/(std::pow(2.0, Nbit_sigth) - 1) };
constexpr double param7_step
{ (param7_max - param7_min)/(std::pow(2.0, Nbit_sigphi) - 1) };

constexpr double GA_min[Num_parameter]
= { param1_min, param2_min, param3_min, param4_min,
    param5_min, param6_min, param7_min };

constexpr double GA_max[Num_parameter]
= { param1_max, param2_max, param3_max, param4_max,
    param5_max, param6_max, param7_max };

class GA_agent{
public:
    bool chrom[Nbit_total];
    double score;
    void calc_fdtd_score(void);
};

#endif