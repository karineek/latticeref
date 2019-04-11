// Rules for the lattice
// 1, unsinged, 0 <= m < b, b >0
int main()
{
    unsigned int a,b,m;
    b = 10u;

    m = a%b;
  
    assert(m >=0 && m < 10u);
}
