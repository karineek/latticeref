int main()
{
    int a,m;
    __CPROVER_assume(a != 0);

    m = a%a;

    assert(m<0);
}
