#include <iostream>
#include <string>
#include <vector>
#include <set>


int main()
{
    std::set<int> y_prepod;
    size_t n_prepod;
    std::cin >> n_prepod;
    for (size_t i = 0; i < n_prepod; i++)
    {
        int tmp;
        std::cin >> tmp;
        y_prepod.insert(tmp);
    }
    std::vector<int> y_stud;
    size_t n_stud;
    std::cin >> n_stud;
    for (size_t i = 0; i < n_stud; i++)
    {
        int tmp;
        std::cin >> tmp;
        y_stud.push_back(tmp);
    }
    int grade = 0;
    for(auto y: y_stud)
    {
        if(y_prepod.find(y) != y_prepod.end())
            grade++;
    }
    std::cout << grade << std::endl;
}