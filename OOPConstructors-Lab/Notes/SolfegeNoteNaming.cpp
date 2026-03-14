#include "SolfegeNoteNaming.h"

NoteName SolfegeNoteNaming::operator()(const std::string & name) const {
    char noteName;
    if (name == "Do") {
        noteName = 'C';
    }
    else if (name == "Re"){
        noteName = 'D';
    }
    else if (name == "Mi"){
        noteName = 'E';
    }
    else if (name == "Fa"){
        noteName = 'F';
    }
    else if (name == "Sol"){
        noteName = 'G';
    }
    else if (name == "La"){
        noteName = 'A';
    }
    else if (name == "Si"){
        noteName = 'B';
    }
    else {
        noteName = '?';
    }

    return NoteName(noteName);
}
