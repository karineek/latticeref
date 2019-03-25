void main()
{
    unsigned int b;
    __CPROVER_assume(b > 0);

    unsigned int m = 4%b;
 
    assert(m == 10);
}
