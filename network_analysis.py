import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt
from datetime import datetime
from collections import defaultdict

class NetworkAnalyzer:
    def __init__(self, database_file):
        self.df = pd.read_csv(database_file)
        self.graph = nx.Graph()
        self._build_network()
    
    def _build_network(self):
        # Add nodes (people) to the network
        # Read through the dataframe we just created in __init__
        for index, row in self.df.iterrows():
            person_id = f"{row['first_name']}_{row['last_name']}"
            self.graph.add_node(person_id, 
                          first_name=row['first_name'],
                          last_name=row['last_name'],
                          birthdate=row['birthdate'],
                          college=row['college'],
                          major=row['major'],
                          state=row['state'])
        
        # Create edges based on common attributes
        for i, row1 in self.df.iterrows():
            for j, row2 in self.df.iterrows():
                if i < j:
                    person1 = f"{row1['first_name']}_{row1['last_name']}"
                    person2 = f"{row2['first_name']}_{row2['last_name']}"
                    
                    # Creating a list of the common attributes between people/nodes
                    common_attributes = []
                    if (row1['college'] == row2['college']):
                        common_attributes.append('college')
                        
                    if (row1['major'] == row2['major']):
                        common_attributes.append('major')

                    if (row1['state'] == row2['state']):
                        common_attributes.append('state')
                    
                    if common_attributes: # If common_attributes is not empty
                        self.graph.add_edge(person1, person2, 
                                      common_attributes=common_attributes)
    
    def analyze_network(self):
        print("\nNetwork Analysis Results:")
        print(f"Number of people in network: {self.graph.number_of_nodes()}")
        print(f"Number of connections: {self.graph.number_of_edges()}")
        
        # Calculate average degree
        avg_degree = sum(dict(self.graph.degree()).values()) / self.graph.number_of_nodes()
        print(f"Average number of connections per person: {avg_degree:.2f}")
        
        # Find most connected people
        degrees = dict(self.graph.degree())
        most_connected = sorted(degrees.items(), key=lambda x: x[1], reverse=True)[:3]
        print("\nMost connected people:")
        for person, degree in most_connected:
            print(f"{person}: {degree} connections")
        
        # Analyze common attributes
        print("\nCommon attributes analysis:")
        attribute_counts = defaultdict(int)
        for _, _, data in self.graph.edges(data=True):
            for attr in data['common_attributes']:
                attribute_counts[attr] += 1
        
        for attr, count in attribute_counts.items():
            print(f"Connections based on {attr}: {count}")
    
    def visualize_network(self):
        plt.figure(figsize=(12, 8))
        pos = nx.spring_layout(self.graph)
        
        # Draw nodes
        nx.draw_networkx_nodes(self.graph, pos, node_color='lightblue', 
                             node_size=1000, alpha=0.6)
        
        # Draw edges
        nx.draw_networkx_edges(self.graph, pos, alpha=0.4)
        
        # Draw labels
        nx.draw_networkx_labels(self.graph, pos, font_size=8)
        
        plt.title("Social Network Visualization")
        plt.axis('off')
        plt.savefig('network_visualization.png')
        plt.close()

def main():
    analyzer = NetworkAnalyzer('network_database.csv')
    analyzer.analyze_network()
    analyzer.visualize_network()
    print()
    print("Network visualization saved as 'network_visualization.png'")

if __name__ == "__main__":
    main() 