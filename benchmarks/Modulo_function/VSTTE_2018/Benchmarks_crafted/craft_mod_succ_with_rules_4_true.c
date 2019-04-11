// Rules for the lattice
// 4. x mod x = 0
int main()
{
    int a,b,m;

    __CPROVER_assume(b != 0);
    a = b;
    m = a%b;

    assert(m == 0);
}

