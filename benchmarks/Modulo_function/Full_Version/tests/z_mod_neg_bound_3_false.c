int nondet();

int main()
{
    int a,b,m;
    m = (a%b);
    __CPROVER_assume(b < 0);

     assert(m>1);
}
