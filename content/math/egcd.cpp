using i64 = long long;

// begin template //
i64 egcd(i64 a, i64 b, i64 &x, i64 &y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	i64 g = egcd(b, a % b, y, x);
	y -= (a / b) * x;
	return g;
}
// end template //
