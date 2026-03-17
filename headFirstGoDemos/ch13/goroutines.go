package ch13

import (
	"fmt"
	"time"
)

func a() {
	for i := 0; i < 50; i++ {
		fmt.Print("a")
	}
	fmt.Print("AEnd")
}

func b() {
	for i := 0; i < 50; i++ {
		fmt.Print("b")
	}
	fmt.Print("BEnd")
}

func TestGoroutines() {
	go a()
	go b()
	for i := 0; i < 50; i++ {
		fmt.Print("m")
	}
	fmt.Print("MEnd")
	time.Sleep(time.Second)
	fmt.Println()
	fmt.Println("end main()")
}
