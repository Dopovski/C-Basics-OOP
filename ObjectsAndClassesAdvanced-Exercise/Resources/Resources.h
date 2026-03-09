#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>
#include <string>
#include "ResourceType.h"

using namespace std;

namespace SoftUni {

    class Resource {
    private:
        int id;
        ResourceType rt;
        string link;

    public:
        int getId() const { return id; }
        ResourceType getType() const { return rt; }
        const string getLink() const { return link; }

        bool operator<(const Resource &other) const {
            return this->id < other.id;
        }

        friend istream &operator>>(istream &is, Resource &r);
    };

    istream &operator>>(istream &is, Resource &r) {
        string resourceType;

        is >> r.id >> resourceType;
        getline(is >> ws, r.link);

        if (resourceType == "Presentation") {
            r.rt = ResourceType::PRESENTATION;
        }
        else if (resourceType == "Demo") {
            r.rt = ResourceType::DEMO;
        }
        else if (resourceType == "Video") {
            r.rt = ResourceType::VIDEO;
        }
        else {
            r.rt = (ResourceType)(ResourceType::VIDEO + 1);
        }

        return is;
    }

    ostream &operator<<(ostream &os, const Resource &r) {
        os << r.getId() << " " << r.getType() << " " << r.getLink();
        return os;
    }

}

#endif
