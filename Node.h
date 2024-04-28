#pragma Once

class Node {
    private:
    int data;
    Node* link;
    public:
    Node(int data) : data(data), link(nullptr) {};
    Node() : data(0), link(nullptr) {};
    int getData() { return data;}
    Node* getLink() { return link;}
    void setLink(Node* node) { link = node;}
};