import csv
from collections import defaultdict

class SimpleNetwork:
    def __init__(self, database_file):
        self.people = {}  # Dictionary to store people
        self.connections = defaultdict(list)  # Dictionary to store connections
        self.load_database(database_file)
    
    def load_database(self, filename):
        with open(filename, 'r') as file:
            reader = csv.DictReader(file)
            for row in reader:
                # Create a person record
                person_id = f"{row['first_name']}_{row['last_name']}"
                self.people[person_id] = {
                    'first_name': row['first_name'],
                    'last_name': row['last_name'],
                    'college': row['college'],
                    'major': row['major'],
                    'state': row['state']
                }
    
    def find_connections(self):
        # Find connections based on common attributes
        for person1 in self.people:
            for person2 in self.people:
                if person1 < person2:  # Avoid duplicate connections
                    common_attrs = []
                    
                    # Check for common attributes
                    if self.people[person1]['college'] == self.people[person2]['college']:
                        common_attrs.append('college')
                    if self.people[person1]['major'] == self.people[person2]['major']:
                        common_attrs.append('major')
                    if self.people[person1]['state'] == self.people[person2]['state']:
                        common_attrs.append('state')
                    
                    if common_attrs:
                        self.connections[person1].append((person2, common_attrs))
                        self.connections[person2].append((person1, common_attrs))
    
    def analyze_network(self):
        print("\nSimple Network Analysis")
        print(f"Total number of people: {len(self.people)}")
        
        # Count total connections
        total_connections = sum(len(conns) for conns in self.connections.values()) // 2
        print(f"Total number of connections: {total_connections}")
        
        # Find people with most connections
        print("\nPeople with most connections:")
        connection_counts = {person: len(conns) for person, conns in self.connections.items()}
        sorted_people = sorted(connection_counts.items(), key=lambda x: x[1], reverse=True)
        
        for person, count in sorted_people:
            print(f"{person}: {count} connections")
        
        # Analyze common attributes
        print("\nCommon attributes analysis:")
        attribute_counts = defaultdict(int)
        for connections in self.connections.values():
            for _, attrs in connections:
                for attr in attrs:
                    attribute_counts[attr] += 1
        
        for attr, count in attribute_counts.items():
            print(f"Connections based on {attr}: {count}")

def main():
    # Create and analyze the network
    network = SimpleNetwork('network_database.csv')
    network.find_connections()
    network.analyze_network()

if __name__ == "__main__":
    main() 