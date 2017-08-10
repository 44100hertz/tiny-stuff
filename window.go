package screen

import "github.com/veandco/go-sdl2/sdl"
import "fmt"

type Element interface {
	Draw(win *Window)
	Focus(win *Window, x, y int32) bool // the mouse has moved here
	Event(win *Window, e sdl.Event)
	Sub() []
}

type Window struct {
	elem   Element
	parent *Window
	sub    []Window
}

func (self Window) Focus(x, y int32) bool {
	for _, child := range self.sub {
		if child.Focus(x, y) {
			fmt.Println("wow")
			return true
		}
	}
	return self.elem.Focus(&self, x, y)
}

func (self Window) Draw() {
	self.elem.Draw(&self)
	for _, child := range self.sub {
		child.elem.Draw(&self)
	}
}

func (self *Window) Add(elem Element) {
	self.sub = append(self.sub, Window{
		elem:   elem,
		parent: self,
	})
}
