int main()
{
    int a;
    int b=5;

    int m = a%5;
    int temp1 = a/5;
    int temp2 = temp1*5;
    int m_p = a - temp2;	
    assert(m == m_p); // True, but not in lra
}
