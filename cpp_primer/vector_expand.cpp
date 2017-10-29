# include <iostream>
# include <vector>

using namespace std;

int main() {
    vector<int> tmp;
    cout << tmp.size() << tmp.capacity() << endl;

    for (int i = 1; i < 10000001; ++i) {
        tmp.push_back(i);
        if (i == tmp.capacity())
            cout << i << " size:" << tmp.size() << " capacity:" << tmp.capacity() << endl;
    }

    return 0;
}
