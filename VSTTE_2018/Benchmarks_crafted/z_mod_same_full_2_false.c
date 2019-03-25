int main()
{
    int a,m;
    __CPROVER_assume(a != 0);

    int b = a;
    m = a%b;

    assert(m<0);
}
