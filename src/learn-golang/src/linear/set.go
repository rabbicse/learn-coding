package main

import "fmt"

type Set struct {
	intMap map[int]bool
}

func (set *Set) New() {
	set.intMap = make(map[int]bool)
}

func (set *Set) AddElement(element int) {
	if !set.ContainsElement(element) {
		set.intMap[element] = true
	}
}

func (set *Set) DeleteElement(element int) {
	delete(set.intMap, element)
}

func (set *Set) ContainsElement(element int) bool {
	var exists bool
	_, exists = set.intMap[element]
	return exists
}

func (set *Set) Intersect(anotherSet *Set) *Set {
	var intersectSet = &Set{}
	intersectSet.New()

	for value, _ := range set.intMap {
		if anotherSet.ContainsElement(value) {
			intersectSet.AddElement(value)
		}
	}

	return intersectSet
}

func (set *Set) Union(anotherSet *Set) *Set {
	var unionSet = &Set{}
	unionSet.New()
	for value, _ := range set.intMap {
		unionSet.AddElement(value)
	}

	for value, _ := range anotherSet.intMap {
		unionSet.AddElement(value)
	}

	return unionSet
}

func main() {
	var set *Set
	set = &Set{}

	set.New()

	set.AddElement(1)
	set.AddElement(2)

	var anotherSet *Set
	anotherSet = &Set{}

	anotherSet.New()
	anotherSet.AddElement(2)
	anotherSet.AddElement(4)
	anotherSet.AddElement(5)

	fmt.Println("Another set", set)

	fmt.Println("Intersection of sets: ", set.Intersect(anotherSet))

	fmt.Println("Union of sets: ", set.Union(anotherSet))
}
