package main

import "fmt"

type DoublyNode struct {
	data         int
	nextNode     *DoublyNode
	previousNode *DoublyNode
}

type DoublyLinkedList struct {
	headNode *DoublyNode
}

func (doublyLinkedList *DoublyLinkedList) AddToHead(data int) {
	node := DoublyNode{}
	node.data = data
	node.nextNode = nil
	node.previousNode = nil

	if doublyLinkedList.headNode != nil {
		node.nextNode = doublyLinkedList.headNode
		doublyLinkedList.headNode.previousNode = &node
	}
	doublyLinkedList.headNode = &node
}

// Add to End
func (linkedList *DoublyLinkedList) AddToEnd(data int) {
	// First create node
	var node = DoublyNode{}
	node.data = data
	node.nextNode = nil

	var lastNode *DoublyNode
	lastNode = linkedList.LastNode()
	if lastNode != nil {
		lastNode.nextNode = &node
	}
}

// Add after
func (linkedList *DoublyLinkedList) AddAfter(nodeAfter int, data int) {
	var node = DoublyNode{}
	node.data = data
	node.nextNode = nil
	node.previousNode = nil

	nodeWith := linkedList.NodeWithValue(nodeAfter)
	if nodeWith != nil {
		node.nextNode = nodeWith.nextNode
		node.previousNode = nodeWith
		nodeWith.nextNode = &node
	}
}

// Last Node
func (linkedList *DoublyLinkedList) LastNode() *DoublyNode {
	var lastNode *DoublyNode
	for node := linkedList.headNode; node != nil; node = node.nextNode {
		if node.nextNode == nil {
			lastNode = node
		}
	}
	return lastNode
}

func (linkedList *DoublyLinkedList) NodeWithValue(data int) *DoublyNode {
	var nodeWith *DoublyNode
	for node := linkedList.headNode; node != nil; node = node.nextNode {
		if node.data == data {
			nodeWith = node
			break
		}
	}
	return nodeWith
}

// Add to End
func (linkedList *DoublyLinkedList) NodeBetweenValues(start int, end int) *DoublyNode {
	var nodeWith *DoublyNode
	// Search node
	for node := linkedList.headNode; node != nil; node = node.nextNode {
		if node.previousNode != nil &&
			node.nextNode != nil &&
			node.previousNode.data == start &&
			node.nextNode.data == end {
			nodeWith = node
			break
		}
	}

	return nodeWith
}

// Iterate method of Linked list
func (linkedList *DoublyLinkedList) IterateDoublyList() {
	for node := linkedList.headNode; node != nil; node = node.nextNode {
		fmt.Println(node.data)
	}
}
func main() {
	doublyLinkedList := DoublyLinkedList{}

	doublyLinkedList.AddToHead(1)
	doublyLinkedList.AddToHead(3)
	doublyLinkedList.AddToEnd(5)
	doublyLinkedList.AddAfter(1, 7)

	doublyLinkedList.IterateDoublyList()

	fmt.Println(doublyLinkedList.headNode.data)

	node := doublyLinkedList.NodeBetweenValues(1, 5)
	fmt.Println(fmt.Sprintf("Node between: %d", node.data))
}
