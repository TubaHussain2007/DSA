class Solution {
public:
    double power(double x, long num) {
        if (num == 0)
            return 1.0;
        if (num == 1)
            return x;

        if (num % 2 == 0) {
            return power(x * x, num / 2);
        }
        return x * power(x, num - 1);
    }
    double myPow(double x, int n) {
        long long num = n;
        if (n < 0)
            return (1.0 / power(x, -1 * num));
        else
            return power(x, num);
    }
};