int main()	
{
    int a=nondet();
    int b=nondet();
    __CPROVER_assume(b >= 1);

    int m = a%b;	

    assert(m != (a - ((a/b)*b)) );	
}
