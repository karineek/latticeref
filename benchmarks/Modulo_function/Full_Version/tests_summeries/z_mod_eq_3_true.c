// z_mod_eq     //Lemma Zmod_eq a b : b>0 -> a mod b = a - (a/b)*b

int nondet();
int mod(int a, int n) { return a % n; }
//int z_mod_eq (int a, int n) { return mod(a,n);}

int main()	
{
    int a=nondet();
    int b=nondet();
    __CPROVER_assume(b >= 1);

    int m = mod(a,b);	
    //__CPROVER_assume(z_mod_eq(a,b) == m);  

    assert(m == mod(a - ((a/b)*b),b) );	
}
