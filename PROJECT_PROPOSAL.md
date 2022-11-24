# Project Proposal 

## Leading Question 

As travel resumes in a world that is moving out of a pandemic, people are ever more conscious of the time they spend on all non-productive activities. Commute is one such activity. In order to allow people to focus on that which is most important w.r.t their purpose of travel, we aim to build a general search tool that allows people to easily minimize time spent on getting to and from their destinations. Using the dataset for OpenFlights, we will use a Shortest Path Algorithm for finding the shortest distances between two airports. Additionally, as a discovery tool, we will also allow users to find the most popular transit hubs servucig their end destinations.

## Dataset Acquisition and Data Format

We plan to primarily use OpenFlights' airport and flight routes datasets. All files in these dataset arre binary files in .dat format. This dataset will allow us to build a graph with airports as nodes and the distances between them as edges, where the existence of an edge is determined by whether there is a flight between any two given nodes (airports). Additionally, part of our team has applied for access to some publicly available APIs that all developers can obtain access to through simple registration and approval, such as the APIs offered by FlightStats, which offer data on connecting flights, flight schedules, etc. Provided our request to access these open APIs is approved, we will gain the ability weight our edges based not only on distance, but also based on average time taken to fly between the two airports in question, etc. However, this implementation of this additional functionality is entirely dependent on whether our request to access these APIs as student developers is approved.

## Data Correction

We fully expect the dataset to have problems, including but not limited to null values, non-standardized values, etc. As part of the pre-processing stage, we plan to standardize all numerical data and replace all null data with predetermined values. Furthermore, we also plan to include range checks for values that we expect to lie within certain ranges, such as the coordinates, i.e. the latitudes/longitudes of airports, flight time, etc.

## Data Storage

We plan on using an Adjacency Matrix to implement our graph – this allows to also easily store information regarding the weight of the edges in our graph regardless of how we choose to represnet said information (we are currently planning on a struct representation of Edge weight information). We plan to represnet said Adjacency Matrix using an array of arrays (where each inner array will be an array of Edge Objects) instead of vectors/other data structures since arrays allow us O(1) lookup time for elements.

We plan to represent nodes as structs, with the said struct containing information on the aiport's name, its coordinates (latitude/longitude), etc.

We plan to represent Edges between nodes using a struct, with said struct holding information about the nodes the edge is between and the wight of the edge, which may be calculated based on multiple factors and be standardized.

## Algorithms
To find the minimum path between two nodes in our graoh, i.e. to find the minimum "distance" between two airports based on factors such as physical distance, flight time, etc., we plan to use Dijkstra's Algorithm. To implement the functionality of finding transit hubs, we plan on using Betweenness Centrality to find the nodal airports, i.e., transit hubs, with the maximum number of edges to them. Our input 2D array, as mentioned earlier in the Data Storage section, shall represnt a graph.

We expect that the output of our distance-and-time minimizer functionality (using the Shortest Path Algorithm), i.e. our implementation of Djikstra's Algorithm, will be either an array/vector/linked-list of Edge objects, depending on how we choose to represent edges (we plan on utilizing a struct representation). The output of our transit-hub-finder functionality (using the Betweenness Centrality) will most likely be either a singular most popular transit hub (therefore, a node object) that services the user's to and fro destinations, or a list of the popular transit hubs (since more than one popular transit hub may service the set of destinations).

## Timeline
Broadly, our current goal is to complete the implementation and rigorous testing of 50% funcionality by the Mid-Project Checkin Deadline. Furthermore, we also plan to complete the implementation and testing of all above-mentioned functions and any additional features to our project by December 3, 2022.