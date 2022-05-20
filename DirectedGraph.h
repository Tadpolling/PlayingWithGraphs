#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H
#include <memory>
#include <vector>
#include <algorithm>
#include "GraphVertex.h"
template <class T>
class DirectedGraph
{

private:
    std::vector<std::string> verticies_names_;
    std::vector<std::shared_ptr<GraphVertex<T>>> verticies_ptrs_;
    int findSourceIndex()
    {
        int i;
        for (i = 0; i < verticies_ptrs_.size(); i++)
        {
            if (verticies_ptrs_[i]->getInDegree() == 0)
            {
                return i;
            }
        }
        // std::cout << "Bad Graph\n";
        throw std::invalid_argument("Received Graph that was not Acyclic");
        return -1;
    }

public:
    DirectedGraph()
    {
        verticies_names_ = std::vector<std::string>();
        verticies_ptrs_ = std::vector<std::shared_ptr<GraphVertex<T>>>();
    }
    DirectedGraph(const DirectedGraph<T> &other)
    {
        this->verticies_names_ = std::vector<std::string>();
        this->verticies_ptrs_ = std::vector<std::shared_ptr<GraphVertex<T>>>();
        for (int i = 0; i < other.verticies_names_.size(); i++)
        {
            this->addVertex(T(other.verticies_ptrs_[i]->getValue()), other.verticies_names_[i]);
        }
        for (int i = 0; i < verticies_names_.size(); i++)
        {
            std::vector<std::string> outgoing_names = other.verticies_ptrs_[i]->getOutEdgesNames();
            std::vector<double> outgoing_weights = other.verticies_ptrs_[i]->getOutWeights();
            for (int j = 0; j < outgoing_names.size(); j++)
            {
                this->createEdge(verticies_names_[i], outgoing_names[j], outgoing_weights[j]);
            }
        }
        /*std::cout << "New Graph Verticies:";
        for (int i = 0; i < verticies_names_.size(); i++)
        {
            std::cout << verticies_names_[i] << ", ";
        }
        */
        /*for (int i = 0; i < other.verticies_names_.size(); i++)
        {
            std::vector<std::shared_ptr<GraphVertex<T>>> outgoing_edges = other.verticies_ptrs_[i]->getOutEdges();
            std::cout << other.verticies_names_[i] << " " << outgoing_edges.size() << ": ";
            for (int k = 0; k < outgoing_edges.size(); k++)
            {
                std::cout << outgoing_edges[k]->getName() << " ,";
            }
            std::cout << "\n";
            std::vector<double> outgoing_weights = other.verticies_ptrs_[i]->getOutWeights();
            for (int j = 0; j < outgoing_edges.size(); i++)
            {
                std::cout << "Creating Edge Between: " << other.verticies_names_[i] << " and " << outgoing_edges[j]->getName() << "\n";
                this->createEdge(other.verticies_names_[i], outgoing_edges[j]->getName(), outgoing_weights[j]);
            }
        }
        */
    }
    bool hasVertex(std::string &vertex_name)
    {
        if (std::find(verticies_names_.begin(), verticies_names_.end(), vertex_name) != verticies_names_.end())
        {
            return true;
        }
        return false;
    }
    bool hasVertex(const std::string &vertex_name)
    {
        if (std::find(verticies_names_.begin(), verticies_names_.end(), vertex_name) != verticies_names_.end())
        {
            return true;
        }
        return false;
    }
    void addVertex(T &value, std::string &name)
    {
        if (hasVertex(name))
        {
            std::cerr << name << " Exists in Graph \n";
            return;
        }
        std::shared_ptr<GraphVertex<T>> vptr(new GraphVertex<T>(value, name));
        verticies_names_.push_back(name);
        verticies_ptrs_.push_back(vptr);
    }
    void addVertex(const T &value, std::string &name)
    {
        if (hasVertex(name))
        {
            std::cerr << name << " Exists in Graph \n";
            return;
        }
        std::shared_ptr<GraphVertex<T>> vptr(new GraphVertex<T>(value, name));
        verticies_names_.push_back(name);
        verticies_ptrs_.push_back(vptr);
    }
    void addVertex(T &value, const std::string &name)
    {
        if (hasVertex(name))
        {
            std::cerr << name << " Exists in Graph \n";
            return;
        }
        std::shared_ptr<GraphVertex<T>> vptr(new GraphVertex<T>(value, name));
        verticies_names_.push_back(name);
        verticies_ptrs_.push_back(vptr);
    }
    void addVertex(const T &value, const std::string &name)
    {
        if (hasVertex(name))
        {
            std::cerr << name << " Exists in Graph \n";
            return;
        }
        std::shared_ptr<GraphVertex<T>> vptr(new GraphVertex<T>(value, name));
        verticies_names_.push_back(name);
        verticies_ptrs_.push_back(vptr);
    }
    std::shared_ptr<GraphVertex<T>> getVertex(std::string &vertex_name)
    {
        std::vector<std::string>::iterator i = std::find(verticies_names_.begin(), verticies_names_.end(), vertex_name);
        if (i == verticies_names_.end())
        {
            std::cerr << vertex_name << " Doesn't Exist in Graph";
            return nullptr;
        }
        int index = i - verticies_names_.begin();
        return verticies_ptrs_[index];
    }
    std::shared_ptr<GraphVertex<T>> getVertex(const std::string &vertex_name)
    {
        std::vector<std::string>::iterator i = std::find(verticies_names_.begin(), verticies_names_.end(), vertex_name);
        if (i == verticies_names_.end())
        {
            std::cerr << vertex_name << " Doesn't Exist in Graph\n";
            return nullptr;
        }
        int index = i - verticies_names_.begin();
        return verticies_ptrs_[index];
    }
    void createEdge(std::string &src, std::string &dst, double weight = 1)
    {
        std::shared_ptr<GraphVertex<T>> src_ptr = getVertex(src);
        std::shared_ptr<GraphVertex<T>> dst_ptr = getVertex(dst);
        src_ptr->addEdge(dst_ptr, weight);
        dst_ptr->addInGoingEdge(src_ptr, weight);
    }
    void createEdge(const std::string &src, std::string &dst, double weight = 1)
    {
        std::shared_ptr<GraphVertex<T>> src_ptr = getVertex(src);
        std::shared_ptr<GraphVertex<T>> dst_ptr = getVertex(dst);
        src_ptr->addEdge(dst_ptr, weight);
        dst_ptr->addInGoingEdge(src_ptr, weight);
    }
    void createEdge(std::string &src, const std::string &dst, double weight = 1)
    {
        std::shared_ptr<GraphVertex<T>> src_ptr = getVertex(src);
        std::shared_ptr<GraphVertex<T>> dst_ptr = getVertex(dst);
        src_ptr->addEdge(dst_ptr, weight);
        dst_ptr->addInGoingEdge(src_ptr, weight);
    }
    void createEdge(const std::string &src, const std::string &dst, double weight = 1)
    {
        std::shared_ptr<GraphVertex<T>> src_ptr = getVertex(src);
        std::shared_ptr<GraphVertex<T>> dst_ptr = getVertex(dst);
        src_ptr->addEdge(dst_ptr, weight);
        dst_ptr->addInGoingEdge(src_ptr, weight);
    }
    void removeEdge(std::string &src, std::string &dst)
    {
        std::shared_ptr<GraphVertex<T>> src_ptr = getVertex(src);
        std::shared_ptr<GraphVertex<T>> dst_ptr = getVertex(dst);
        src_ptr->removeEdge(dst_ptr);
        dst_ptr->removeInGoingEdge(src_ptr);
    }
    void removeEdge(const std::string &src, std::string &dst)
    {
        std::shared_ptr<GraphVertex<T>> src_ptr = getVertex(src);
        std::shared_ptr<GraphVertex<T>> dst_ptr = getVertex(dst);
        src_ptr->removeEdge(dst_ptr);
        dst_ptr->removeInGoingEdge(src_ptr);
    }
    void removeEdge(std::string &src, const std::string &dst)
    {
        std::shared_ptr<GraphVertex<T>> src_ptr = getVertex(src);
        std::shared_ptr<GraphVertex<T>> dst_ptr = getVertex(dst);
        src_ptr->removeEdge(dst_ptr);
        dst_ptr->removeInGoingEdge(src_ptr);
    }
    void removeEdge(const std::string &src, const std::string &dst)
    {
        std::shared_ptr<GraphVertex<T>> src_ptr = getVertex(src);
        std::shared_ptr<GraphVertex<T>> dst_ptr = getVertex(dst);
        src_ptr->removeEdge(dst_ptr);
        dst_ptr->removeInGoingEdge(src_ptr);
    }
    void removeVertex(std::string &name)
    {
        std::vector<std::string>::iterator i = std::find(verticies_names_.begin(), verticies_names_.end(), name);
        if (i == verticies_names_.end())
        {
            std::cerr << name << "Isn't a Vertex in the graph\n";
            return;
        }

        std::shared_ptr<GraphVertex<T>> vptr = getVertex(name);
        std::vector<std::string> outgoing_names = vptr->getOutEdgesNames();
        for (int i = 0; i < outgoing_names.size(); i++)
        {
            this->removeEdge(name, outgoing_names[i]);
        }

        verticies_names_.erase(i);
        int index = i - verticies_names_.begin();
        typename std::vector<std::shared_ptr<GraphVertex<T>>>::iterator vertex_iterator = verticies_ptrs_.begin() + index;
        verticies_ptrs_.erase(vertex_iterator);
    }
    friend std::ostream &operator<<(std::ostream &os, const DirectedGraph<T> &G)
    {
        os << "Printing Graph:\n";
        for (int i = 0; i < G.verticies_ptrs_.size(); i++)
        {
            os << (*G.verticies_ptrs_[i]);
        }
        return os;
    }
    void printInGoingEdgesInGraph()
    {
        std::cout << "Printing In Edges of Graph:\n";
        for (int i = 0; i < verticies_ptrs_.size(); i++)
        {
            (*verticies_ptrs_[i]).printInGoingEdges();
        }
    }
    std::vector<std::string> TopologicalSort()
    {

        // Reminder This will Only work if the graph is a DAG
        std::cout << "Topological Sort:\n";
        std::vector<std::string> topo_sort = std::vector<std::string>();
        int count = 0;
        DirectedGraph<T> copied_graph = DirectedGraph<T>(*this);
        while (copied_graph.verticies_ptrs_.size() > 0)
        {
            int index = copied_graph.findSourceIndex();
            if (index < 0)
                return std::vector<std::string>();
            topo_sort.push_back(copied_graph.verticies_names_[index]);
            copied_graph.removeVertex(copied_graph.verticies_names_[index]);
        }
        return topo_sort;
    }
    void printTopologicolSort()
    {
        std::vector<std::string> topo_sort = this->TopologicalSort();
        std::cout << "[";
        for (int i = 0; i < topo_sort.size() - 1; i++)
        {
            std::cout << topo_sort[i] << ", ";
        }
        std::cout << topo_sort[topo_sort.size() - 1] << " ]\n";
    }
};
#endif