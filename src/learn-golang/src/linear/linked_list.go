package main

import "fmt"

// Node class
type Node struct {
	data     int
	nextNode *Node
}

//LinkedList class
type LinkedList struct {
	headNode *Node
}

// Add to head method of linked list class
func (linkedList *LinkedList) AddToHead(data int) {
	var node = Node{}
	node.data = data
	node.nextNode = nil

	if linkedList.headNode != nil {
		node.nextNode = linkedList.headNode
	}
	linkedList.headNode = &node
}

// Last Node
func (linkedList *LinkedList) LastNode() *Node {
	var node *Node
	var lastNode *Node
	for node = linkedList.headNode; node != nil; node = node.nextNode {
		if node.nextNode == nil {
			lastNode = node
		}
	}

	return lastNode
}

// Add to End
func (linkedList *LinkedList) AddToEnd(data int) {
	// First create node
	var node = Node{}
	node.data = data
	node.nextNode = nil

	var lastNode *Node
	lastNode = linkedList.LastNode()
	if lastNode != nil {
		lastNode.nextNode = &node
	}
}

// Last Node
func (linkedList *LinkedList) NodeWithValue(data int) *Node {
	var node *Node
	var nodeWith *Node
	for node = linkedList.headNode; node != nil; node = node.nextNode {
		if node.data == data {
			nodeWith = node
			break
		}
	}

	return nodeWith
}

// Add after
func (linkedList *LinkedList) AddAfter(nodeAft int, data int) {
	var node = Node{}
	node.data = data
	node.nextNode = nil

	nodeWith := linkedList.NodeWithValue(nodeAft)
	if nodeWith != nil {
		node.nextNode = nodeWith.nextNode
		nodeWith.nextNode = &node
	}
}

// Iterate method of Linked list
func (linkedList *LinkedList) IterateList() {
	var node *Node
	for node = linkedList.headNode; node != nil; node = node.nextNode {
		fmt.Println(node.data)
	}
}

func main() {
	var linkedList = LinkedList{}
	linkedList.AddToHead(3)
	linkedList.AddToHead(1)
	linkedList.AddToEnd(5)
	linkedList.AddAfter(1, 7)
	linkedList.IterateList()
}
