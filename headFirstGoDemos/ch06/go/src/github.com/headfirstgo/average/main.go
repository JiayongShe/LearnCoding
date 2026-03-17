// average calculates the average of several numbers.
package ch06

import (
	"fmt"
	"headFirstGoDemos/ch06/go/src/github.com/headfirstgo/datafile"
	"log"
)

func Average() {
	numbers, err := datafile.GetFloats("ch06/go/bin/data.txt")
	if err != nil {
		log.Fatal(err)
	}
	var sum float64 = 0
	for _, number := range numbers {
		sum += number
	}
	sampleCount := float64(len(numbers))
	fmt.Printf("Average: %0.2f\n", sum/sampleCount)
}
