#include <random>
#include "utility_funcs.h"

int generate_random_number(int lhs, int rhs){
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> distr(lhs, rhs);
   return distr(gen);
}