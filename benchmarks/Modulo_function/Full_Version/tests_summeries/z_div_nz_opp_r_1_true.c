//z_div_nz_opp_r		// forall a b:Z, a mod b <> 0 -> a/(-b) = -(a/b)-1. - only under mod!

int nondet();
int mod(int a, int n) { return a % n; }
//int z_div_nz_opp_r (int a, int n) { return mod(a,n);}

int main()	
{
    int a=nondet();
    int b=nondet();

    int m = mod(a,b);	
    __CPROVER_assume(b != 0);
    //__CPROVER_assume(z_div_nz_opp_r(a,b) == m);  
    __CPROVER_assume(m != 0);

    int m1 = mod(a/(-b),b); 
    int m2 = mod(-(a/b)-1,b);
    assert(m1 == m2);	
}
