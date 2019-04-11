int main()	
{
    int a = nondet();
    int b = nondet();
    __CPROVER_assume(b != 0);

    __CPROVER_assume(b < 99999999);
    __CPROVER_assume(b > -99999999);

    int m = a%b;
    int m_p = m%b;

    // Test
    assert(m != m_p);	
}
