//simple_mod_28_false.c
int inner_loop_mod(int _n, int _res);
void main() 
{
  int n, res_mod;
  while (1==1) 
  {
     __CPROVER_assume(n != 0); 
     res_mod = inner_loop_mod(n, res_mod);
     assert(res_mod >= n); 
  }
}

int inner_loop_mod(int _n, int _res)
{
     int res = _res % _n; 
     __CPROVER_assume(res != 0);
     return res;
}
