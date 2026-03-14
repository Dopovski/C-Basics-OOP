#pragma once
#include "NoteName.h"
#include <sstream>
 class SolfegeNoteNaming {
 private:

 public:
     NoteName operator()(const std::string & name) const;
 };
