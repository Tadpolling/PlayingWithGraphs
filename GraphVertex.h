#ifndef GRAPH_VERTEX_H
#define GRAPH_VERTEX_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory>

// template <class T>
// std::ostream &operator<<(std::ostream &os, const GraphVertex<T> &vertex);
template <class T>

class GraphVertex
{
    typedef std::shared_ptr<GraphVertex<T>> EdgePtr;

private:
    T value_;
    std::string vertex_name_;
    std::vector<EdgePtr> outgoing_edges_;
    std::vector<std::string> names_;
    std::vector<double> weights_;
    std::vector<EdgePtr> ingoing_edges_;
    std::vector<std::string> ingoing_edges_names_;
    std::vector<double> ingoing_weights_;
    // std::shared_ptr<Node<Edge<T>>> outgoing_edges;

public:
    GraphVertex(T &value, std::string &name)
    {
        value_ = value;
        vertex_name_ = name;
        outgoing_edges_ = std::vector<EdgePtr>();
        names_ = std::vector<std::string>();
        weights_ = std::vector<double>();
        ingoing_edges_ = std::vector<EdgePtr>();
        ingoing_edges_names_ = std::vector<std::string>();
        ingoing_weights_ = std::vector<double>();
    }
    GraphVertex(T &value, const std::string &name)
    {
        value_ = value;
        vertex_name_ = name;
        outgoing_edges_ = std::vector<EdgePtr>();
        names_ = std::vector<std::string>();
        weights_ = std::vector<double>();
        ingoing_edges_ = std::vector<EdgePtr>();
        ingoing_edges_names_ = std::vector<std::string>();
        ingoing_weights_ = std::vector<double>();
    }
    GraphVertex(const T &value, std::string &name)
    {
        value_ = value;
        vertex_name_ = name;
        outgoing_edges_ = std::vector<EdgePtr>();
        names_ = std::vector<std::string>();
        weights_ = std::vector<double>();
        ingoing_edges_ = std::vector<EdgePtr>();
        ingoing_edges_names_ = std::vector<std::string>();
        ingoing_weights_ = std::vector<double>();
    }
    GraphVertex(const T &value, const std::string &name)
    {
        value_ = value;
        vertex_name_ = name;
        outgoing_edges_ = std::vector<EdgePtr>();
        names_ = std::vector<std::string>();
        weights_ = std::vector<double>();
        ingoing_edges_ = std::vector<EdgePtr>();
        ingoing_edges_names_ = std::vector<std::string>();
        ingoing_weights_ = std::vector<double>();
    }
    T &getValue()
    {
        return value_;
    }
    std::string &getName()
    {
        return vertex_name_;
    }
    void addEdge(std::shared_ptr<GraphVertex<T>> vptr, double weight)
    {
        if (this->hasEdge((*vptr).getName()))
        {
            std::cerr << vptr->getName() << " Exists in Vertex" << this->getName();
            return;
        }

        outgoing_edges_.push_back(vptr);
        names_.push_back((*vptr).getName());
        weights_.push_back(weight);
    }
    bool hasEdge(std::string &other_name)
    {
        if (std::find(names_.begin(), names_.end(), other_name) != names_.end())
        {
            return true;
        }
        return false;
    }
    void removeEdge(std::shared_ptr<GraphVertex<T>> vptr)
    {
        std::vector<std::string>::iterator i = std::find(names_.begin(), names_.end(), (*vptr).getName());
        if (i == names_.end())
        {
            std::cerr << vptr->getName() << " Doesn't Exist in Vertex" << this->getName();
            return;
        }
        int index = i - names_.begin();

        names_.erase(i);
        std::vector<double>::iterator weights_index = weights_.begin() + index;
        weights_.erase(weights_index);
        typename std::vector<EdgePtr>::iterator edges_index = outgoing_edges_.begin() + index;
        outgoing_edges_.erase(edges_index);
    }
    bool hasInGoingEdge(std::string &other_name)
    {
        if (std::find(ingoing_edges_names_.begin(), ingoing_edges_names_.end(), other_name) != ingoing_edges_names_.end())
        {
            return true;
        }
        return false;
    }
    void addInGoingEdge(std::shared_ptr<GraphVertex<T>> vptr, double weight)
    {
        if (this->hasInGoingEdge((*vptr).getName()))
        {
            std::cerr << vptr->getName() << " is an Ingoing Vertex Already" << this->getName();
            return;
        }

        ingoing_edges_.push_back(vptr);
        ingoing_edges_names_.push_back((*vptr).getName());
        ingoing_weights_.push_back(weight);
    }
    void removeInGoingEdge(EdgePtr vptr)
    {
        std::vector<std::string>::iterator i = std::find(ingoing_edges_names_.begin(), ingoing_edges_names_.end(), (*vptr).getName());
        if (i == ingoing_edges_names_.end())
        {
            std::cerr << vptr->getName() << " is not an ingoing vertex in" << this->getName();
            return;
        }
        int index = i - ingoing_edges_names_.begin();

        ingoing_edges_names_.erase(i);
        std::vector<double>::iterator weights_index = ingoing_weights_.begin() + index;
        ingoing_weights_.erase(weights_index);
        typename std::vector<EdgePtr>::iterator edges_index = ingoing_edges_.begin() + index;
        ingoing_edges_.erase(edges_index);
    }
    int getInDegree()
    {
        return ingoing_edges_.size();
    }
    int getOutDegree()
    {
        return outgoing_edges_.size();
    }
    std::vector<EdgePtr> &getInEdges()
    {
        return ingoing_edges_;
    }
    std::vector<EdgePtr> &getOutEdges()
    {
        return outgoing_edges_;
    }
    std::vector<double> &getInWeights()
    {
        return ingoing_weights_;
    }
    std::vector<double> &getOutWeights()
    {
        return weights_;
    }
    std::vector<std::string> &getOutEdgesNames()
    {
        return names_;
    }
    friend std::ostream &operator<<(std::ostream &os, const GraphVertex<T> &vertex)
    {

        os << vertex.vertex_name_ << "," << vertex.value_ << ": [ ";
        int num_of_edges = vertex.outgoing_edges_.size();
        if (num_of_edges == 0)
        {
            os << "]\n";
            return os;
        }
        for (int i = 0; i < num_of_edges - 1; i++)
        {
            os << "(" << vertex.weights_[i] << "," << vertex.outgoing_edges_[i]->vertex_name_ << ") , ";
        }
        os << "(" << vertex.weights_[num_of_edges - 1] << ", " << vertex.outgoing_edges_[num_of_edges - 1]->vertex_name_ << ") ]\n";
        return os;
    }
    void printInGoingEdges()
    {

        std::cout << vertex_name_ << "," << value_ << ": [ ";
        int num_of_edges = ingoing_edges_.size();
        if (num_of_edges == 0)
        {
            std::cout << "]\n";
            return;
        }
        for (int i = 0; i < num_of_edges - 1; i++)
        {
            std::cout << "(" << ingoing_weights_[i] << "," << ingoing_edges_[i]->vertex_name_ << ") , ";
        }
        std::cout << "(" << ingoing_weights_[num_of_edges - 1] << ", " << ingoing_edges_[num_of_edges - 1]->vertex_name_ << ") ]\n";
    }
};

#endif