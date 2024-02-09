int foo(int x) {
	return 1 + x;
}

int arr(int x[]) {
	return x[2];
}
int main() {
	const int c = 3;
	int y = foo(3);
	int x[y];

	int w = arr(x);
}
