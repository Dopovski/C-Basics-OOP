#ifndef SONGCOMPARATOR_H
#define SONGCOMPARATOR_H

#include "Song.h"

class SongLengthComparator {
public:
	bool operator()(const Song& a, const Song& b) const {
		return a.getLengthSeconds() < b.getLengthSeconds();
	}
};

#endif
