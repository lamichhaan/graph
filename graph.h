// Name: Angat Lamichhane
//class: CSIS 352
//Assignment 5
//date:04/01/16
// instructor: Dr. Brekke

# ifndef _GRAPH_H_
# define _GRAPH_H_
# include <iostream>
# include <vector>
# include <stdexcept>
# include <iomanip>

using namespace std;

namespace GraphNameSpace
{
  // enum type for directed/undirected graph
  enum direction {DIRECTED,UNDIRECTED};
  // enum type for weighted/unweighted graph
enum mass{WEIGHTED, UNWEIGHTED};
  
  template <class graphType>
  class Graph
  {
  public:
    Graph(direction,mass); 
    // constructor for directed weighted
    // precondition: none
    //postcondition: sets size of vector to store vertices and two dymensional vector 
    // to store edges
   
    Graph(mass,direction); 
    // constructor for weighted and directed
    // precondition: none
    //postcondition: sets size of vector to store vertices and two dymensional vector 
    // to store edges
    // input: enum type mass direction
    
    Graph(direction);
    // constructor for directed and unweighted
    // precondition: none
    //postcondition: sets size of vector to store vertices and two dymensional vector 
    // to store edges
    //input : enum type direction
    Graph(mass); 
    // constructor for undirected and unweighted
    // precondition: none
    //postcondition: sets size of vector to store vertices and two dymensional vector 
    // to store edges
    // input : enum type mass
    Graph(); 
    //  constructor for undirected an un weighted
    //precondition: none
    //postcondition: sets size of vector to store vertices and two dymensional vector 
    // to store edges
    
    void destroy(); 
    // delete all edge and vertices
    // precondition: none
    // postcondition: destroy all vertex and edge
   // input: none
    // output: none
    bool isEmpty() const; // no vertices
    // method to check if graph is empty
    // precondition: none
    // postcondition: none
    //input: none
    //output: boolean value
    bool isFull() const;
     // method to check if graph is full
    // precondition: none
    // postcondition: none
    //input: none
    //output: boolean value
    bool isAdjacentTo(const graphType&,const graphType&) const;
    // method to check if two vertices are isAdjacent
    // precondition: edge exists
    //postcondition: none
    // input: two vertex
  
    int edgeWeight(const graphType&,const graphType&) const; // precondition: edge exists
    // method to find weight of edge
    //precondition: edge exists
    //postcondition: none
    // input: two vertex
    
    int edgeCount() const;
    // method to count number of edge
    //precondition: none
    //postcondition: none
    //input: none
    // output: integer
    int vertexCount() const;
    // method to count number of vertex
    //precondition: none
    //postcondition: none
    //input: none
    // output: integer
    void insertVertex(const graphType&);
    // method to insert vertex in vector
    // precondition: vertex should be of graphType
    // postcondition: vertex is added to the vector

    void insertEdge(const graphType&,const graphType&, int);
      // method to insert edge in two dymensional vector
    // precondition: edge should be integer
    // postcondition: edge is added to the vector
    void deleteEdge(const graphType&,const graphType&);
    // method to delete a edge
    // precondition: edge should exists
    //postcondition: edge is deleted
    //input: two vertes of graphType
    //output: none
    
    void deleteVertex(const graphType&); // be sure to delete associated edges
    // method to delete a vertex
    // precondition:vertex should exists
    //postcondition: vertex is deleted
    //input: vertes of graphType
    //output: none
    int findVertex(const graphType&) const; // return the index where Vertex is found, -1 if not found
    // method to find vertex
    //precondition: vertex should exists
    //postcondition: none
    // output: index of vertex
    void dump() const;  // for debugging purposes, simply dumps out graph contents
                    // assumes << overloaded for template type
    // method to print
    //precondition: none
    //postcondition: none
    

