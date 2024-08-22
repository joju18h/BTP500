#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
using namespace std;



struct node
{
    string vertex;
    int weight;
    node* next;

    node(string v, int w)
    {
        vertex = v;
        weight = w;
        next = nullptr;
    }
};

class Graph
{
    private:
        class AdjList
        {
            public:
                node* head;
        };
        int numVertices;
        AdjList *adjList;

    public:
        Graph(int);
        ~Graph();
        void addEdge(string, string, int);
        void printGraph();
        int findVertex(const string&);
        void bfs(const string&);
        void dfs(const string&);\
};

// int Graph::findVertex(const string& vertex)
// {
//     for (int i = 0; i < numVertices; ++i)
//     {
//        node* head = adjList[i].head;
//          if(head && head->vertex == vertex)
//          {
//               return i;
//          }

//     }
//     return -1;
// }

int Graph::findVertex(const string& vertex){
    for (int i = 0; i < numVertices; ++i){
        node *head = adjList[i].head;

        if(head && head->vertex ==  vertex){
            return i;
        }
    }
    return -1;
}

Graph::Graph(int numvertices)
{
    numVertices = numvertices;
    adjList = new AdjList[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        adjList[i].head = nullptr;
    }
}

Graph::~Graph()
{
    for (int i = 0; i < numVertices; i++)
    {
        node* curr = adjList[i].head;
        while (curr)
        {
            node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    delete[] adjList;
}

void Graph::addEdge(string src, string dest, int weight)
{
    int index = findVertex(src);
    if (index == -1)
    {
        for(int i = 0; i < numVertices; i++)
        {
            if(!adjList[i].head)
            {
                adjList[i].head = new node(src, 0);
                index = i;
                break;
            }
        }

    }
    node* temp = new node(dest, weight);
    node* curr = adjList[index].head;

    if (!curr)
    {
        adjList[index].head = temp;
    }
    else
    {
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

void Graph::printGraph()
{
    cout << "Adjacency list:" << endl;

    for (int i = 0; i < numVertices; i++)
    {
        node* curr = adjList[i].head;
        cout << i + 1 << ". " << curr->vertex;

        while (curr->next)
        {
            curr = curr->next;
            cout << " -> " << curr->vertex;
        }
        cout << endl;
    }
}

void Graph::bfs(const string& startVertex)
{
    int startIndex = findVertex(startVertex);
    if (startIndex == -1)
    {
        cout << "Vertex not found!" << endl;
        return;
    }

    cout << "BFS starting from " << startVertex << ":" << endl;
    queue<int> q;
    vector<bool> visited(numVertices, false);

    q.push(startIndex);
    visited[startIndex] = true;

    while (!q.empty())
    {
        int currentVertex = q.front();
        q.pop();

        cout << currentVertex + 1 << ". " << adjList[currentVertex].head->vertex << " ";

        node* curr = adjList[currentVertex].head->next;
        while (curr)
        {
            int neighborIndex = findVertex(curr->vertex);
            if (!visited[neighborIndex])
            {
                q.push(neighborIndex);
                visited[neighborIndex] = true;
            }
            curr = curr->next;
        }
    }

    cout << endl;
}



void Graph::dfs(const string& startVertex)
{
    int startIndex = findVertex(startVertex);
    if (startIndex == -1)
    {
        cout << "Vertex not found!" << endl;
        return;
    }

    cout << "DFS starting from " << startVertex << ":" << endl;
    stack<int> s;
    vector<bool> visited(numVertices, false);

    s.push(startIndex);

    while (!s.empty())
    {
        int currentVertex = s.top();
        s.pop();

        if (!visited[currentVertex])
        {
            cout << currentVertex + 1 << ". " << adjList[currentVertex].head->vertex << " ";
            visited[currentVertex] = true;

            node* curr = adjList[currentVertex].head->next;
            while (curr)
            {
                int neighborIndex = findVertex(curr->vertex);
                if (!visited[neighborIndex])
                {
                    s.push(neighborIndex);
                }
                curr = curr->next;
            }
        }
    }

    cout << endl;
}



int main()
{
    Graph g(13);
    g.addEdge("Alberta", "British Columbia", 1);
    g.addEdge("Alberta", "Saskatchewan", 1);
    g.addEdge("Alberta", "Northwest Territories", 1);
    g.addEdge("British Columbia", "Alberta", 1);
    g.addEdge("British Columbia", "Yukon", 1);
    g.addEdge("Manitoba", "Saskatchewan", 1);
    g.addEdge("Manitoba", "Ontario", 1);
    g.addEdge("Manitoba", "Northwest Territories", 1);
    g.addEdge("New Brunswick", "Quebec", 1);
    g.addEdge("New Brunswick", "Nova Scotia", 1);
    g.addEdge("New Brunswick", "Prince Edward Island", 1);
    g.addEdge("Newfoundland and Labrador", "Quebec", 1);
    g.addEdge("Newfoundland and Labrador", "Nova Scotia", 1);
    g.addEdge("Newfoundland and Labrador", "Prince Edward Island", 1);
    g.addEdge("Newfoundland and Labrador", "New Brunswick", 1);
    g.addEdge("Northwest Territories", "Alberta", 1);
    g.addEdge("Northwest Territories", "Saskatchewan", 1);
    g.addEdge("Northwest Territories", "Manitoba", 1);
    g.addEdge("Nova Scotia", "New Brunswick", 1);
    g.addEdge("Nova Scotia", "Newfoundland and Labrador", 1);
    g.addEdge("Nova Scotia", "Prince Edward Island", 1);
    g.addEdge("Nunavut", "Northwest Territories", 1);
    g.addEdge("Nunavut", "Manitoba", 1);
    g.addEdge("Ontario", "Manitoba", 1);
    g.addEdge("Ontario", "Quebec", 1);
    g.addEdge("Ontario", "Northwest Territories", 1);
    g.addEdge("Prince Edward Island", "New Brunswick", 1);
    g.addEdge("Prince Edward Island", "Newfoundland and Labrador", 1);
    g.addEdge("Prince Edward Island", "Nova Scotia", 1);
    g.addEdge("Quebec", "New Brunswick", 1);
    g.addEdge("Quebec", "Newfoundland and Labrador", 1);
    g.addEdge("Quebec", "Ontario", 1);
    g.addEdge("Saskatchewan", "Alberta", 1);
    g.addEdge("Saskatchewan", "Manitoba", 1);
    g.addEdge("Saskatchewan", "Northwest Territories", 1);
    g.addEdge("Yukon", "British Columbia", 1);
    cout << "Canada Provinces and Territories: \n\n";
    g.printGraph();

    cout << endl;
    cout << "USA States: \n\n";
    Graph usaGraph(50);


usaGraph.addEdge("Alabama", "Georgia", 1);
usaGraph.addEdge("Alabama", "Tennessee", 1);
usaGraph.addEdge("Alabama", "Mississippi", 1);
usaGraph.addEdge("Alabama", "Florida", 1);

usaGraph.addEdge("Alaska", "Washington", 1);

usaGraph.addEdge("Arizona", "California", 1);
usaGraph.addEdge("Arizona", "Nevada", 1);
usaGraph.addEdge("Arizona", "Utah", 1);
usaGraph.addEdge("Arizona", "New Mexico", 1);

usaGraph.addEdge("Arkansas", "Tennessee", 1);
usaGraph.addEdge("Arkansas", "Mississippi", 1);
usaGraph.addEdge("Arkansas", "Louisiana", 1);
usaGraph.addEdge("Arkansas", "Texas", 1);
usaGraph.addEdge("Arkansas", "Oklahoma", 1);
usaGraph.addEdge("Arkansas", "Missouri", 1);

usaGraph.addEdge("California", "Oregon", 1);
usaGraph.addEdge("California", "Nevada", 1);
usaGraph.addEdge("California", "Arizona", 1);

usaGraph.addEdge("Colorado", "Wyoming", 1);
usaGraph.addEdge("Colorado", "Nebraska", 1);
usaGraph.addEdge("Colorado", "Kansas", 1);
usaGraph.addEdge("Colorado", "Oklahoma", 1);
usaGraph.addEdge("Colorado", "New Mexico", 1);
usaGraph.addEdge("Colorado", "Utah", 1);

usaGraph.addEdge("Connecticut", "New York", 1);
usaGraph.addEdge("Connecticut", "Massachusetts", 1);
usaGraph.addEdge("Connecticut", "Rhode Island", 1);

usaGraph.addEdge("Delaware", "Maryland", 1);
usaGraph.addEdge("Delaware", "New Jersey", 1);
usaGraph.addEdge("Delaware", "Pennsylvania", 1);

usaGraph.addEdge("Florida", "Georgia", 1);
usaGraph.addEdge("Florida", "Alabama", 1);

usaGraph.addEdge("Georgia", "Florida", 1);
usaGraph.addEdge("Georgia", "Alabama", 1);
usaGraph.addEdge("Georgia", "Tennessee", 1);
usaGraph.addEdge("Georgia", "South Carolina", 1);
usaGraph.addEdge("Georgia", "North Carolina", 1);

usaGraph.addEdge("Hawaii", "Alaska", 1);

usaGraph.addEdge("Idaho", "Washington", 1);
usaGraph.addEdge("Idaho", "Oregon", 1);
usaGraph.addEdge("Idaho", "Nevada", 1);
usaGraph.addEdge("Idaho", "Montana", 1);
usaGraph.addEdge("Idaho", "Wyoming", 1);
usaGraph.addEdge("Idaho", "Utah", 1);

usaGraph.addEdge("Illinois", "Missouri", 1);
usaGraph.addEdge("Illinois", "Kentucky", 1);
usaGraph.addEdge("Illinois", "Indiana", 1);
usaGraph.addEdge("Illinois", "Wisconsin", 1);
usaGraph.addEdge("Illinois", "Iowa", 1);

usaGraph.addEdge("Indiana", "Illinois", 1);
usaGraph.addEdge("Indiana", "Kentucky", 1);
usaGraph.addEdge("Indiana", "Ohio", 1);
usaGraph.addEdge("Indiana", "Michigan", 1);

usaGraph.addEdge("Iowa", "Minnesota", 1);
usaGraph.addEdge("Iowa", "Wisconsin", 1);
usaGraph.addEdge("Iowa", "Illinois", 1);
usaGraph.addEdge("Iowa", "Missouri", 1);
usaGraph.addEdge("Iowa", "Nebraska", 1);
usaGraph.addEdge("Iowa", "South Dakota", 1);

usaGraph.addEdge("Kansas", "Nebraska", 1);
usaGraph.addEdge("Kansas", "Oklahoma", 1);
usaGraph.addEdge("Kansas", "Colorado", 1);
usaGraph.addEdge("Kansas", "Missouri", 1);

usaGraph.addEdge("Kentucky", "Illinois", 1);
usaGraph.addEdge("Kentucky", "Indiana", 1);
usaGraph.addEdge("Kentucky", "Ohio", 1);
usaGraph.addEdge("Kentucky", "West Virginia", 1);
usaGraph.addEdge("Kentucky", "Virginia", 1);
usaGraph.addEdge("Kentucky", "Tennessee", 1);
usaGraph.addEdge("Kentucky", "Missouri", 1);

usaGraph.addEdge("Louisiana", "Arkansas", 1);
usaGraph.addEdge("Louisiana", "Texas", 1);
usaGraph.addEdge("Louisiana", "Mississippi", 1);

usaGraph.addEdge("Maine", "New Hampshire", 1);

usaGraph.addEdge("Maryland", "Delaware", 1);
usaGraph.addEdge("Maryland", "Virginia", 1);
usaGraph.addEdge("Maryland", "West Virginia", 1);
usaGraph.addEdge("Maryland", "Pennsylvania", 1);

usaGraph.addEdge("Massachusetts", "Rhode Island", 1);
usaGraph.addEdge("Massachusetts", "Connecticut", 1);
usaGraph.addEdge("Massachusetts", "New York", 1);
usaGraph.addEdge("Massachusetts", "Vermont", 1);
usaGraph.addEdge("Massachusetts", "New Hampshire", 1);

usaGraph.addEdge("Michigan", "Indiana", 1);
usaGraph.addEdge("Michigan", "Ohio", 1);
usaGraph.addEdge("Michigan", "Wisconsin", 1);

usaGraph.addEdge("Minnesota", "North Dakota", 1);
usaGraph.addEdge("Minnesota", "South Dakota", 1);
usaGraph.addEdge("Minnesota", "Iowa", 1);
usaGraph.addEdge("Minnesota", "Wisconsin", 1);

usaGraph.addEdge("Mississippi", "Louisiana", 1);
usaGraph.addEdge("Mississippi", "Arkansas", 1);
usaGraph.addEdge("Mississippi", "Tennessee", 1);
usaGraph.addEdge("Mississippi", "Alabama", 1);

usaGraph.addEdge("Missouri", "Iowa", 1);
usaGraph.addEdge("Missouri", "Illinois", 1);
usaGraph.addEdge("Missouri", "Kentucky", 1);
usaGraph.addEdge("Missouri", "Tennessee", 1);
usaGraph.addEdge("Missouri", "Arkansas", 1);
usaGraph.addEdge("Missouri", "Oklahoma", 1);
usaGraph.addEdge("Missouri", "Kansas", 1);
usaGraph.addEdge("Missouri", "Nebraska", 1);

usaGraph.addEdge("Montana", "Idaho", 1);
usaGraph.addEdge("Montana", "Wyoming", 1);
usaGraph.addEdge("Montana", "South Dakota", 1);
usaGraph.addEdge("Montana", "North Dakota", 1);

usaGraph.addEdge("Nebraska", "South Dakota", 1);
usaGraph.addEdge("Nebraska", "Iowa", 1);
usaGraph.addEdge("Nebraska", "Missouri", 1);
usaGraph.addEdge("Nebraska", "Kansas", 1);
usaGraph.addEdge("Nebraska", "Colorado", 1);
usaGraph.addEdge("Nebraska", "Wyoming", 1);

usaGraph.addEdge("Nevada", "California", 1);
usaGraph.addEdge("Nevada", "Oregon", 1);
usaGraph.addEdge("Nevada", "Idaho", 1);
usaGraph.addEdge("Nevada", "Utah", 1);
usaGraph.addEdge("Nevada", "Arizona", 1);

usaGraph.addEdge("New Hampshire", "Vermont", 1);
usaGraph.addEdge("New Hampshire", "Maine", 1);

usaGraph.addEdge("New Jersey", "Delaware", 1);
usaGraph.addEdge("New Jersey", "Pennsylvania", 1);
usaGraph.addEdge("New Jersey", "New York", 1);

usaGraph.addEdge("New Mexico", "Arizona", 1);
usaGraph.addEdge("New Mexico", "Utah", 1);
usaGraph.addEdge("New Mexico", "Colorado", 1);
usaGraph.addEdge("New Mexico", "Oklahoma", 1);
usaGraph.addEdge("New Mexico", "Texas", 1);

usaGraph.addEdge("New York", "Vermont", 1);
usaGraph.addEdge("New York", "Massachusetts", 1);
usaGraph.addEdge("New York", "Connecticut", 1);
usaGraph.addEdge("New York", "New Jersey", 1);
usaGraph.addEdge("New York", "Pennsylvania", 1);

usaGraph.addEdge("North Carolina", "South Carolina", 1);
usaGraph.addEdge("North Carolina", "Georgia", 1);
usaGraph.addEdge("North Carolina", "Tennessee", 1);
usaGraph.addEdge("North Carolina", "Virginia", 1);

usaGraph.addEdge("North Dakota", "Minnesota", 1);
usaGraph.addEdge("North Dakota", "South Dakota", 1);
usaGraph.addEdge("North Dakota", "Montana", 1);

usaGraph.addEdge("Ohio", "Indiana", 1);
usaGraph.addEdge("Ohio", "Kentucky", 1);
usaGraph.addEdge("Ohio", "West Virginia", 1);
usaGraph.addEdge("Ohio", "Pennsylvania", 1);
usaGraph.addEdge("Ohio", "Michigan", 1);

usaGraph.addEdge("Oklahoma", "Texas", 1);
usaGraph.addEdge("Oklahoma", "Arkansas", 1);
usaGraph.addEdge("Oklahoma", "Missouri", 1);
usaGraph.addEdge("Oklahoma", "Kansas", 1);
usaGraph.addEdge("Oklahoma", "Colorado", 1);
usaGraph.addEdge("Oklahoma", "New Mexico", 1);

usaGraph.addEdge("Oregon", "Washington", 1);
usaGraph.addEdge("Oregon", "Idaho", 1);
usaGraph.addEdge("Oregon", "Nevada", 1);
usaGraph.addEdge("Oregon", "California", 1);

usaGraph.addEdge("Pennsylvania", "New York", 1);
usaGraph.addEdge("Pennsylvania", "New Jersey", 1);
usaGraph.addEdge("Pennsylvania", "Delaware", 1);
usaGraph.addEdge("Pennsylvania", "Maryland", 1);
usaGraph.addEdge("Pennsylvania", "West Virginia", 1);
usaGraph.addEdge("Pennsylvania", "Ohio", 1);

usaGraph.addEdge("Rhode Island", "Massachusetts", 1);
usaGraph.addEdge("Rhode Island", "Connecticut", 1);

usaGraph.addEdge("South Carolina", "North Carolina", 1);
usaGraph.addEdge("South Carolina", "Georgia", 1);

usaGraph.addEdge("South Dakota", "North Dakota", 1);
usaGraph.addEdge("South Dakota", "Minnesota", 1);
usaGraph.addEdge("South Dakota", "Iowa", 1);
usaGraph.addEdge("South Dakota", "Nebraska", 1);
usaGraph.addEdge("South Dakota", "Wyoming", 1);
usaGraph.addEdge("South Dakota", "Montana", 1);

usaGraph.addEdge("Tennessee", "Kentucky", 1);
usaGraph.addEdge("Tennessee", "Virginia", 1);
usaGraph.addEdge("Tennessee", "North Carolina", 1);
usaGraph.addEdge("Tennessee", "Georgia", 1);
usaGraph.addEdge("Tennessee", "Alabama", 1);
usaGraph.addEdge("Tennessee", "Mississippi", 1);
usaGraph.addEdge("Tennessee", "Arkansas", 1);
usaGraph.addEdge("Tennessee", "Missouri", 1);

usaGraph.addEdge("Texas", "New Mexico", 1);
usaGraph.addEdge("Texas", "Oklahoma", 1);
usaGraph.addEdge("Texas", "Arkansas", 1);
usaGraph.addEdge("Texas", "Louisiana", 1);

usaGraph.addEdge("Utah", "Idaho", 1);
usaGraph.addEdge("Utah", "Wyoming", 1);
usaGraph.addEdge("Utah", "Colorado", 1);
usaGraph.addEdge("Utah", "New Mexico", 1);
usaGraph.addEdge("Utah", "Arizona", 1);

usaGraph.addEdge("Vermont", "New York", 1);
usaGraph.addEdge("Vermont", "Massachusetts", 1);
usaGraph.addEdge("Vermont", "New Hampshire", 1);

usaGraph.addEdge("Virginia", "North Carolina", 1);
usaGraph.addEdge("Virginia", "Tennessee", 1);
usaGraph.addEdge("Virginia", "Kentucky", 1);
usaGraph.addEdge("Virginia", "West Virginia", 1);
usaGraph.addEdge("Virginia", "Maryland", 1);

usaGraph.addEdge("Washington", "Oregon", 1);
usaGraph.addEdge("Washington", "Idaho", 1);

usaGraph.addEdge("West Virginia", "Ohio", 1);
usaGraph.addEdge("West Virginia", "Pennsylvania", 1);
usaGraph.addEdge("West Virginia", "Maryland", 1);
usaGraph.addEdge("West Virginia", "Virginia", 1);
usaGraph.addEdge("West Virginia", "Kentucky", 1);
usaGraph.addEdge("West Virginia", "Ohio", 1);

usaGraph.addEdge("Wisconsin", "Michigan", 1);
usaGraph.addEdge("Wisconsin", "Illinois", 1);
usaGraph.addEdge("Wisconsin", "Iowa", 1);
usaGraph.addEdge("Wisconsin", "Minnesota", 1);

usaGraph.addEdge("Wyoming", "Montana", 1);
usaGraph.addEdge("Wyoming", "South Dakota", 1);
usaGraph.addEdge("Wyoming", "Nebraska", 1);
usaGraph.addEdge("Wyoming", "Colorado", 1);
usaGraph.addEdge("Wyoming", "Utah", 1);
usaGraph.addEdge("Wyoming", "Idaho", 1);

usaGraph.printGraph();

    cout << endl;
    g.bfs("Alberta");
    g.dfs("Alberta");

    cout << endl;
    usaGraph.bfs("Texas");
    usaGraph.dfs("Texas");

return 0;
}