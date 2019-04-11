int main()
{
    int a;
    int b;

    __CPROVER_assume(b!=0);
    __CPROVER_assume(b>0);
    __CPROVER_assume(b<100); 
    __CPROVER_assume(a!=0);
    __CPROVER_assume(a>0);
    __CPROVER_assume(a<100); 

    int m = a%b;
    int temp1 = a/b;
    int temp2 = temp1*b;
    int m_p = a - temp2;	
    assert(m == m_p);
}
