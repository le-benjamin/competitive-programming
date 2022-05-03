int gcd (int a, int b) { // a >= b
    /* python has this function built in */
    /* lcm = b*gcd(a,b) */
    if (b == 0) return a;
    return gcd(b,a%b);
}