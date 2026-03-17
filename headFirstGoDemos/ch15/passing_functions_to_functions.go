package ch15

import "fmt"

func sayHi() {
	fmt.Println("Hi")
}
func sayBye() {
	fmt.Println("Bye")
}

func twice(theFunction func()) {
	theFunction()
	theFunction()
}

func TestFuncAsParams() {
	twice(sayHi)
	twice(sayBye)
}
