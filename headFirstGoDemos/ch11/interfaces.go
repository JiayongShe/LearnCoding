package main

import (
	"ch11/go/src/mypkg"
	"fmt"
)

func main() {
	var value mypkg.MyInterface
	value = mypkg.MyType(5)
	value.MethodWithoutParameters()
	value.MethodWithParameter(127.3)
	fmt.Println(value.MethodWithReturnValue())

	if myType, ok := value.(mypkg.MyType); ok {
		fmt.Println("myType", myType)
		myType.MethodNotInInterface()
	}
}
