#include "Silnice.h"

#include <deque>
#include <iostream>


Silnice::Silnice(TerrainMap& m, std::string name_in, Point start_in, Point finish_in) : Path(m, name_in,  start_in,  finish_in){};

bool Silnice::find() {
    Matrix<float> distMatrix = Matrix<float>(256, 256);  //init of matrix of distances
    distMatrix.zero();
    Matrix<Point> prevMatrix = Matrix<Point>(256, 256);  //init of matrix of previously visited points
    std::deque<Point> queueToCheck; //queue of points to check
    queueToCheck.push_front(start);  //uses start point as the first point to perform pathfindig from
    Point pt;   //the point we are currently examining
    while(queueToCheck.size() != 0){
       pt = queueToCheck.back();    //retrieve the point to examine from queue
       for(int dx = -1; dx < 2; dx++){  //for all neighbouring points
            for(int dy = -1; dy < 2; dy++){
                if(dst(dx, dy) != 0){ //to exclude the point being examined
                    if(map.validCoords(Point(pt.x + dx, pt.y +dy)) && (distMatrix(pt.x + dx, pt.y +dy) + dst(dx,dy) < distMatrix(pt.x + dx, pt.y +dy) || distMatrix(pt.x + dx, pt.y +dy) == 0)){
                        if((map.alt(pt.x + dx, pt.y +dy) > 0 &&  abs(map.alt(pt.x + dx, pt.y +dy) - map.alt(pt)) < 60)|| map.alt(pt.x + dx, pt.y +dy) == map.alt(finish)){
                            distMatrix(pt.x + dx, pt.y +dy) += dst(dx,dy);   //add current distance to the neighbouring point
                            prevMatrix(pt.x + dx, pt.y +dy) = pt;   //save current point to as previous for this neighbouring point
                            queueToCheck.push_front(Point(pt.x + dx, pt.y + dy));   //add neighbouring point to queue
                        }
                    }
                }
            }
       }
       queueToCheck.pop_back(); //get rid of current point
    }

    path.push_back(start);  //saves start point as the first point of path
    path.push_back(finish);  //saves start point as the first point of path
    Point prevpt = prevMatrix(finish);
    while(prevpt != start){
        path.insert(path.begin() + 1, prevpt);
        prevpt = prevMatrix(prevpt);
    }

    return true;
}