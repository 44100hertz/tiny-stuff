package main

import "fmt"

type hello struct {
	times int
}

func (self hello) print(value interface{}) {
	for i := 0; i < self.times; i++ {
		fmt.Println(value)
	}
}

func main() {
	h := hello{2}
	h.print("cool")
	h.print(11)
}
