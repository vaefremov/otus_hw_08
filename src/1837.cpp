#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>
#include <array>


using Team_t = std::array<std::string, 3>;
using Dist_t = std::map<std::string, int>;
using OneTeam_t = std::map<std::string, std::set<std::string>>;

std::istream& operator>>(std::istream& in, Team_t& team)
{
    in >> team[0] >> team[1] >> team[2];
    return in;
}

std::ostream& operator<<(std::ostream& out, Dist_t const& dist)
{
    for(auto e: dist)
    {
        out << e.first << " ";
        if(e.second < 0)
        {
            out << "undefined";
        }
        else
        {
            out << e.second;
        }
        out << std::endl;
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, std::set<std::string> const& s)
{
    for(auto& m:s)
    {
        out << m << " ";
    }
    return out;
}


std::ostream& operator<<(std::ostream& out, Team_t const& s)
{
    for(auto& m:s)
    {
        out << m << " ";
    }
    return out;
}

Dist_t compute_dist(std::string const& main_name, OneTeam_t & one_team)
{
    Dist_t res;
    for(auto& t:one_team)
    {
        res[t.first] = -1;
    }
    std::queue<std::string> to_process;
    if(one_team.count(main_name) > 0)
    {
        to_process.push(main_name);
        res[main_name] = 0;
    }
    while(to_process.size())
    {
        std::string cur_mem = to_process.front();
        to_process.pop();
        for(auto const& m: one_team[cur_mem])
        {
            if(res[m] < 0)
            {
                res[m] = res[cur_mem]+1;
                to_process.push(m);
            }
        }
    }
    return res;
}


int main()
{
    size_t n;
    std::cin >> n;
    std::vector<Team_t> teams;
    for (size_t i = 0; i < n; i++)
    {
        Team_t t;
        std::cin >> t;
        teams.push_back(t);
    }
    OneTeam_t in_one_team;
    for(auto const& t: teams) 
    {
        for(auto& m1: t)
        {
            for(auto& m2: t)
            {
                if(m1 != m2)
                {
                    in_one_team[m1].insert(m2);
                    in_one_team[m2].insert(m1);
                }
            }
        }
    }
    Dist_t res = compute_dist("Isenbaev", in_one_team);
    std::cout << res;
}