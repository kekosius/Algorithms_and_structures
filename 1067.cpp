#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

struct Dir {
    map<string, Dir*> sub_dirs;
};

Dir roots[50001];
long root_dir_num = 1, n;

Dir* new_dir(Dir* parent, string child_name)
{
    auto& d = parent->sub_dirs[child_name];
    if (!d) d = &roots[root_dir_num++];
    return d;
}

void print_rec(Dir* roots, string tabs = "")
{
    for (auto root_dir : roots->sub_dirs)
    {
        cout << tabs << root_dir.first << endl;
        print_rec(root_dir.second, tabs + " ");
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str, dirstr;
        cin >> str;
        stringstream ss(str);
        Dir* dir = &roots[0];

        while (getline(ss, dirstr, '\\'))
            dir = new_dir(dir, dirstr);
    }

    stringstream out;
    print_rec(&roots[0]);
}




//
// Created by kekos on 06.04.2021.
//

