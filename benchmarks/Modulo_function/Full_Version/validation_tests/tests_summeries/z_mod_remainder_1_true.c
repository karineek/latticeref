//z_mod_remainder	        //b<>0 -> Remainder (a mod b) b

int nondet();
int mod(int a, int n) { return a % n; }
int z_mod_remainder(int a, int n) { return mod(a,n);}

int main()	
{
    int a,b,m;
    __CPROVER_assume(b != 0);
    m = mod(a,b);	
    __CPROVER_assume(z_mod_remainder(a,b) == m);  

     assert(m < b || b < 0);	
}
