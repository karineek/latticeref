int main()	
{
    unsigned int a = nondet();
    unsigned int b = nondet();

    __CPROVER_assume(0 == a || 0 < a);
    __CPROVER_assume(0 < b);

    int m = a%b;	

    assert(m <= a);	
}
