#pragma once

#include <string>

using std::string;

typedef string Vertex;

class Edge
{
  public:
    Vertex src;
    Vertex dest;
    string edge_label;
    float weight;

    Edge(Vertex src, Vertex dest)
        : src(src), dest(dest), edge_label(""), weight(-1) {;}


    Edge(Vertex src, Vertex dest, string label)
        : src(src), dest(dest), edge_label(label), weight(-1) {;}


    Edge(Vertex src, Vertex dest, float w, string label)
        : src(src), dest(dest), edge_label(label), weight(w) {;}


    Edge() : src(""), dest(""), edge_label(""), weight(-1) {;}


    bool operator<(const Edge& other) const { return weight < other.weight; };

    bool operator==(Edge& other) const {
        if (this->src != other.src)
            return false;
        if (this->dest != other.dest)
            return false;
        return true;
    };

  private:
    
};
