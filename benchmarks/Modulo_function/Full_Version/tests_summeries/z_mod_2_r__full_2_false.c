//z_mod_2_r_full  //a mod 2 \in {-1,0,1}

int nondet();
int mod(int a, int n) { return a % n; }
int z_mod_2_r_full(int a, int n) { return mod(a,n);}

int main()	
{
    int a,b,m;
    m = mod(a,2);	
    __CPROVER_assume(z_mod_2_r_full(a,2) == m);  

     assert(m > 2);	
}
