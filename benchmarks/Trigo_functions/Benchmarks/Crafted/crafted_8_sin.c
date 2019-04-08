#include <math.h>

/* Taken from TACAS 2017 Benchmarks: sin_interpolated_bigrange_loose_true-unreach-call.c */
extern double __VERIFIER_nondet_double();
extern void __VERIFIER_assume(int expression);



const double T[362] = {
  0.00000000000000, 0.01745240643728, 0.03489949670250, 0.05233595624294,
  0.06975647374413, 0.08715574274766, 0.10452846326765, 0.12186934340515,
  0.13917310096007, 0.15643446504023, 0.17364817766693, 0.19080899537654,
  0.20791169081776, 0.22495105434386, 0.24192189559967, 0.25881904510252,
  0.27563735581700, 0.29237170472274, 0.30901699437495, 0.32556815445716,
  0.34202014332567, 0.35836794954530, 0.37460659341591, 0.39073112848927,
  0.40673664307580, 0.42261826174070, 0.43837114678908, 0.45399049973955,
  0.46947156278589, 0.48480962024634, 0.50000000000000, 0.51503807491005,
  0.52991926423320, 0.54463903501503, 0.55919290347075, 0.57357643635105,
  0.58778525229247, 0.60181502315205, 0.61566147532566, 0.62932039104984,
  0.64278760968654, 0.65605902899051, 0.66913060635886, 0.68199836006250,
  0.69465837045900, 0.70710678118655, 0.71933980033865, 0.73135370161917,
  0.74314482547739, 0.75470958022277, 0.76604444311898, 0.77714596145697,
  0.78801075360672, 0.79863551004729, 0.80901699437495, 0.81915204428899,
  0.82903757255504, 0.83867056794542, 0.84804809615643, 0.85716730070211,
  0.86602540378444, 0.87461970713940, 0.88294759285893, 0.89100652418837,
  0.89879404629917, 0.90630778703665, 0.91354545764260, 0.92050485345244,
  0.92718385456679, 0.93358042649720, 0.93969262078591, 0.94551857559932,
  0.95105651629515, 0.95630475596304, 0.96126169593832, 0.96592582628907,
  0.97029572627600, 0.97437006478524, 0.97814760073381, 0.98162718344766,
  0.98480775301221, 0.98768834059514, 0.99026806874157, 0.99254615164132,
  0.99452189536827, 0.99619469809175, 0.99756405025982, 0.99862953475457,
  0.99939082701910, 0.99984769515639, 1.00000000000000, 0.99984769515639,
  0.99939082701910, 0.99862953475457, 0.99756405025982, 0.99619469809175,
  0.99452189536827, 0.99254615164132, 0.99026806874157, 0.98768834059514,
  0.98480775301221, 0.98162718344766, 0.97814760073381, 0.97437006478524,
  0.97029572627600, 0.96592582628907, 0.96126169593832, 0.95630475596304,
  0.95105651629515, 0.94551857559932, 0.93969262078591, 0.93358042649720,
  0.92718385456679, 0.92050485345244, 0.91354545764260, 0.90630778703665,
  0.89879404629917, 0.89100652418837, 0.88294759285893, 0.87461970713940,
  0.86602540378444, 0.85716730070211, 0.84804809615643, 0.83867056794542,
  0.82903757255504, 0.81915204428899, 0.80901699437495, 0.79863551004729,
  0.78801075360672, 0.77714596145697, 0.76604444311898, 0.75470958022277,
  0.74314482547739, 0.73135370161917, 0.71933980033865, 0.70710678118655,
  0.69465837045900, 0.68199836006250, 0.66913060635886, 0.65605902899051,
  0.64278760968654, 0.62932039104984, 0.61566147532566, 0.60181502315205,
  0.58778525229247, 0.57357643635105, 0.55919290347075, 0.54463903501503,
  0.52991926423320, 0.51503807491005, 0.50000000000000, 0.48480962024634,
  0.46947156278589, 0.45399049973955, 0.43837114678908, 0.42261826174070,
  0.40673664307580, 0.39073112848927, 0.37460659341591, 0.35836794954530,
  0.34202014332567, 0.32556815445716, 0.30901699437495, 0.29237170472274,
  0.27563735581700, 0.25881904510252, 0.24192189559967, 0.22495105434387,
  0.20791169081776, 0.19080899537654, 0.17364817766693, 0.15643446504023,
  0.13917310096007, 0.12186934340515, 0.10452846326765, 0.08715574274766,
  0.06975647374413, 0.05233595624294, 0.03489949670250, 0.01745240643728,
  0.00000000000000, -0.01745240643728, -0.03489949670250, -0.05233595624294,
  -0.06975647374412, -0.08715574274766, -0.10452846326765, -0.12186934340515,
  -0.13917310096007, -0.15643446504023, -0.17364817766693, -0.19080899537654,
  -0.20791169081776, -0.22495105434386, -0.24192189559967, -0.25881904510252,
  -0.27563735581700, -0.29237170472274, -0.30901699437495, -0.32556815445716,
  -0.34202014332567, -0.35836794954530, -0.37460659341591, -0.39073112848927,
  -0.40673664307580, -0.42261826174070, -0.43837114678908, -0.45399049973955,
  -0.46947156278589, -0.48480962024634, -0.50000000000000, -0.51503807491005,
  -0.52991926423320, -0.54463903501503, -0.55919290347075, -0.57357643635105,
  -0.58778525229247, -0.60181502315205, -0.61566147532566, -0.62932039104984,
  -0.64278760968654, -0.65605902899051, -0.66913060635886, -0.68199836006250,
  -0.69465837045900, -0.70710678118655, -0.71933980033865, -0.73135370161917,
  -0.74314482547739, -0.75470958022277, -0.76604444311898, -0.77714596145697,
  -0.78801075360672, -0.79863551004729, -0.80901699437495, -0.81915204428899,
  -0.82903757255504, -0.83867056794542, -0.84804809615643, -0.85716730070211,
  -0.86602540378444, -0.87461970713940, -0.88294759285893, -0.89100652418837,
  -0.89879404629917, -0.90630778703665, -0.91354545764260, -0.92050485345244,
  -0.92718385456679, -0.93358042649720, -0.93969262078591, -0.94551857559932,
  -0.95105651629515, -0.95630475596304, -0.96126169593832, -0.96592582628907,
  -0.97029572627600, -0.97437006478524, -0.97814760073381, -0.98162718344766,
  -0.98480775301221, -0.98768834059514, -0.99026806874157, -0.99254615164132,
  -0.99452189536827, -0.99619469809175, -0.99756405025982, -0.99862953475457,
  -0.99939082701910, -0.99984769515639, -1.00000000000000, -0.99984769515639,
  -0.99939082701910, -0.99862953475457, -0.99756405025982, -0.99619469809175,
  -0.99452189536827, -0.99254615164132, -0.99026806874157, -0.98768834059514,
  -0.98480775301221, -0.98162718344766, -0.97814760073381, -0.97437006478524,
  -0.97029572627600, -0.96592582628907, -0.96126169593832, -0.95630475596304,
  -0.95105651629515, -0.94551857559932, -0.93969262078591, -0.93358042649720,
  -0.92718385456679, -0.92050485345244, -0.91354545764260, -0.90630778703665,
  -0.89879404629917, -0.89100652418837, -0.88294759285893, -0.87461970713940,
  -0.86602540378444, -0.85716730070211, -0.84804809615643, -0.83867056794542,
  -0.82903757255504, -0.81915204428899, -0.80901699437495, -0.79863551004729,
  -0.78801075360672, -0.77714596145697, -0.76604444311898, -0.75470958022277,
  -0.74314482547739, -0.73135370161917, -0.71933980033865, -0.70710678118655,
  -0.69465837045900, -0.68199836006250, -0.66913060635886, -0.65605902899051,
  -0.64278760968654, -0.62932039104984, -0.61566147532566, -0.60181502315205,
  -0.58778525229247, -0.57357643635105, -0.55919290347075, -0.54463903501503,
  -0.52991926423321, -0.51503807491005, -0.50000000000000, -0.48480962024634,
  -0.46947156278589, -0.45399049973955, -0.43837114678908, -0.42261826174070,
  -0.40673664307580, -0.39073112848927, -0.37460659341591, -0.35836794954530,
  -0.34202014332567, -0.32556815445716, -0.30901699437495, -0.29237170472274,
  -0.27563735581700, -0.25881904510252, -0.24192189559967, -0.22495105434387,
  -0.20791169081776, -0.19080899537654, -0.17364817766693, -0.15643446504023,
  -0.13917310096007, -0.12186934340515, -0.10452846326765, -0.08715574274766,
  -0.06975647374413, -0.05233595624294, -0.03489949670250, -0.01745240643728,
  0, 0
};


double SIN_0_180(double x) 
{
  double dx, i_dx, v_inf;
  double v_sup;
  int i;
  dx = 2*x;
  i = dx; 
  i_dx = i;
  v_inf = T[i]; 
  v_sup = T[i+1];
  return v_inf + (dx - i_dx) * (v_sup - v_inf); 
}

double SIN_180(double x) 
{
  if (x<0) return -SIN_0_180(-x);
  else return SIN_0_180(x); 
}

double SIN_POS(double x) 
{
  if (x>180) return SIN_180(x-360.*(int)((x+180.)/360.));
  else return SIN_180(x); 
}

double SIN(double x) 
{
  if (x<0) return -SIN_POS(-x);
  else return SIN_POS(x); 
}

/* END ADDED CODE FROM TACAS BENCHMARKS */


void main()
{
    double x;
    __CPROVER_assume(0 < x); 
    __CPROVER_assume(x < 180); 

    double val_sin = SIN(x);

    assert(0 < val_sin); // UNSAT
    assert(0 == val_sin); // SAT
    assert(0 > val_sin); // SAT
    // 0 < x -> x < PI -> 0 < sin x.
}
