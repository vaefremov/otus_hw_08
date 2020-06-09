#include <iostream>
#include <string>
#include <vector>
#include <map>


std::ostream& operator<<(std::ostream& out, std::map<std::string, int> const& m)
{
    for(auto const& s:m)
    {
        if(s.second > 1)
            std::cout << s.first  << std::endl;
    }
    return out;
}

int main()
{
    size_t n;
    std::cin >> n;
    std::map<std::string, int> m;
    for (size_t i = 0; i < n; i++)
    {
        std::string tmp;
        std::cin >> tmp;
        m[tmp]++;
    }
    std::cout << m;
}