int nondet();

void main()
{
    unsigned int a , b;
    unsigned int m = (4%b);

    __CPROVER_assume(b > 0 && a >= 0);
    assert(m <= 4);
}

