// Rules for the lattice
// 5. x mod x = 0 also for unsigned
int main()
{
    unsigned int a,b,m;

    __CPROVER_assume(b > 0u);
    a = b;
    m = a%b;

    assert(m == 0u);
}

