#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <algorithm>

std::ostream& operator<<(std::ostream& out, std::vector<std::string> const& v)
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(out, "\n"));
    return out;
}

int main()
{
    size_t n;
    std::cin >> n;
    std::map<char, std::vector<std::string>> hier;
    for (size_t i = 0; i < n; i++)
    {
        std::string tmp;
        std::cin >> tmp;
        hier[tmp[0]].push_back(tmp);
    }
    char c;
    std::cin >> c;
    if(hier.find(c) != hier.end())
        std::cout << hier[c] << std::endl;
}