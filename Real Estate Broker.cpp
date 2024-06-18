
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct house;

struct client {
  int a;
  int p;
};
struct house {
  int x;
  int y;
};

//somewhat like an adjacency matrix
bool** chg;
//visited houses (reset at each client)
bool* visited;
//the client matched for each house
//necessary for rematching previous clients
int* hmatch;

int hcount;

//try to match client ci to an unpurchased house
//standard bipartite matching algorithm
bool match(int ci )
{
  //try all houses
  for (int i = 0; i < hcount; i++)
  {
    //see if house meets client's preferences
    if(chg[ci][i] == true)
    {
      //make sure we don't loop
      if(visited[i] == false)
      {
        visited[i] = true;
        //house hasn't been matched yet
        if (hmatch[i] == -1)
        {
          hmatch[i] = ci;
          return true;
        } else if (match(hmatch[i])) {
        //house was previously matched; try to rematch the client
          hmatch[i] = ci;
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  hcount = m;
  client* cl = new client[n];
  house* hl = new house[m];
  chg = new bool*[n];
  hmatch = new int[m];
  for (int i = 0; i < n; i++)
  {
    chg[i] = new bool[m];
    cin >> cl[i].a >> cl[i].p;
  }
  for (int i = 0; i < m; i++)
  {
    hmatch[i] = -1;
    cin >> hl[i].x >> hl[i].y;
  }
  for( int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      if(cl[i].a < hl[j].x && cl[i].p >= hl[j].y)
      {
        chg[i][j] = true;
      } else {
        chg[i][j] = false;
      }
    }
  }
  int count = 0;
  //try to match each client
  for(int i = 0; i < n; i++)
  {
    //reset the visited houses list once per client
    visited = new bool[m];
    for (int j = 0; j < m; j++)
    {
      visited[j] = false;
    }
    //try to match the client; count matches
    if (match(i))
    {
      count++;
    }
  }
  cout << count << endl;
  return 0;
}

