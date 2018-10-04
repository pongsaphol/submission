#include <filesystem>
#include <bits/stdc++.h>
using namespace std;
namespace fs = std::filesystem;

int main()
{
    std::string path = "~/Documents/submission/Codeforces/1052/data_train";
    for (auto & p : fs::directory_iterator(path))
    {
        cout << p << endl;
    }
}
