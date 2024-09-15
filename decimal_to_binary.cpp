long long decimal_to_binary(int n){
    long long bin = 0;
    long long i=1;
    int rem;
    while(n!=0){
        rem = n % 2;
        n /=  2;
        bin += rem*i;
        i *= 2;
    }
}