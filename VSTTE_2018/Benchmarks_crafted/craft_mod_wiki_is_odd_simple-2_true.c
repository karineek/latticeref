unsigned is_odd_wiki(unsigned i) 
{
   return ((i%2) == 1);
}

// Main test
int main()
{
    unsigned a,b;
    __CPROVER_assume(b < 100);

    // Is odd?
    //a = b*2;
    int n;a=0;for (int i=0;i<n;i++)a+=2;
    
    unsigned ret = is_odd_wiki(a);
    assert(ret == 0 || ret == 1);

    assert(!ret);
}

