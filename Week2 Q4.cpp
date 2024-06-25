/*Question:
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).*/

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0; // x^0 = 1
        }
        
        // For negative exponent, convert to positive and take reciprocal
        if (n < 0) {
            x = 1 / x;
            // Handle potential overflow for INT_MIN case
            return (n % 2 == 0) ? myPow(x * x, -(n / 2)) : x * myPow(x * x, -(n / 2));
        }
        
        return (n % 2 == 0) ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
    }
};