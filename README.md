# Flight Path Optimization

### CS 225 Final Project:
#### Siddarth Aananth, Vinit Gupta, Divyansh Jain, Akash Arunabharathi

# Team Contract

## Communication
1. **Team Meetings** 


Our team will meet twice in a week. One would be a flexible date based on all our availabilites and the second time we meet would be on Saturday from 3:30pm - 5:30pm. We will be meeting in-person at the grainger library. We will be taking notes and writing to-do's on our individual devices.

2. **Assistance** 

We have shared our numbers with each other and our source of communication would be Whatsapp. Everyone is expected to respond as soon as possible (within 3-4hours).

3. **Respect** 

We will ensure that every member stays respectful with each other by promoting open communication. We discussed that we will talk about every issue as soon as it comes up and would keep our minds open to various ideas and proposals.

## Collaboration

4. **Work Distribution** 

We will be assigning workload equally based on each individual's strenghts. We have talked about the areas we all are comfortable with and the areas we arent. We planned that two people can work on one subfunction and to maximise learning we decided that from those two people one would be a person who feels confident with that domain and the other member would be not as confident. This is so that we all can go out of our comfort zones and learn new things. We will address unexpected complications/ unforeseen work together as a group. We will work together to get through any complcation that arises. We also promote asking for help so our group members can feel comfortable asking any help they need. Along with that we will be using online learning resources to learn things none of us have experience in.


5. **Time Commitment** 

Around 5-8 hours of work per week is expected of each group member. There arent any prior time commitments that need to be accounted for. We will address new conflicts and committments by being understanding of the other persons conflicts and will try to distribute work when something inevitably occurs.

6. **Conflict Resolution** 

Our team's core value is communication. Whenever any conflict will come up or any team member does not do their work properly, we will talk about it with that team member and try to understand what happeneded and why it happened. We will collectively work on how to fix it. Aftet 2-3 reminders if the situation still stays the same, we will inform the course staff.

## Signatures
Divyansh Jain, Vinit Gupta, Akash Arunabharathi, Siddarth Aananth



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
