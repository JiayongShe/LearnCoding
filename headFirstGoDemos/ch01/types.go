package ch01

import (
	"fmt"
	"reflect"
)

func PrintTypes() {
	fmt.Println(reflect.TypeOf(42))
	fmt.Println(reflect.TypeOf(3.1415))
	fmt.Println(reflect.TypeOf(true))
	fmt.Println(reflect.TypeOf("Hello, Go!"))
	fmt.Println()
}
