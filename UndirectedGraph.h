#ifndef UNDIRECTED_GRAPH_H
#define UNDIRECTED_GRAPH_H
#include "DirectedGraph.h"
template <class T>
class UndirectedGraph
{
private:
    DirectedGraph<T> graph_;

public:
    UndirectedGraph()
    {
        graph_ = DirectedGraph<T>();
    }
    UndirectedGraph(const UndirectedGraph<T> &other)
    {
        graph_ = DirectedGraph<T>(other.graph_);
    }
    bool hasVertex(std::string &vertex_name)
    {
        return graph_.hasVertex(vertex_name);
    }
    bool hasVertex(const std::string &vertex_name)
    {
        return graph_.hasVertex(vertex_name);
    }
    void addVertex(T &value, std::string &name)
    {
        graph_.addVertex(value, name);
    }
    void addVertex(const T &value, std::string &name)
    {
        graph_.addVertex(value, name);
    }
    void addVertex(T &value, const std::string &name)
    {
        graph_.addVertex(value, name);
    }
    void addVertex(const T &value, const std::string &name)
    {
        graph_.addVertex(value, name);
    }
    std::shared_ptr<GraphVertex<T>> getVertex(std::string &vertex_name)
    {
        return graph_.getVertex(vertex_name);
    }
    std::shared_ptr<GraphVertex<T>> getVertex(const std::string &vertex_name)
    {
        return graph_.getVertex(vertex_name);
    }
    void createEdge(std::string &src, std::string &dst, double weight = 1)
    {
        graph_.createEdge(src, dst, weight);
        graph_.createEdge(dst, src, weight);
    }
    void createEdge(const std::string &src, std::string &dst, double weight = 1)
    {
        graph_.createEdge(src, dst, weight);
        graph_.createEdge(dst, src, weight);
    }
    void createEdge(std::string &src, const std::string &dst, double weight = 1)
    {
        graph_.createEdge(src, dst, weight);
        graph_.createEdge(dst, src, weight);
    }
    void createEdge(const std::string &src, const std::string &dst, double weight = 1)
    {
        graph_.createEdge(src, dst, weight);
        graph_.createEdge(dst, src, weight);
    }

    void removeEdge(std::string &src, std::string &dst)
    {
        graph_.removeEdge(src, dst);
        graph_.removeEdge(dst, src);
    }
    void removeEdge(const std::string &src, std::string &dst)
    {
        graph_.removeEdge(src, dst);
        graph_.removeEdge(dst, src);
    }
    void removeEdge(std::string &src, const std::string &dst)
    {
        graph_.removeEdge(src, dst);
        graph_.removeEdge(dst, src);
    }
    void removeEdge(const std::string &src, const std::string &dst)
    {
        graph_.removeEdge(src, dst);
        graph_.removeEdge(dst, src);
    }
    void removeVertex(std::string &name)
    {
        graph_.removeVertex(name);
    }
    void removeVertex(const std::string &name)
    {
        graph_.removeVertex(name);
    }
    friend std::ostream &operator<<(std::ostream &os, const UndirectedGraph<T> &G)
    {
        os << G.graph_;
        return os;
    }
    std::shared_ptr<GraphFunction<double>> BFS(std::string &s)
    {
        return graph_.BFS(s);
    }
    std::shared_ptr<GraphFunction<double>> BFS(const std::string &s)
    {
        return graph_.BFS(s);
    }
    void printNames()
    {
        graph_.printNames();
    }
};
#endif