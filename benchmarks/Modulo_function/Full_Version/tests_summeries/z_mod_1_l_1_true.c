//1 mod a = 1

int nondet();
int mod(int a, int n) { return a % n; }
int z_mod_1_l(int a, int n) { return mod(a,n);}

int main()	
{
    int b = nondet();
    int m = mod(1,b);
    __CPROVER_assume(b > 1);	
    __CPROVER_assume(z_mod_1_l(1,b) == m);  

     assert(m == 1);	
}
