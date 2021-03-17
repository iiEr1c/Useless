#include <functional>
#include <iostream>
using namespace std;

template <typename F>
struct Y
{
    Y(F f) : m_f(f) {}

template <typename T>
    auto operator()(T&& t) const
    {
        return m_f(*this, forward<T>(t));
    }
    F m_f;
};

template <typename F>
Y<F> fix(F&& f)
{
    return Y<F>(forward<F>(f));
}

int main()
{
    auto f = fix([] (auto f, int n) -> int {
                if (n == 0)
                    return 1;
                return n * f(n-1);
                });
    cout << f(5) << endl;
    return 0;
}