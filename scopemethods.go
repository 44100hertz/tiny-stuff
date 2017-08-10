package main

import "fmt"

func dothing(i *int32) {
	arf := func(self *int32) {
		*self++
	}
	i.arf()
}

func main() {
	x := i32(8)
	dothing(&x)
	fmt.Println(x)
}
