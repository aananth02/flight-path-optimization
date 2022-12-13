# Final Report

Our project recognises post-pandemic changes in human behaviors towards non-productive uses of time, such as commute time – and as the world began to move away from a pandemic-fueled, work-from-home era, we wanted to help people reduce the amount of time spent traveling for business trips, conferences, work, vacations etc. so that most of our user’s time can be directed at performing that activity instead of getting to the physical location where said activity needs to be performed. To this end, we made the key assumption that distance positively correlates with time and cost, and we used the OpenFlights dataset and implemented certain graph algorithms that help people minimize time spent traveling by minimizing distance (using Floyd-Warshall’s Algorithm), a tool to find to transit hubs (using the Betweenness Centrality Algorithm), and a backpacker’s tool to find the next cheapest destination (in terms of distance) to head to (using Kruskal’s algorithm). Additionally, we also traversed our graph implementation using BFS (Breadth-First-Search) as a way of understanding what airports and routes are available for us to show to our users.

# Minimum Spanning Tree w/ Kruskal’s Algorithm

Kruskal’s algorithm is, quite literally, the backpacker’s dream. Imagine not having to sift through what flights are available from your present location to your next as you attempt to satisfy your wanderlust. Kruskal’s algorithm helps us do just that, by building for us the Minimum Spanning Tree, which is essentially a subgraph of our original graph that allows us to reach all nodes at the minimum possible cost. To illustrate this, here’s a sample of airports, the routes between them, and the weights of the edges connecting them (i.e. the distance between the two airports which are connected). 
 
![alt text](https://github.com/aananth02/flight-path-optimization/blob/main/images/PriorityQueueEdges.png)
![alt text](https://github.com/aananth02/flight-path-optimization/blob/main/images/Weighted%20Graph.jpeg)
![alt text](https://github.com/aananth02/flight-path-optimization/blob/main/images/MST%20(Kruskal's).jpeg)
          

The top graph represents our original graph with its weighted, undirected edges, while the graph on the bottom (with the edges highlighted in red) represents our Minimum Spanning Tree. To verify that our implementation of Kruskal’s algorithm indeed did have the intended functionality, we wrote some test cases. Here’s some code testing for the same graph as shown above:

![alt text](https://github.com/aananth02/flight-path-optimization/blob/main/images/Kruskal's%20Test.png)


# Breadth First Search to Explore our Airports (Nodes, we mean)

In addition to implementing the use-case motivated algorithms described above, we also implemented Breadth First Search as a way of traversing our implementation of the graph to understand and explore all nodes in our graph. As an example how BFS ran on a subset of the massive data we had, here’s a quick snapshot:

![alt text](https://github.com/aananth02/flight-path-optimization/blob/main/images/BFS%20Hand%20Drawn.jpg)

The edges are color-coded, with discovery-edges being labeled blue and cross-edges being labeled green. To test for proper BFS functionality, we recreated the same graph as above, ran BFS on it, and checked if all edge labels were correct. Additionally, to ensure more rigorous testing, we also ran BFS on a tree (which is after all, a special graph) and checked for the absence of cross-edges in the same. Below’s a snapshot of the code for the above-mentioned test cases:

![alt text](https://github.com/aananth02/flight-path-optimization/blob/main/images/BFS%20Edge%20Label%20Test%20Case.png)
![alt text](https://github.com/aananth02/flight-path-optimization/blob/main/images/BFS%20ON%20Tree.png)


# Shortest Path between two nodes w/ Floyd-Warshall’s Algorithm

The core of our project was primarily to reduce travel time, and we chose to act based on the assumption that the distance between two places is directly proportional to the time take to travel between them (though this may not necessarily be true in the airline industry, since, someone might have multiple layovers even between two physically close places if there are no flights servicing the two location directly). To achieve this goal of finding the shortest path, we implemented Floyd-Warshall’s algorithm, which returns the shortest path between all possible pairs of nodes. We then implemented a custom function that would accept source and destination as parameters and look for the path between those two nodes from the dataset of best paths built by running Floyd-Warshall’s algorithm. Here’s a set of tests we created with the subset of data we ran to verify that Floyd-Warshall’s Algorithm was working:

![alt_text](https://github.com/aananth02/flight-path-optimization/blob/main/images/Floyd-Warshall%20testing.png)

# Finding Transit Hubs w/ Betweenness Centrality

As mentioned earlier, we believe that finding important transit hubs is extremely important. As a traveler, it might allow you to find other like-minded explorers, and in some cases, traveling through popular travel hubs may sometimes be cheaper than flying directly to your destination! We used Betweenness Centrality to implement this functionality. To test for this, we used our test dataset, i.e. the subset of our master dataset, to find the node of the highest degree. Here’s a snapshot of code implementing the algorithm:

![alt_text](https://github.com/aananth02/flight-path-optimization/blob/main/images/BetweennessCentrality.png)

# Conclusion

As mentioned in the beginning of this report, we set out with a goal to build a set of tools for travelers to optimize for quality of time spent engaging in their primary activity instead of spending time traveling. We worked under the assumption that distance positively correlates with time and cost of travel. Specifically, we wanted travelers to minimize time spent traveling, be able to discover cheap next destinations and explore transit hubs. And through the ideas we came up with, the code we’ve written and the algorithms we’ve implemented – Floyd-Warshall’s Algorithm, Kruskal’s Algorithm, and the Betweenness Centrality Algorithm, in addition to BFS – we believe we’ve lived up to that goal!
