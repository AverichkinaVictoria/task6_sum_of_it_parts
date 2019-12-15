#include <iostream>
using namespace std;
#include "parts.h"

void Part::describe(void)
{
    cout << "Part " << this->name << " subparts are:\n";
    if (subparts.size() == 0)
        cout << "It has no subparts.\n";
    else
    {
        for (map <Part*,int>::iterator i = subparts.begin(); i != subparts.end(); ++i)
            cout << i->second << " " << i->first->name << "\n";
    }
}

int Part::count_howmany(Part const *p)
{
    int val = 0;
    if (this == p)
        return 1;
    else
    {
        for (map <Part*,int>::iterator i = subparts.begin(); i != subparts.end(); ++i)
            val += i->first->count_howmany(p) * i->second;
        return val;
    }
}

Part *NameContainer::lookup(string const &name)
{
    map <string,Part*>::iterator  i = name_map.find(name);
    if (i == name_map.end())
        name_map[name] = new Part(name);
    return name_map[name];
}

NameContainer::~NameContainer(void)
{
    for (map <string,Part*>::iterator i = name_map.begin(); i != name_map.end(); ++i)
        delete i->second;
}

void add_part(string const &x, int q, string const &y)
{
    Part* prt = partContainer.lookup(x);
    Part* subprt = partContainer.lookup(y);
    prt->subparts[subprt] = q;
}
NameContainer partContainer;
