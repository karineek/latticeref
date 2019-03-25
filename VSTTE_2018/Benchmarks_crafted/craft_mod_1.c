int main()
{
    unsigned int a,b;

    __CPROVER_assume(b==10u || (b < 10u)); // eq to b <= 10u
    __CPROVER_assume(b!=0u);   

    unsigned int m = a%b;
    assert(m < 10u); // true, as (0 <= m < 10u)
}
