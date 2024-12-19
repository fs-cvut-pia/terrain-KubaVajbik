#ifndef LETADLO_H
#define LETADLO_H

#include "TerrainMap.h"
#include "Path.h"

class Letadlo : public Path {
    public:
        Letadlo(TerrainMap& m, std::string name_in, Point start_in, Point finish_in);
        bool find();
};

#endif