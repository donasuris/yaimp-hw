#include <iostream>
using namespace std;

int main()
{
	int N, k;
	cin >> N >> k; //расстояние км между пунктами, расстояние км способное проехать автомобиль
	int S, cur, x; 
	int next = 0, res = 0;
	cin >> S; //кол-во бензоколонок
	cur = next = k;

	for (int i = 0; i < S && cur < N; i++) {
		cin >> x; //бензоколонки
		if (cur < x) {
			if (next < x) {
				res = -1;
				break;
			}
			res++;
			cur = next;
		}
		next = x + k;
	}

	if (cur < N) {
		if (next >= N) res++;
		else res = -1;
	}

	cout << res;
}