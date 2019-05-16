//z_mod_2_r  //a mod 2 \in {0,1}

int nondet();
int mod(int a, int n) { return a % n; }
int z_mod_2_r(int a, int n) { return mod(a,n);}

int main()	
{
    int a,b,m;
    __CPROVER_assume(a >= 0);

    m = mod(a,2);	
    __CPROVER_assume(z_mod_2_r(a,2) == m);  

    assert(m != 0);	
}
