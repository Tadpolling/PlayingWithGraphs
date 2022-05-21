#ifndef GRAPH_FUNCTION_H
#define GRAPH_FUNCTION_H
#include <string>
#include <vector>
#include <algorithm>
template <class T>

class GraphFunction
{
private:
public:
    std::vector<std::string> verticies_names_;
    std::vector<T> function_outputs_;
    GraphFunction()
    {
        verticies_names_ = std::vector<std::string>();
        function_outputs_ = std::vector<T>();
    }
    GraphFunction(const GraphFunction<T> &other)
    {
        this->verticies_names_ = std::vector<std::string>();
        this->function_outputs_ = std::vector<T>();
        for (int i = 0; i < other.verticies_names_.size(); i++)
        {
            verticies_names_.push_back(other.verticies_names_[i]);
            function_outputs_.push_back(T(other.function_outputs_[i]));
        }
    }
    ~GraphFunction() = default;
    void addValue(std::string &s, T &val)
    {
        // std::vector<std::string>::iterator i=verticies_names_.begin();
        /*if (std::find(verticies_names_.begin(), verticies_names_.end(), s) == verticies_names_.end())
        {
            std::cerr << "Already Gave Value For Vertex " << s << "\n";
            return;
        }
        */
        // std::cout << "Adding " << s << "\n";
        verticies_names_.push_back(s);
        function_outputs_.push_back(val);
    }
    void addValue(const std::string &s, T &val)
    {
        // std::vector<std::string>::iterator i=verticies_names_.begin();
        /* if (std::find(verticies_names_.begin(), verticies_names_.end(), s) == verticies_names_.end())
         {
             std::cerr << "Already Gave Value For Vertex " << s << "\n";
             return;
         }
         */
        // std::cout << "Adding " << s << "\n";
        verticies_names_.push_back(s);
        function_outputs_.push_back(val);
    }
    void addValue(std::string &s, const T &val)
    {
        // std::vector<std::string>::iterator i=verticies_names_.begin();
        /* if (std::find(verticies_names_.begin(), verticies_names_.end(), s) == verticies_names_.end())
         {
             std::cerr << "Already Gave Value For Vertex " << s << "\n";
             return;
         }
         */
        // std::cout << "Adding " << s << "\n";
        verticies_names_.push_back(s);
        function_outputs_.push_back(val);
    }
    void addValue(const std::string &s, const T &val)
    {
        // std::vector<std::string>::iterator i=verticies_names_.begin();
        /*if (std::find(verticies_names_.begin(), verticies_names_.end(), s) == verticies_names_.end())
        {
            std::cerr << "Already Gave Value For Vertex " << s << "\n";
            return;
        }
        */
        // std::cout << "Adding " << s << "\n";
        verticies_names_.push_back(s);
        function_outputs_.push_back(val);
    }
    T getVertexValue(std::string &s) const
    {
        for (int i = 0; i < verticies_names_.size(); i++)
        {
            if (verticies_names_[i] == s)
            {
                return function_outputs_[i];
            }
        }
        throw std::invalid_argument("Received Vertex Name that does not exist in Graph");
    }
    T getVertexValue(const std::string &s) const
    {
        for (int i = 0; i < verticies_names_.size(); i++)
        {
            if (verticies_names_[i] == s)
            {
                return function_outputs_[i];
            }
        }
        throw std::invalid_argument("Received Vertex Name that does not exist in Graph");
    }
    void updateValue(std::string &s, T &newValue)
    {
        for (int i = 0; i < verticies_names_.size(); i++)
        {
            if (verticies_names_[i] == s)
            {
                function_outputs_[i] = newValue;
                return;
            }
        }
        throw std::invalid_argument("Received Vertex Name that does not exist in Graph, therefore cannot update Value\n");
    }
    void updateValue(const std::string &s, T &newValue)
    {
        for (int i = 0; i < verticies_names_.size(); i++)
        {
            if (verticies_names_[i] == s)
            {
                function_outputs_[i] = newValue;
                return;
            }
        }
        throw std::invalid_argument("Received Vertex Name that does not exist in Graph, therefore cannot update Value\n");
    }
    void updateValue(std::string &s, const T &newValue)
    {
        for (int i = 0; i < verticies_names_.size(); i++)
        {
            if (verticies_names_[i] == s)
            {
                function_outputs_[i] = newValue;
                return;
            }
        }
        throw std::invalid_argument("Received Vertex Name that does not exist in Graph, therefore cannot update Value\n");
    }
    void updateValue(const std::string &s, const T &newValue)
    {
        for (int i = 0; i < verticies_names_.size(); i++)
        {
            if (verticies_names_[i] == s)
            {
                function_outputs_[i] = newValue;
                return;
            }
        }
        throw std::invalid_argument("Received Vertex Name that does not exist in Graph, therefore cannot update Value\n");
    }
    friend std::ostream &operator<<(std::ostream &os, const GraphFunction<T> &gf)
    {
        os << "Printing Function With All Outputs:\n";
        for (int i = 0; i < gf.verticies_names_.size(); i++)
        {
            os << gf.verticies_names_[i] << ": " << gf.function_outputs_[i] << "\n";
        }
        return os;
    }
};

#endif