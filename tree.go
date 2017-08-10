package main

import "fmt"

type node interface {
	write()
	children() []node
}
type baseNode struct {
	sub []node
}

func (self baseNode) children() []node {
	return self.sub
}

func subwrite(n node) {
	n.write()
	for _, sub := range n.children() {
		subwrite(sub)
	}
}

type identWriter struct {
	baseNode
	name string
}

func (self identWriter) write() {
	fmt.Print(self.name)
}

func main() {
	writer := identWriter{
		name: "Hello, ",
		baseNode: identWriter{sub: []node{
			writer2{
				number:   2,
				baseNode: baseNode{sub: []node{}},
			},
		}},
	}
	subwrite(writer)
}
