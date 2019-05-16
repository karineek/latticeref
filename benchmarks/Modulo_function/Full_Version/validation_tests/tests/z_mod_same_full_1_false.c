int nondet();

int main()
{
    int a,m;
    m = (a%a);
    __CPROVER_assume(a != 0);

    assert(m<0);
}
