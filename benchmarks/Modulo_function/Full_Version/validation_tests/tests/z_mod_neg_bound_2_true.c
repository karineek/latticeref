int nondet();

int main()
{
    int a,m;
    m = a%(-99);

     assert(m<=0 && m>(-99));
}
