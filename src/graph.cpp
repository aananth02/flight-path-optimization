#include "graph.h"

Graph::Graph(bool weighted) : weighted(weighted),directed(false) {
    ;
}

Graph::Graph(bool weighted, bool directed) : weighted(weighted),directed(directed) {
    ;
}

Graph::Graph(Airport_data& ad, Route_data& rd) {
    weighted = true;
    directed = true;
    vector<route> routes = rd.getdata();
    for (size_t i = 0; i < routes.size(); i++) {

        string src = ad.getName(routes[i].source_id);
        string dst = ad.getName(routes[i].dest_id);
        if (!vertexExists(src)) insertVertex(src);
        if (!vertexExists(dst)) insertVertex(dst);
        float dist = distance(ad.getLatitude(routes[i].source_id), ad.getLongitude(routes[i].source_id),
                              ad.getLatitude(routes[i].dest_id), ad.getLongitude(routes[i].dest_id));
        if (!insertEdge(src, dst, dist, routes[i].airline_code)) {
            if (adjacency_matrix[getVertexIdx(dst)][getVertexIdx(src)].first < 0) {
                adjacency_matrix[getVertexIdx(dst)][getVertexIdx(src)].first *= -1;
            } else {
                adjacency_matrix[getVertexIdx(src)][getVertexIdx(dst)].first *= -1;
            }
        }
    }
}

vector<Vertex> Graph::getAdjacentDir(Vertex v, int dir) const {
    int idx = getVertexIdx(v);
    vector<Vertex> to_ret;
    if (idx == -1) return to_ret;
    for (size_t i = 0; i < ver_index.size(); i++) {
        if (dir == 1 && adjacency_matrix[idx][i].first > 0) {
            to_ret.push_back(ver_index[i]);
        } else if (dir == -1 && adjacency_matrix[idx][i].first < 0) {
            to_ret.push_back(ver_index[i]);
        } else if (dir == 0 && adjacency_matrix[idx][i].first != 0) {
            to_ret.push_back(ver_index[i]);
        }
    }
    return to_ret;
}


vector<Vertex> Graph::getVertices() const {
    vector<Vertex> ret;

    for (size_t i = 0; i < ver_index.size(); i++) ret.push_back(ver_index[i]);

    return ret;
}


vector<Edge> Graph::getEdges() const {
    vector<Edge> ret;
    for (size_t i = 0; i < ver_index.size(); i++) {
        for (size_t j = 0; j < ver_index.size(); j++) {
            if (adjacency_matrix[i][j].first > 0) ret.push_back(getEdge(ver_index[i], ver_index[j]));       // only gives positive edges (source->destination)
        }
    }

    return ret;
}

bool Graph::vertexExists(Vertex v) const {
    return (getVertexIdx(v) != -1);
}

bool Graph::edgeExists(Vertex source, Vertex destination) const {
    return adjacency_matrix[getVertexIdx(source)][getVertexIdx(destination)].first;
}

void Graph::setEdgeLabel(Vertex source, Vertex destination, string label) {
    adjacency_matrix[getVertexIdx(source)][getVertexIdx(destination)].second = label;
}


string Graph::getEdgeLabel(Vertex source, Vertex destination) const {
    return adjacency_matrix[getVertexIdx(source)][getVertexIdx(destination)].second;
}

float Graph::getEdgeWeight(Vertex source, Vertex destination) const {
    return adjacency_matrix[getVertexIdx(source)][getVertexIdx(destination)].first;
}

void Graph::insertVertex(Vertex v) {

    empty_edges.push_back(pair<float, string>(0, ""));
    ver_index.push_back(v);

    adjacency_matrix.push_back(empty_edges);

    for (size_t i = 0; i < adjacency_matrix.size() - 1; i++) {
        adjacency_matrix[i].push_back(pair<float, string>(0, ""));       // 0 for no edge
    }
}

int Graph::getVertexIdx(Vertex x) const {
    for (int i = 0; i < int(ver_index.size()); i++) {
        if (ver_index[i] == x) return i;
    }
    return -1;
}

Vertex Graph::removeVertex(Vertex v) {
    if (find(ver_index.begin(), ver_index.end(), v) == ver_index.end()) return Vertex();
    adjacency_matrix.erase(adjacency_matrix.begin() + getVertexIdx(v));
    for (size_t i = 0; i < adjacency_matrix.size(); i++) {
        adjacency_matrix[i].erase(adjacency_matrix[i].begin() + getVertexIdx(v));
    }

    empty_edges.erase(empty_edges.begin() + getVertexIdx(v));
    ver_index.erase(ver_index.begin() + getVertexIdx(v));
    return v;
}

bool Graph::insertEdge(Vertex source, Vertex destination, float weight, string label) {
    if (adjacency_matrix[getVertexIdx(source)][getVertexIdx(destination)].first != 0) {
        return false;
    }

    adjacency_matrix[getVertexIdx(source)][getVertexIdx(destination)] = pair<float, string>(weight, label);
    if (directed) adjacency_matrix[getVertexIdx(destination)][getVertexIdx(source)] = pair<float, string>(weight * -1, label);

    return true;
}

Edge Graph::getEdge(Vertex source, Vertex destination) const {
    if (adjacency_matrix[getVertexIdx(source)][getVertexIdx(destination)].first == 0) return Edge();
    return Edge(source, destination, 
        adjacency_matrix[getVertexIdx(source)][getVertexIdx(destination)].first, 
        adjacency_matrix[getVertexIdx(source)][getVertexIdx(destination)].second);
}

Edge Graph::removeEdge(Vertex source, Vertex destination) {
    if (adjacency_matrix[getVertexIdx(source)][getVertexIdx(destination)].first == 0) return Edge();

    pair<float, string> e = adjacency_matrix[getVertexIdx(source)][getVertexIdx(destination)];
    adjacency_matrix[getVertexIdx(source)][getVertexIdx(destination)] = pair<float, string>(0, "");
    adjacency_matrix[getVertexIdx(destination)][getVertexIdx(source)] = pair<float, string>(0, "");
    return Edge(source, destination, e.first, e.second);
}


bool Graph::isDirected() const {
    return directed;
}

void Graph::clear() {
    adjacency_matrix.clear();
    ver_index.clear();
    empty_edges.clear();
}
