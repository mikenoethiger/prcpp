#include "pgm.h"
#include <fstream>
#include <sstream>

bool ReadNextToken(std::ifstream* stream, std::string* token) {
  do {
    std::getline(*stream, *token);
    if (stream->good() == false) {
      return false;
    }
  } while ((*token)[0] == '#');
}

bool PGM::ReadASCII(const std::string& filename) {
  
}