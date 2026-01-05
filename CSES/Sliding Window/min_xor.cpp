
#include <iostream>
#include <vector>
#include <climits>
// Numbers generate karo → window ka minimum rakho → har min ko XOR karo → ek final number print karo.
using namespace std;

int main()
{
    // n- number of elements , k - window size
    int n, k;
    cin >> n >> k;

    // four integers x, a, b and c: the input generator parameters
    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<long long> window(k);
    long long sum = 0;
    long long xr = 0;

    // first element
    window[0] = x;
    sum += x;

    // generate first k elements
    for (int i = 1; i < k; i++)
    {
        x = (a * x + b) % c;
        window[i] = x;
        sum += x;
    }

    xr = sum;

    int idx = 0;

    // sliding window
    for (int i = k; i < n; i++)
    {
        x = (a * x + b) % c;

        sum -= window[idx];
        window[idx] = x;
        sum += x;

        idx = (idx + 1) % k;
        xr ^= sum;
    }

    cout << xr;
    return 0;
}
