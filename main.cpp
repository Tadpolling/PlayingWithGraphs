#include <iostream>
//#include "Node.h"
#include <string>
#include <memory>
#include "DirectedGraph.h"
#include "GraphVertex.h"
#include "UndirectedGraph.h"
#include "GraphFunction.h"
// typedef std::shared_ptr<GraphVertex<int>> VertexPtr;
int main(int, char **)
{
    /*
    std::string s = "A";
    std::string s2 = "B";
    GraphVertex<int> a = GraphVertex<int>(3, s);
    GraphVertex<int> b = GraphVertex<int>(6, s2);
    GraphVertex<int> c = GraphVertex<int>(16, "C");
    VertexPtr aptr = std::make_shared<GraphVertex<int>>(a);
    VertexPtr bptr = std::make_shared<GraphVertex<int>>(b);
    VertexPtr cptr = std::make_shared<GraphVertex<int>>(c);

    a.addEdge(bptr, 1);
    b.addEdge(cptr, 4.5);
    a.addEdge(cptr, 5.75);
    b.addInGoingEdge(aptr, 1);
    c.addInGoingEdge(aptr, 5.75);
    c.addInGoingEdge(bptr, 4.5);
    std::cout << a << b << c;
    a.printInGoingEdges();
    b.printInGoingEdges();
    c.printInGoingEdges();

    */

    /*DirectedGraph<int> G = DirectedGraph<int>();
    int num = 3;
    G.addVertex(num, "c");
    G.addVertex(4, "a");
    G.addVertex(7, "b");
    // std::cout << G.hasVertex("a") << "\n";
    G.createEdge("c", "a");
    G.createEdge("b", "c", 5.6);
    G.createEdge("a", "b");
    G.printTopologicolSort();

    */
    // std::cout << G.printI;nGoingEdges(std::cout);

    /* while (G.verticies_names_.size() > 0)
     {
         std::cout << G;
         G.printInGoingEdgesInGraph();
         std::string v = G.verticies_names_[G.findSourceIndex()];
         std::cout << v << "\n";
         G.removeVertex(v);
         std::chrono::milliseconds timespan(2000);
         std::this_thread::sleep_for(timespan);
     }
     */
    // DirectedGraph<int> G2 = DirectedGraph<int>(G);
    // G.createEdge("c", "a", 2);
    // G2.createEdge("b", "a");
    // std::cout << G;
    // std::cout << "copied Graph:\n"
    //           << G2;

    // int b = 2;
    UndirectedGraph<int> G = UndirectedGraph<int>();
    for (int i = 0; i <= 'H' - 'A'; i++)
    {
        char c = (char)('A' + i);
        std::string s = std::string(1, c);
        // std::cout << c << " ";
        G.addVertex(1, s);
    }
    std::cout << "\n";

    /* G.addVertex(1, "A");
     G.addVertex(1, "B");
     G.addVertex(1, "C");
     G.addVertex(1, "D");
     G.addVertex(1, "E");
     G.addVertex(1, "F");
     G.addVertex(1, "G");
     G.addVertex(1, "H");
     */
    std::cout << "Finished Creating Graph\n";
    G.printNames();
    G.createEdge("A", "C");
    G.createEdge("A", "B");
    G.createEdge("A", "F");
    G.createEdge("A", "G");
    G.createEdge("G", "E");
    G.createEdge("F", "E");
    G.createEdge("F", "D");
    G.createEdge("D", "E");
    G.createEdge("D", "H");
    std::cout << G << "\n";
    // std::shared_ptr<GraphFunction<double>> gf_ptr = G.BFS("A");
    std::shared_ptr<GraphFunction<double>> gf_ptr = G.BFS("A");
    // std::cout << *gf_ptr;
    // std::cout << G << "\n";
    // std::cout << "working:\n";
    std::cout << (*gf_ptr) << "\n";
}
