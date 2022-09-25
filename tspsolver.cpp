#include "tspsolver.hpp"

TSPSolver::TSPSolver(ListOfPoints &list) {
  m_list=list;
}

//calculates the added distance from adding a point in between points at j and j+1
float added_distance(TSPCycle &solution, ListOfPoints &list, int j,int i){
  float dis1=solution.getPointAt(j).getDistance(list.getPointAt(i));
  float dis2=solution.getPointAt(j+1).getDistance(list.getPointAt(i));
  float dis3=solution.getPointAt(j).getDistance(solution.getPointAt(j+1));

  return dis1+dis2-dis3;

}

//calculates distance from adding point in between the first and last points in m_solution
float added_dis_firstlast(TSPCycle &solution, ListOfPoints &list, int j,int i){
  float dis1=solution.getPointAt(j).getDistance(list.getPointAt(i));
  float dis2=solution.getPointAt(0).getDistance(list.getPointAt(i));
  float dis3=solution.getPointAt(j).getDistance(solution.getPointAt(0));

  return dis1+dis2-dis3;
  
}

void TSPSolver::solve() {
  m_solution=TSPCycle();

  if(m_list.getSize()<=1){
    m_solution.addPoint(m_list.getPointAt(0));
    return;
  }

  m_solution.addPoint(m_list.getPointAt(0));
  m_solution.addPoint(m_list.getPointAt(1));
  m_solution.addPoint(m_list.getPointAt(2));
  
  for(int i=3;i<m_list.getSize();i++){
    //keep track of where to add the point 
    int add_after=0;
    //calculates the added distance by adding the new 
    //point in between the first two points 
    float min_dis=added_distance(m_solution,m_list,0,i);
    
    //cout<<"min_dis before for loop is:"+to_string(min_dis)<<endl;
    for(int j=1;j<m_solution.getSize();j++){
      //starts from j=1 because we already calculated between the first two
      float dis=added_distance(m_solution,m_list,j,i);
      //if the added point is inbtween the last and first point:
      //calculate it separately 
      if(j==m_solution.getSize()-1)
        dis=added_dis_firstlast(m_solution,m_list,j,i);

      //cout<<"dis in for loop is:"+to_string(dis)<<endl;
      //if the dis is less than the min dis update 
      if (dis<=min_dis){
        min_dis=dis;
        add_after=j;
      }
    }
    //cout<<"adding after: "+to_string(add_after)<<endl;
    m_solution.addAfter(m_list.getPointAt(i),m_solution.getPointAt(add_after).getName());
  }
}

TSPCycle& TSPSolver::getSolution() {
  // currently returns an empty cycle
  return m_solution;
}