  private:
    vector <graphType> vertices; // vector to store vertices
    vector <vector <int> > edge; // two dimensional vector to store edge
    static direction d; // static attribute for direction 
    static mass m; // static attribute for mass
    //int vertexCt; // private variable for counting vertex
    int edgeCt;  // private variable for counting edge

};
template <class graphType>
mass Graph<graphType> :: m = UNWEIGHTED;

template <class graphType>
direction Graph <graphType> :: d = UNDIRECTED;


template <class graphType>
Graph <graphType> :: Graph ()
{
  //vertexCt = 0;
  edgeCt = 0;
vector <graphType> vertices(100);
//vector <vector <int> >edge(100, vector<int>(100));
  edge.resize(100);
  for (int i = 0;i<100;i++)
  {
    edge[i].resize(100);
  }
d = UNDIRECTED;
m = UNWEIGHTED;

}
template <class graphType>
Graph <graphType> :: Graph (direction d1,mass m1)
{
  //vertexCt = 0;
  edgeCt = 0;
vector <graphType> vertices(100);
//vector <vector <int> >edge(100, vector<int>(100));
  edge.resize(100);
  for (int i = 0;i<100;i++)
  {
    edge[i].resize(100);
  }
d = d1;
m = m1;

}
template <class graphType>
Graph <graphType> :: Graph (mass m1, direction d1)
{
  //vertexCt = 0;
  edgeCt = 0;
vector <graphType> vertices(100);
//vector <vector <int> >edge(100, vector<int>(100));
  edge.resize(100);
  for (int i = 0;i<100;i++)
  {
    edge[i].resize(100);
  }
d = d1;
m = m1;
}
template <class graphType>
Graph <graphType> :: Graph (mass m1)
{
  //vertexCt = 0;
  edgeCt = 0;
vector <graphType> vertices(100);
//vector <vector <int> >edge(100, vector<int>(100));
  edge.resize(100);
  for (int i = 0;i<100;i++)
  {
    edge[i].resize(100);
  }
d = UNDIRECTED;
m = m1;
}
template <class graphType>
Graph <graphType> :: Graph (direction d1)
{
  //vertexCt = 0;
  edgeCt = 0;
vector <graphType> vertices(100);
//vector <vector <int> >edge(100, vector<int>(100));
  edge.resize(100);
  for (int i = 0;i<100;i++)
  {
    edge[i].resize(100);
  }
d = d1;
m = UNWEIGHTED;
  
}

template <class graphType>
int Graph <graphType> :: edgeCount() const
{
  return edgeCt;
}

template <class graphType>
int Graph <graphType> :: vertexCount() const
{

  return vertices.size() ;
 
}

template <class graphType>
void Graph <graphType> :: insertVertex(const graphType &a)
{
  if (!isFull())
    vertices.push_back(a);
  else
    throw range_error("out of Range!!!");
}

template <class graphType>
bool Graph <graphType> :: isEmpty() const
{
  if (vertices.empty())
    return true;
  else
    return false;
}
template <class graphType>
bool Graph <graphType> :: isFull() const
{
  if (vertices.size() == 100)
    return true;
  else
    return false;
}

template <class graphType>
int Graph <graphType> :: findVertex (const graphType& a) const
{
  int tmpIndex = -1; // -1 index if not found
  for (int i = 0; i<vertices.size(); i++)
  {
    if (vertices[i] == a)
      tmpIndex = i;
  }
  return tmpIndex;
}


template <class graphType>
void Graph <graphType> :: destroy()
{
  
  for (int i = 0;i<100;i++)
  {
    for (int j = 0;j<100;j++)
    {edge[i][j] = 0;}
  }
  vertices.clear();
  //vertexCt = 0;
  edgeCt = 0;
}

template <class graphType>
bool Graph <graphType> :: isAdjacentTo(const graphType &a,const graphType &b)const
{
  int aIndex = findVertex(a);
  int bIndex = findVertex(b);
  
  if (!(aIndex==-1 || bIndex == -1))
  {
    if (edge[aIndex][bIndex] == 0)
      return false;
    else
      return true;
  }
  else
    throw invalid_argument ("edge does not exists!!");
}
template <class graphType>
int Graph <graphType> :: edgeWeight(const graphType& a, const graphType& b) const
{
  int actualWeight;
  int aIndex = findVertex(a);
  int bIndex = findVertex(b);
  if (!(aIndex == -1 || bIndex == -1))
  { actualWeight = edge[aIndex][bIndex];
  return actualWeight;}
  else
    throw invalid_argument ("does not exist!!");
}

template <class graphType>
void Graph <graphType> :: insertEdge(const graphType &a, const graphType &b, int weight = 1)
{
    int aIndex = findVertex(a);
  int bIndex = findVertex(b);
  if (!(aIndex == -1 || bIndex == -1))
  {
    if (m == UNWEIGHTED && d == UNDIRECTED)
    {
      edge[aIndex][bIndex] = 1;
      edge[bIndex][aIndex] = 1;
      edgeCt++;
      
      edgeCt++;
    }
    
    else if (m == UNWEIGHTED && d == DIRECTED)
    {
      edge[aIndex][bIndex] = 1;
      edgeCt++;
      
    }
    else if (m == WEIGHTED && d == UNDIRECTED)
    {
      edge[aIndex][bIndex] = weight;
      edge[bIndex][aIndex] = weight;
      edgeCt++;
      
      edgeCt++;
      
    }
    else if (m == WEIGHTED && d == DIRECTED)
    {
      edge[aIndex][bIndex] = weight;
      edgeCt++;
    }
  }
  else
    throw invalid_argument("weight cannot be added!!!");
  
}



template <class graphType>
void Graph <graphType> :: deleteVertex(const graphType& a)
{
  int vertexIndex = findVertex(a);
  if (!(vertexIndex==-1))
  {
    vertices.erase(vertices.begin()+vertexIndex);
  }
  else 
    throw invalid_argument("vertex cannot be deleted!!!");
}



template <class graphType>
void Graph <graphType> :: deleteEdge(const graphType& a, const graphType& b)
{
    int aIndex = findVertex(a);
  int bIndex = findVertex(b);
  if (!(aIndex == -1 || bIndex == -1))
  {
    if (d == DIRECTED)
    {
      edge[aIndex][bIndex] = 0;
      edgeCt--;
    }
    else 
    {
      edge[aIndex][bIndex] = 0;
      edge[aIndex][bIndex] = 0;
      edgeCt--;
      
      edgeCt--;
    }
  }
  else 
    throw invalid_argument("edge cannot be deleted!!");
}


template <class graphType>
void Graph <graphType> :: dump() const
{
 
  for (int i = 0;i<vertices.size();i++)
    cout <<right<<setw(12) <<vertices[i];
  cout << endl;
  for (int j = 0;j<vertices.size();j++)
  {
    cout <<"["<< setw(2)<<j << "]";
    cout <<left<<setw(10) <<vertices[j];
    for (int k = 0;k<vertices.size();k++)
    {
      cout << setw(12)<<edge[j][k];
    }
    cout << endl;
  }
}

}

#endif
