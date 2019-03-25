// Rules for the lattice
// 2. singed, -b < m < b, b > 0
int main()
{
    int a,b,m;

    b = 10;

    m = a%b;


    char u2 = (m <= 0);
    char l2 = (m >= -9);
    char u1 = (m <= 9);
    char l1 = (m >= 0);
    assert((u1 && l1) || (u2 && l2));
} 
