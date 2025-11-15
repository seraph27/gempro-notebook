

#include <iostream>

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

// begin template //
struct Fraction {
    int a, b;
    Fraction() : a(0), b(1) {}
    Fraction(int x) : a(x), b(1) {}
    Fraction(int x, int y) : a(x), b(y) { norm(*this); }
    friend std::ostream& operator << (std::ostream &out, const Fraction &n) {
        return out << n.a << '/' << n.b;
    }
    friend void norm(Fraction &X) {
        int g = gcd(X.a, X.b);
        X.a /= g, X.b /= g;
    }
    friend bool operator == (const Fraction &A, const Fraction &B) { return A.a == B.a && A.b == B.b; }
    friend bool operator != (const Fraction &A, const Fraction &B) { return A.a != B.a || A.b != B.b; }
    Fraction& operator += (const Fraction &other) {
        int L = lcm(b, other.b);
        a = L/b*a + L/other.b*other.a;
        b = L;
        norm(*this);
        return *this;
    }
    Fraction& operator -= (const Fraction &other) {
        int L = lcm(b, other.b);
        a = L/b*a - L/other.b*other.a;
        b = L;
        norm(*this);
        return *this;
    }
    Fraction &operator *= (const Fraction &other) {
        a *= other.a, b *= other.b;
        norm(*this);
        return *this;
    }
    Fraction operator /= (const Fraction &other) {
        a *= other.b, b *= other.a;
        norm(*this);
        return *this;
    }
    friend Fraction pow(Fraction A, int k) {
        Fraction ret(1);
        while (k) {
            if (k&1) ret *= A;
            A = A * A;
            k >>= 1;
        }
        return ret;
    }
    friend Fraction operator + (const Fraction &A, const Fraction &B) { return Fraction(A) += B; }
    friend Fraction operator - (const Fraction &A, const Fraction &B) { return Fraction(A) -= B; }
    friend Fraction operator * (const Fraction &A, const Fraction &B) { return Fraction(A) *= B; }
    friend Fraction operator / (const Fraction &A, const Fraction &B) { return Fraction(A) /= B; }
};
// end template //

