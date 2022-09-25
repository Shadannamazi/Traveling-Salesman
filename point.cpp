#include "point.hpp"

float Point::getDistance(const Point &other) const { 
  
  float x_dist = getX()-other.getX();
  //cout<<"first (x,y)= ("+to_string(getX())+","+to_string(getY())+")"<<endl;
  //cout<<"2nd (x,y)= ("+to_string(other.getX())+","+to_string(other.getY())+")"<<endl;
  
  //cout<<"x_dist is:"+to_string(x_dist)<<endl;
  float y_dist = getY()-other.getY();
  
  //cout<<"y_dist is: "+to_string(y_dist)<<endl;
  float result = sqrt(pow(x_dist, 2)+pow(y_dist, 2));
  //cout<<"result: "+to_string(result)<<endl;
  return result;
  
}

string Point::toString() const {
  // examples how to create string from small parts
  string str(m_name);
  str += " = (";
  str += std::to_string(m_x);
  str.append(",").append(std::to_string(m_y)).append(")");
  return str;
}


void Point::printPoint() const {
  cout << toString() << endl;
}

// used for printing Point using << operator.
// For example, the following code will work
// Point origin(0,0,'O');
// cout << origin;
ostream& operator<<(ostream &os, const Point &p) {
  return os << p.toString();
}
