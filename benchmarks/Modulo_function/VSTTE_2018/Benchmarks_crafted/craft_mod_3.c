int main()
{
    int a,b;
    __CPROVER_assume(b!=0);	

    int m = a%b;
    int temp1 = a/b;
    int temp2 = temp1*b;
    int m_p = a - temp2;

    assert(m == m_p); // True
}
