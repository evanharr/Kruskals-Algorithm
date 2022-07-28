
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <set>

using namespace std;

typedef pair<int,int> edge;
typedef pair<int,edge> cost;



vector<vector<int> > kruskal(vector<vector<int> > G )
{
  int s = G.size();
  vector<int> source;
  vector<int>destination;

  vector<int>parent;
  vector<int>visited;
  set<cost>set;

  int weight;
  int xVert;
  int yVert;
  vector<int> subset;


  for(int i = 0; i < G.size(); i++)
  {
    for(int j = 0; j < G.size(); j++)
    {
      //if vertices are not connected
      if(G[i][j] == 0)
      {
        continue;
      }
      //create pair of source and destination edges
      edge x = make_pair(i,j);
      //create pair of weight, and source/destination edges
      cost y = make_pair(G[i][j], x);
      //insert into set which automatically sorts from smallest to largest
      set.insert(y);
    }
  }


  cout << "edge list: " << endl;
  for(const auto &itset : set)
  {

    source.push_back( itset.second.first);
    destination.push_back( itset.second.second);

      cout << itset.first << " " << itset.second.first << " " << itset.second.second <<  endl;
  }
  //remove highest weight repeated edges between vertices
  for(int i = 0; i < source.size(); i ++)
  {
    for(int j =0; j < source.size(); j++)
    {
      if((source[i] == destination[j])&&(destination[i] == source[j]))
      {
        cout <<"source: " << source[j] << " destination: " << destination[j] << endl;
        source.erase(source.begin()+j);
        destination.erase(destination.begin()+j);
      }
    }
  }
cout << endl;
  cout << "---------------" << endl;
  cout << endl;
  for(int i = 0; i < source.size(); i++)
  {
    cout <<"source: " << source[i] << " destination: " << destination[i] << endl;

  }
  //add

  for(int i = 0; i < source.size(); i++)
  {
    subset.push_back(-1);
  }

  parent.push_back(source[0]);
  visited.push_back(destination[0]);
  cout << endl;
  cout << "parent: " << parent[0] << " visited: " << visited[0] << endl;
  cout << endl;
  int count;
  for(int i =1; i < source.size()-1; i++)
  {
    cout <<"i iteration " << source[i] << " " << destination[i] << endl;
    cout << endl;
    for (int j = 0; j < source.size(); j++)
    {

      if((source[i] == parent[j] && source[i] != visited[j]))
      {
        cout <<"source: " << source[i] << " destination: " << destination[i] << endl;

        parent.push_back(destination[i]);
        visited.push_back(source[i]);
        count++;
      }
      if(destination[i] == parent[j] && destination[i] != visited[j])
      {
        cout <<"source: " << source[i] << " destination: " << destination[i] << endl;

        parent.push_back(source[i]);
        visited.push_back(destination[i]);
        count++;
      }
      if((source[i] != parent[j] && source[i] != visited[j]))
      {
        if((destination[i] != parent[j] && destination[i] != visited[j]))
        {
          parent.push_back(source[i]);
          visited.push_back(destination[i]);
        }

      }
      else
      {
        break;
      }
    }

  }

  for(int i =0; i < parent.size(); i++)
  {
    cout << "parent: " << parent[i] << " visited: " << visited[i] << endl;
  }

  return G;



}


int main()
{

  srand (time(NULL));
  int s=4;

  vector<vector<int> > G;

  for(int i=0 ; i<s ;i++)
  {
    vector<int>* dump=new vector<int>;
      for(int j=0 ; j<s ;j++)
        dump->push_back(0);
        G.push_back(*dump);
  }
  for(int i=0 ; i<s ;i++)
  {
    for(int j=0 ; j<s ;j++)
    {
      if(i==j)
        continue;
      if(rand() % 10 > 6)
        continue;
      G[i][j]=rand() % 100;
    }
  }
  for(int i=0 ; i<s ;i++)
  {
    for(int j=0 ; j<s ;j++)
    cout<<G[i][j]<<" ";
    cout<<endl;
  }

kruskal(G);
}
