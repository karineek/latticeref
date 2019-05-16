int nondet();

int main()
{
    int a,m;
    int b = a;
    m = (a%b);
    __CPROVER_assume(a != 0);

    assert(m==0);
}
