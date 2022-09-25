#include <iostream>

#include "tspcycle.hpp"

TSPCycle::TSPCycle() {
  // implement me
//  cout << "default TSPCycle constructor" << endl;
}

// returns the length of the cycle
float TSPCycle::getLength() const {
  float cycleLength=0;
  //calculate the distance from the first point up to last
  for(int i=0;i<len-1;i++){
    cycleLength+=m_points[i].getDistance(m_points[i+1]);
  }
  //since its the length of a cycle we also need to 
  //add the distance between the last and first point 
  cycleLength+=m_points[0].getDistance(m_points[len-1]);
  return cycleLength;
}
