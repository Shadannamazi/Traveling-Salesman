#include "listofpoints.hpp"


ListOfPoints::ListOfPoints() {
}

void ListOfPoints::addAfter(Point& newPt, string name) {
  int pos=0;
  for(int i=0;i<len;i++){
    if(m_points[i].getName()==name)
      pos=i;
  }
  m_points.insert(m_points.begin()+pos+1,newPt);
  len++;
}

void ListOfPoints::addPoint(Point& newPt)  {
  m_points.push_back(newPt);
  len++;
  
}

Point& ListOfPoints::getPointAt(unsigned int i) {
  return m_points[i];
}

int ListOfPoints::getSize() const {
  return len;
}

void ListOfPoints::printList() const {
  for(int i=0;i<len;i++){
    string x=to_string(m_points[i].getX());
    string y=to_string(m_points[i].getY());
    cout << m_points[i].getName()+" = " + "(" + x+ "," + y+ ")" << endl;
  }
}

void ListOfPoints::draw() const {
  for(int i=0;i<21;i++){
    for(int j=0;j<21;j++){
      bool point=false;
     
      for(int k=0;k<len;k++){
        if(m_points[k].getX()==j && m_points[k].getY()==20-i){
          point=true;
          cout<<m_points[k].getName();
            
          }
        }
      if(!point)
        cout<<"-";
      }
    printf("\n");
  }
}
 
