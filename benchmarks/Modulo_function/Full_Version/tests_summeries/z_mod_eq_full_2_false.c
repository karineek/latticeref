// z_mod_eq     //Lemma Zmod_eq a b : b>0 -> a mod b = a - (a/b)*b

int nondet();
int mod(int a, int n) { return a % n; }
//int z_mod_eq_full (int a, int n) { return mod(a,n);}

int main()	
{
    int a=nondet();
    int b=nondet();
    __CPROVER_assume(b != 0);

    int m = mod(a,b);	
    //__CPROVER_assume(z_mod_eq_full (a,b) == m);  

    assert(m != mod(a - ((a/b)*b),b) );	
}
