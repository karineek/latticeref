int get_output(int a)
{
    return (a % 5);
}

int main()
{
    int a;
    while(1)
    {
        assert(a < 5);
        a = get_output(a);
	assert(a == 5);
    }
}
