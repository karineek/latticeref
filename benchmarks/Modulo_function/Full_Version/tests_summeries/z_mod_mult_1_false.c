//z_mod_mult		//forall a b, (a*b) mod b = 0

int nondet();
int mod(int a, int n) { return a % n; }
int z_mod_mult(int a, int n) { return mod(a,n);}

int main()	
{
    int b = nondet();
    __CPROVER_assume(b != 0);

    __CPROVER_assume(b < 99999999);
    __CPROVER_assume(b > -99999999);

    int m = mod(5*b,b);	
    __CPROVER_assume(z_mod_mult(5*b,b) == m);  

     assert(m == 5);	
}
