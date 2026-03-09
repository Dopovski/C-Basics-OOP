#ifndef LECTURES_H
#define LECTURES_H

#include <set>
#include <map>
#include <vector>
#include "Resource.h"

using namespace std;

namespace SoftUni {

    class Lecture {
    public:
        typedef set<Resource> ResourceData;

    private:
        ResourceData data;
        map<ResourceType, int> resourceTypeCount;

    public:
        Lecture &operator<<(const Resource &r) {
            ResourceData::iterator itID = data.find(r);

            if (itID != data.end()) {
                resourceTypeCount[itID->getType()]--;
                data.erase(itID);
            }

            data.insert(r);
            resourceTypeCount[r.getType()]++;

            return *this;
        }

        ResourceData::const_iterator begin() const { return data.begin(); }
        ResourceData::const_iterator end() const { return data.end(); }

        friend vector<ResourceType> &operator<<(vector<ResourceType> &rtMap, const Lecture &L);

        int operator[](ResourceType rt) const {
            auto it = resourceTypeCount.find(rt);
            if (it == resourceTypeCount.end()) return 0;
            return it->second;
        }
    };

    vector<ResourceType> &operator<<(vector<ResourceType> &rtMap, const Lecture &L) {
        for (const pair<ResourceType, int> &cur : L.resourceTypeCount) {
            if (cur.second != 0) {
                rtMap.push_back(cur.first);
            }
        }
        return rtMap;
    }

}

#endif
