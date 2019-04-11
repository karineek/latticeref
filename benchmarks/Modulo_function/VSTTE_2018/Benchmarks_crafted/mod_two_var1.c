unsigned f(unsigned i, unsigned j)
{
   return ((i%j) >= j);
}

int main()
{
    unsigned a,b;
    if (b>100 || b < 1) return;

    assert(!f(a,b)); //safe only in prop 
}

